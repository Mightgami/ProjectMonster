// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PMPlayerState.h"
#include "AbilitySystem/PMAbilitySystemComponent.h"
#include "AbilitySystem/PMAttributeSet.h"
#include "Character/PMCharacter.h"

APMPlayerState::APMPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UPMAbilitySystemComponent>("AbilitySystemComponent");
	AttributeSet = CreateDefaultSubobject<UPMAttributeSet>("AttributeSet");
	PartyOrderTags.SetNum(3);

	CurrentMemberIndex = 0;

}

UAbilitySystemComponent* APMPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void APMPlayerState::SaveCurrentAttributes()
{
	if (!AbilitySystemComponent) return;

	if (!PartyOrderTags.IsValidIndex(CurrentMemberIndex)) return;

	FGameplayTag CurrentTag = PartyOrderTags[CurrentMemberIndex];

	if (!AttributeSet) return;

	FPartyMemberAttributes& Attr = PartyMembersAttributesMap.FindOrAdd(CurrentTag);
	UPMAttributeSet* PMAttributeSet = CastChecked<UPMAttributeSet>(AttributeSet);
	Attr.Strength = PMAttributeSet->GetStrength();
	Attr.Dexterity = PMAttributeSet->GetDexterity();
	Attr.Constitution = PMAttributeSet->GetConstitution();
	Attr.Intelligence = PMAttributeSet->GetIntelligence();
	Attr.Wisdom = PMAttributeSet->GetWisdom();
	Attr.Charisma = PMAttributeSet->GetCharisma();
	Attr.Health = PMAttributeSet->GetHealth();
	Attr.MaxHealth = PMAttributeSet->GetMaxHealth();
}

void APMPlayerState::LoadAttributesForTag(const FGameplayTag& MemberTag)
{
	if (!PartyMembersAttributesMap.Contains(MemberTag)) return;

	const FPartyMemberAttributes& Attr = PartyMembersAttributesMap[MemberTag];
	ApplySetAttributesGE(Attr);

}

void APMPlayerState::ApplySetAttributesGE(const FPartyMemberAttributes& Attr) const
{
	if (!AbilitySystemComponent || !SetAttributesGEClass) return;

	FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
	EffectContext.AddSourceObject(this);

	FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(SetAttributesGEClass, 1.f, EffectContext);

	if (SpecHandle.IsValid())
	{
		FGameplayEffectSpec* Spec = SpecHandle.Data.Get();

		Spec->SetSetByCallerMagnitude(FGameplayTag::RequestGameplayTag(FName("SetAttributes.Strength")), Attr.Strength);
		Spec->SetSetByCallerMagnitude(FGameplayTag::RequestGameplayTag(FName("SetAttributes.Dexterity")), Attr.Dexterity);
		Spec->SetSetByCallerMagnitude(FGameplayTag::RequestGameplayTag(FName("SetAttributes.Constitution")), Attr.Constitution);
		Spec->SetSetByCallerMagnitude(FGameplayTag::RequestGameplayTag(FName("SetAttributes.Intelligence")), Attr.Intelligence);
		Spec->SetSetByCallerMagnitude(FGameplayTag::RequestGameplayTag(FName("SetAttributes.Wisdom")), Attr.Wisdom);
		Spec->SetSetByCallerMagnitude(FGameplayTag::RequestGameplayTag(FName("SetAttributes.Charisma")), Attr.Charisma);
		Spec->SetSetByCallerMagnitude(FGameplayTag::RequestGameplayTag(FName("SetAttributes.Health")), Attr.Health);
		Spec->SetSetByCallerMagnitude(FGameplayTag::RequestGameplayTag(FName("SetAttributes.MaxHealth")), Attr.MaxHealth);
		
		AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*Spec);
	}

}

void APMPlayerState::ClearActiveTags()
{
	if (!AbilitySystemComponent) return;
	if (!PartyOrderTags.IsValidIndex(CurrentMemberIndex)) return;

	FGameplayTag CurrentTag = PartyOrderTags[CurrentMemberIndex];

	AbilitySystemComponent->RemoveLooseGameplayTag(CurrentTag);
	AbilitySystemComponent->RemoveLooseGameplayTag(FGameplayTag::RequestGameplayTag(FName("Character.Active")));

}

void APMPlayerState::AddActiveTags(const FGameplayTag& MemberTag) const
{
	if (!AbilitySystemComponent) return;

	AbilitySystemComponent->AddLooseGameplayTag(MemberTag);
	AbilitySystemComponent->AddLooseGameplayTag(FGameplayTag::RequestGameplayTag(FName("Character.Active")));
}

void APMPlayerState::NotifyCharacterSwitch(const FGameplayTag& MemberTag)
{
	APlayerController* PC = Cast<APlayerController>(GetOwner());

	if (!PC) return;

	APMCharacter* Char = Cast<APMCharacter>(PC->GetCharacter());
	if (!Char) return;
	
	if (PaperZDAnimInstanceMap.Contains(MemberTag))
		OnSwitchCharacter.Broadcast(PaperZDAnimInstanceMap[MemberTag]);
	
}


void APMPlayerState::SwitchToPartyMember(int32 NewIndex)
{
	if (NewIndex < 0 || NewIndex >= PartyOrderTags.Num() || NewIndex == CurrentMemberIndex)
        return;

    SaveCurrentAttributes();

    ClearActiveTags();

    CurrentMemberIndex = NewIndex;

    FGameplayTag NewMemberTag = PartyOrderTags[CurrentMemberIndex];

    AddActiveTags(NewMemberTag);

    LoadAttributesForTag(NewMemberTag);

    NotifyCharacterSwitch(NewMemberTag);

}

void APMPlayerState::BeginPlay()
{
	Super::BeginPlay();
	if (PartyOrderTags.Num() > 0)
	{
		// Carica il primo personaggio attivo
		LoadAttributesForTag(PartyOrderTags[CurrentMemberIndex]);
		AddActiveTags(PartyOrderTags[CurrentMemberIndex]);
		NotifyCharacterSwitch(PartyOrderTags[CurrentMemberIndex]);
	}


}

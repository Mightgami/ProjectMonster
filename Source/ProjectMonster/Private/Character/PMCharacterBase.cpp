// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/PMCharacterBase.h"

#include "AbilitySystem/PMAbilitySystemComponent.h"

APMCharacterBase::APMCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

UAbilitySystemComponent* APMCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void APMCharacterBase::AddCharacterAbilities()
{
	UPMAbilitySystemComponent* PMASC = CastChecked<UPMAbilitySystemComponent>(AbilitySystemComponent);
	if (!HasAuthority()) return;
	PMASC->AddCharacterAbilities(StartupAbilities);
}

void APMCharacterBase::InitAbilityActorInfo()
{
}

void APMCharacterBase::ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, float Level) const
{
	check(IsValid(GetAbilitySystemComponent()));
	check(DefaultPrimaryAttributes);
	check(GameplayEffectClass);
	FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	ContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(GameplayEffectClass, Level, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
}

void APMCharacterBase::InitializeDefaultAttributes() const
{
	ApplyEffectToSelf(DefaultPrimaryAttributes, 1.f);
	ApplyEffectToSelf(DefaultSecondaryAttributes, 1.f);
}


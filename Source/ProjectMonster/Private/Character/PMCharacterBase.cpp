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

void APMCharacterBase::InitializePrimaryAttributes() const
{
	check(IsValid(GetAbilitySystemComponent()));
	check(DefaultPrimaryAttributes);
	const FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(DefaultPrimaryAttributes, 1.f, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
}

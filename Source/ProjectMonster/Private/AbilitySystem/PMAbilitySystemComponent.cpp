// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/PMAbilitySystemComponent.h"

void UPMAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UPMAbilitySystemComponent::EffectApplied);
}

void UPMAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
												const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);
	for (const FGameplayTag& Tag : TagContainer)
	{
		EffectAssetTags.Broadcast(TagContainer);
	}
}


void UPMAbilitySystemComponent::AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& StartupAbilities)
{
	for (TSubclassOf<UGameplayAbility> AbilityClass : StartupAbilities)
	{
		const FGameplayAbilitySpec	AbilitySpec=FGameplayAbilitySpec(AbilityClass,1);
		GiveAbility(AbilitySpec);
	}
}

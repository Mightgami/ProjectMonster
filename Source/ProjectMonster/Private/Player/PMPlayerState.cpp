// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PMPlayerState.h"

#include "AbilitySystem/PMAbilitySystemComponent.h"
#include "AbilitySystem/PMAttributeSet.h"

APMPlayerState::APMPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UPMAbilitySystemComponent>("AbilitySystemComponent");
	AttributeSet = CreateDefaultSubobject<UPMAttributeSet>("AttributeSet");
}

UAbilitySystemComponent* APMPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

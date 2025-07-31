// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/PMCharacterBase.h"

APMCharacterBase::APMCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

UAbilitySystemComponent* APMCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

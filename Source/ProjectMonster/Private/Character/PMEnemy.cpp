// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/PMEnemy.h"
#include "AbilitySystem/PMAbilitySystemComponent.h"
#include "AbilitySystem/PMAttributeSet.h"

APMEnemy::APMEnemy()
{
	AbilitySystemComponent = CreateDefaultSubobject<UPMAbilitySystemComponent>("AbilitySystemComponent");
	AttributeSet = CreateDefaultSubobject<UPMAttributeSet>("AttributeSet");
}

void APMEnemy::BeginPlay()
{
	Super::BeginPlay();
	InitAbilityActorInfo();
	
}

void APMEnemy::InitAbilityActorInfo()
{
	Cast<UPMAbilitySystemComponent>(AbilitySystemComponent)->InitAbilityActorInfo(this, this);
}

int32 APMEnemy::GetPlayerLevel()
{
	return Level;
}

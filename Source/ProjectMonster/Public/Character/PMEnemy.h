// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/PMCharacterBase.h"
#include "PMEnemy.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTMONSTER_API APMEnemy : public APMCharacterBase
{
	GENERATED_BODY()
public:
	APMEnemy();

protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;	
};

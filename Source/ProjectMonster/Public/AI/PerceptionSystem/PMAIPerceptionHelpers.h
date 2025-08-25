// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PMAIPerceptionHelpers.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTMONSTER_API UPMAIPerceptionHelpers : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="AI|Perception|Senses|Sight")
	static void GetSightRadius(UAISenseConfig* SenseConfig, UPARAM(DisplayName="Sight Radius") float& OutSightRadius);

	UFUNCTION(BlueprintPure, Category="AI|Perception|Senses|Sight")
	static void GetLoseSightRadius(UAISenseConfig* SenseConfig, UPARAM(DisplayName="Lose Sight Radius") float& OutLoseSightRadius);
};

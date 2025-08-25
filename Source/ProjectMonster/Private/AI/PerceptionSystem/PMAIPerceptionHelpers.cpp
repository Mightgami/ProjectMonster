// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/PerceptionSystem/PMAIPerceptionHelpers.h"
#include "Perception/AISenseConfig_Sight.h"

void UPMAIPerceptionHelpers::GetSightRadius(UAISenseConfig* SenseConfig, float& OutSightRadius)
{
	UAISenseConfig_Sight* SightConfig = Cast<UAISenseConfig_Sight>(SenseConfig);
	check(SightConfig);
	OutSightRadius = SightConfig->SightRadius;
}

void UPMAIPerceptionHelpers::GetLoseSightRadius(UAISenseConfig* SenseConfig, float& OutLoseSightRadius)
{
	UAISenseConfig_Sight* SightConfig = Cast<UAISenseConfig_Sight>(SenseConfig);
	check(SightConfig);
	OutLoseSightRadius = SightConfig->LoseSightRadius;
}

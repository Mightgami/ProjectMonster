#pragma once

#include "CoreMinimal.h"
#include "Perception/AIPerceptionComponent.h"
#include "PMAIPerceptionComponent.generated.h"

class UAISenseConfig;

UCLASS(ClassGroup=(AI), meta=(BlueprintSpawnableComponent))
class PROJECTMONSTER_API UPMAIPerceptionComponent : public UAIPerceptionComponent
{
	GENERATED_BODY()

public:
	// Espone i sense config a Blueprint
	UFUNCTION(BlueprintPure, Category="AI|Perception|Senses")
	void GetAllSenseConfigs(UPARAM(DisplayName="Sense Configs") TArray<UAISenseConfig*>& OutConfigs) const;

	// Restituisce sense config filtrati per tipo
	UFUNCTION(BlueprintCallable, Category="AI|Perception|Senses")
	void GetSenseConfigsByType(TSubclassOf<UAISense> SenseType, UPARAM(DisplayName="Filtered Sense Configs") TArray<UAISenseConfig*>& OutConfigs) const;
};
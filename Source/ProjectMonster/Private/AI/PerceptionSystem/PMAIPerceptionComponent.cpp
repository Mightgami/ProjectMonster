// by Anthony Fedeli

#include "AI/PerceptionSystem/PMAIPerceptionComponent.h"
#include "Perception/AISense.h"
#include "Perception/AISenseConfig.h"


void UPMAIPerceptionComponent::GetAllSenseConfigs(TArray<UAISenseConfig*>& OutConfigs) const
{
	OutConfigs = SensesConfig;
}

void UPMAIPerceptionComponent::GetSenseConfigsByType(TSubclassOf<UAISense> SenseType, TArray<UAISenseConfig*>& OutConfigs) const
{
	TArray<UAISenseConfig*> Result;
	if (!*SenseType) return;

	for (UAISenseConfig* Config : SensesConfig)
	{
		if (Config && Config->GetSenseImplementation() && Config->GetSenseImplementation()->IsChildOf(SenseType))
		{
			Result.Add(Config);
		}
	}
	OutConfigs = Result;
}

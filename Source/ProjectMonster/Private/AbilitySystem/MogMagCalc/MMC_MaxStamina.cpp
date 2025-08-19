// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/MogMagCalc/MMC_MaxStamina.h"
#include "AbilitySystem/PMAttributeSet.h"
#include "Interfaces/CombatInterface.h"


UMMC_MaxStamina::UMMC_MaxStamina()
{

	ConstDef.AttributeToCapture = UPMAttributeSet::GetConstitutionAttribute();
	ConstDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	ConstDef.bSnapshot = false;
	RelevantAttributesToCapture.Add(ConstDef);

	DexDef.AttributeToCapture = UPMAttributeSet::GetConstitutionAttribute();
	DexDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	DexDef.bSnapshot = false;
	RelevantAttributesToCapture.Add(DexDef);

	
}

float UMMC_MaxStamina::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	// Gather tags from source and target
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvaluationParameters;
	EvaluationParameters.SourceTags = SourceTags;
	EvaluationParameters.TargetTags = TargetTags;

	float Const = 0.f;
	GetCapturedAttributeMagnitude(ConstDef, Spec, EvaluationParameters, Const);
	Const = FMath::Max<float>(Const, 0.f);

	float Dex = 0.f;
	GetCapturedAttributeMagnitude(DexDef, Spec, EvaluationParameters, Dex);
	Dex = FMath::Max<float>(Dex, 0.f);

	ICombatInterface* CombatInterface = Cast<ICombatInterface>(Spec.GetContext().GetSourceObject());
	const int32 PlayerLevel = CombatInterface->GetPlayerLevel();

	return 50.f + 1.25f * Const + 1.25f * Dex + 15.f * PlayerLevel;
}

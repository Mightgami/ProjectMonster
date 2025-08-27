// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetControllers/PMAttributeMenuWidgetController.h"
#include "PMGameplayTags.h"
#include "AbilitySystem/PMAttributeSet.h"
#include "AbilitySystem/Data/AttributeInfo.h"


void UPMAttributeMenuWidgetController::BindCallBacksToDependencies()
{
	
	UPMAttributeSet* AS = CastChecked<UPMAttributeSet>(AttributeSet);
	check(AttributeInfo);
	for (auto& Pair : AS->TagsToAttributes)
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Pair.Value()).AddLambda(
		[this, Pair](const FOnAttributeChangeData& Data)
		{
			BroadcastAttributeInfo(Pair.Key, Pair.Value());
		}
	);
	}
}

void UPMAttributeMenuWidgetController::BroadcastInitialValues()
{
	UPMAttributeSet* AS = CastChecked<UPMAttributeSet>(AttributeSet);

	check(AttributeInfo);

	// FPMAttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(FPMGameplayTags::Get().Attributes_Primary_Strength);
	// Info.AttributeValue = AS->GetStrength();
	// AttributeInfoDelegate.Broadcast(Info);
	for (auto& Pair : AS->TagsToAttributes)
	{
		FPMAttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(Pair.Key);
		Info.AttributeValue = Pair.Value().GetNumericValue(AS);
		AttributeInfoDelegate.Broadcast(Info);
	}
	
}

void UPMAttributeMenuWidgetController::BroadcastAttributeInfo(const FGameplayTag& AttributeTag,
	const FGameplayAttribute& Attribute) const
{
	FPMAttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(AttributeTag);
	Info.AttributeValue = Attribute.GetNumericValue(AttributeSet);
	AttributeInfoDelegate.Broadcast(Info);
}

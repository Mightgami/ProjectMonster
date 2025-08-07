// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetControllers/OverlayWidgetController.h"

#include "AbilitySystem/PMAbilitySystemComponent.h"
#include "AbilitySystem/PMAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	UPMAttributeSet* PMAttributeSet = CastChecked<UPMAttributeSet>(AttributeSet);
	OnHealthChanged.Broadcast(PMAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(PMAttributeSet->GetMaxHealth());


	
}

void UOverlayWidgetController::BindCallBacksToDependencies()
{
	UPMAttributeSet* PMAttributeSet = CastChecked<UPMAttributeSet>(AttributeSet);
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		PMAttributeSet->GetHealthAttribute()
		).AddUObject(this,&UOverlayWidgetController::HealthChanged);
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		PMAttributeSet->GetMaxHealthAttribute()
		).AddUObject(this,&UOverlayWidgetController::MaxHealthChanged);

		Cast<UPMAbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddLambda(
		[this](const FGameplayTagContainer& AssetTags)
			{
			for (const FGameplayTag& Tag : AssetTags)
				{
					const FString Msg = FString::Printf(TEXT("GE Tag: %s"), *Tag.ToString());
					GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Blue, Msg);

					FGameplayTag MessageTag = FGameplayTag::RequestGameplayTag(FName("Message"));
					if (Tag.MatchesTag(MessageTag))
					{
						const FUIWidgetRow* Row = GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, Tag);
						MessageWidgetRowDelegate.Broadcast(*Row);
					}
				}
			});
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

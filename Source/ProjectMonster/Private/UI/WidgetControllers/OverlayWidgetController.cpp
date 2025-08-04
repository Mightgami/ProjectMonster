// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetControllers/OverlayWidgetController.h"

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
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

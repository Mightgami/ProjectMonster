// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetControllers/PMWidgetController.h"

void UPMWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

void UPMWidgetController::BroadcastInitialValues()
{

}

void UPMWidgetController::BindCallBacksToDependencies()
{
	
}


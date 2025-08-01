// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/PMHUD.h"
#include "UI/WidgetS/PMUserWidget.h"

void APMHUD::BeginPlay()
{
	Super::BeginPlay();

	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	Widget->AddToViewport();
	
}
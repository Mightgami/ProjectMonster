// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/PMAbilitySystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Player/PMPlayerState.h"
#include "UI/HUD/PMHUD.h"
#include "UI/WidgetControllers/PMWidgetController.h"

UOverlayWidgetController* UPMAbilitySystemLibrary::GetOverlayWidgetController(const UObject* WorldContextObject)
{
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (APMHUD* PMHud = Cast<APMHUD>(PC->GetHUD()))
		{
			APMPlayerState* PS = PC->GetPlayerState<APMPlayerState>();
			UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
			UAttributeSet* AS = PS->GetAttributeSet();
			const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
			return PMHud->GetOverlayWidgetController(WidgetControllerParams);
		}
	}
	return nullptr;
}

UPMAttributeMenuWidgetController* UPMAbilitySystemLibrary::GetAttributeMenuWidgetController(
	const UObject* WorldContextObject)
{
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (APMHUD* PMHud = Cast<APMHUD>(PC->GetHUD()))
		{
			APMPlayerState* PS = PC->GetPlayerState<APMPlayerState>();
			UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
			UAttributeSet* AS = PS->GetAttributeSet();
			const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
			return PMHud->GetAttributeMenuWidgetController(WidgetControllerParams);
		}
	}
	return nullptr;
}

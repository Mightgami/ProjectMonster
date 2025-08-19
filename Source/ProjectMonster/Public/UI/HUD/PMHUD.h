// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PMHUD.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;
class UOverlayWidgetController;
class UPMAttributeMenuWidgetController;
class UPMUserWidget;
struct FWidgetControllerParams;

UCLASS()
class PROJECTMONSTER_API APMHUD : public AHUD
{
	GENERATED_BODY()
public:

	
	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);
	UPMAttributeMenuWidgetController* GetAttributeMenuWidgetController(const FWidgetControllerParams& WCParams);

	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);

private:

	
	UPROPERTY()
	TObjectPtr<UPMUserWidget>  OverlayWidget;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UPMUserWidget> OverlayWidgetClass;
	
	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;

	UPROPERTY()
	TObjectPtr<UPMAttributeMenuWidgetController> AttributeMenuWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UPMAttributeMenuWidgetController> AttributeMenuWidgetControllerClass;
};

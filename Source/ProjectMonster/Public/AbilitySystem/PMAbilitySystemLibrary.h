// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PMAbilitySystemLibrary.generated.h"


class UOverlayWidgetController;
class UPMAttributeMenuWidgetController;

UCLASS()
class PROJECTMONSTER_API UPMAbilitySystemLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category="PMAbilitySystemLibrary|WidgetController")
	static UOverlayWidgetController* GetOverlayWidgetController(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="AuraAbilitySystemLibrary|WidgetController")
	static UPMAttributeMenuWidgetController* GetAttributeMenuWidgetController(const UObject* WorldContextObject);
};

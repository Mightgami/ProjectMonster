// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InputActionValue.h"
#include "PlayerActionsInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class UPlayerActionsInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PROJECTMONSTER_API IPlayerActionsInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
    // Movimento, input vettore 2D
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Input")
    void Move(const FVector2D& MovementVector);

    // Salto
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Input")
    void Jump();

    // Attacco
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Input")
    void Attack();
};

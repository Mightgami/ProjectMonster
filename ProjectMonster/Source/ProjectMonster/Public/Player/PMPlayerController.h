// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"     // Per Enhanced Input
#include "PMPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
/**
 * 
 */
UCLASS()
class PROJECTMONSTER_API APMPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

    virtual void SetupInputComponent() override;

protected:

    // Referenze agli asset di Input Mapping Context e Input Action
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    TObjectPtr <UInputMappingContext> DefaultInputMappingContext;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    TObjectPtr<UInputAction> IA_Move;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    TObjectPtr<UInputAction> IA_Jump;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    TObjectPtr<UInputAction> IA_Attack;

    // Funzioni callback per input
    void Move(const FInputActionValue& Value);
    void Jump(const FInputActionValue& Value);
    void Attack(const FInputActionValue& Value);
};

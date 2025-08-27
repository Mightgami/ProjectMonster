// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameplayTagContainer.h"
#include "InputActionValue.h"     // Per Enhanced Input
#include "PMPlayerController.generated.h"

class UPMAbilitySystemComponent;
class UInputMappingContext;
class UInputAction;
class UPMInputConfig;
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
    
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    TObjectPtr<UInputAction> IA_Switch1;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    TObjectPtr<UInputAction> IA_Switch2;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    TObjectPtr<UInputAction> IA_Switch3;
    // Funzioni callback per input
    void Move(const FInputActionValue& Value);
    void Jump(const FInputActionValue& Value);
    void Attack(const FInputActionValue& Value);
    
    void SwitchToMember1();
    void SwitchToMember2();
    void SwitchToMember3();

    
    void AbilityInputTagPressed(FGameplayTag InputTag);
    void AbilityInputTagReleased(FGameplayTag InputTag);
    void AbilityInputTagHeld(FGameplayTag InputTag);

    UPROPERTY(EditDefaultsOnly, Category="Input")
    TObjectPtr<UPMInputConfig> InputConfig;
    
    UPROPERTY()
    TObjectPtr<UPMAbilitySystemComponent> PMAbilitySystemComponent;

    UPMAbilitySystemComponent* GetASC();
    
    void SwitchToMemberByIndex(int32 Index);
};

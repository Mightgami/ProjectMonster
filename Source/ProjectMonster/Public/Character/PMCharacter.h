// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Interfaces/PlayerActionsInterface.h"
#include "Interfaces/AttackEndInterface.h"
#include "GameFramework/SpringArmComponent.h"
#include "CharacterTypes.h"
#include "PMCharacterBase.h"
#include "PMCharacter.generated.h"

/**
 *
 */
UCLASS()
class PROJECTMONSTER_API APMCharacter : public APMCharacterBase, public IPlayerActionsInterface, public IAttackEndInterface
{
    GENERATED_BODY()

public:
    APMCharacter();
public:

    // Region IPlayerActionsInterface
    virtual void Move_Implementation(const FVector2D& MovementVector) override;
    virtual void Jump_Implementation() override;
    virtual void Attack_Implementation() override;
    // End Region IPlayerActionsInterface
    // RegioIAttackEndInterface
    virtual void EndAttack_Implementation() override;
    // End Regio IAttackEndInterface
    virtual void PossessedBy(AController* NewController) override;
protected:
    /** Spring arm to offset the camera from the character */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
    USpringArmComponent* CameraBoom;

    /** Camera that follows the character */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
    UCameraComponent* FollowCamera;
    // Stato attuale del personaggio
    UPROPERTY(EditAnywhere, Category = "Character State")
    EActionState CurrentState = EActionState::EAS_Unoccupied;


private:
    virtual void InitAbilityActorInfo() override;
};

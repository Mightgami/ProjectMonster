// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/PMCharacter.h"
#include "AbilitySystemComponent.h"
#include "PaperFlipBookComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PaperZDAnimInstance.h"
#include "Player/PMPlayerState.h"

APMCharacter::APMCharacter()
{
 
    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);
    CameraBoom->TargetArmLength = 500.0f;
    CameraBoom->bUsePawnControlRotation = true;
    CameraBoom->SetRelativeRotation(FRotator(-90.0f, 0.0f, 0.0f));
    FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
    FollowCamera->bUsePawnControlRotation = false;
    //FollowCamera->ProjectionMode = ECameraProjectionMode::Orthographic;
    FollowCamera->OrthoWidth = 2048.0f;
    CurrentState = EActionState::EAS_Unoccupied;
}

void APMCharacter::Move_Implementation(const FVector2D& MovementVector)
{
    UE_LOG(LogTemp, Log, TEXT("AMyCharacter: Move triggered"));
    if (CurrentState != EActionState::EAS_Attacking) {
        double value = MovementVector.X;
        AddMovementInput(FVector::ForwardVector, value);

        // Se cambio la direzione aggiorno l'orientamento
        if (value > 0.f)
        {
            GetSprite()->SetRelativeScale3D(FVector(1.f, 1.f, 1.f));
        }
        else if (value < 0.f)
        {
            GetSprite()->SetRelativeScale3D(FVector(-1.f, 1.f, 1.f));
        }
    }
}

void APMCharacter::Jump_Implementation()
{
    UE_LOG(LogTemp, Log, TEXT("AMyCharacter: Jump triggered"));
    if (CurrentState != EActionState::EAS_Attacking) {
        ACharacter::Jump();
    }
}


void APMCharacter::Attack_Implementation()
{
    UE_LOG(LogTemp, Log, TEXT("AMyCharacter: Attack triggered"));
    // Logica attacco
    if (CurrentState != EActionState::EAS_Attacking) {
        if (GetCharacterMovement() && GetCharacterMovement()->IsFalling())
        {
            this->GetAnimInstance()->JumpToNode(FName("JumpAttack"), NAME_None);
            FVector Velocity = GetCharacterMovement()->Velocity;

            // Spinta orizzontale (come prima)
            float Direction = FMath::Sign(Velocity.X);
            if (Direction == 0.f)
                Direction = 1.f;

            float HorizontalBoost = 200.f;
            Velocity.X = Direction * HorizontalBoost;

            // Spinta verticale verso il basso per atterrare prima
            float DownwardBoost = -500.f;  // valore da adattare
            Velocity.Z = DownwardBoost;

            GetCharacterMovement()->Velocity = Velocity;

        }
        else {
            this->GetAnimInstance()->JumpToNode(FName("Attack"), NAME_None);
        }
        CurrentState = EActionState::EAS_Attacking;
    }

}

void APMCharacter::EndAttack_Implementation()
{
    CurrentState = EActionState::EAS_Unoccupied;
}

void APMCharacter::PossessedBy(AController* NewController)
{
    Super::PossessedBy(NewController);

    // Init ability actor info for the Server
    InitAbilityActorInfo();
}

void APMCharacter::InitAbilityActorInfo()
{
    APMPlayerState* PMPlayerState = GetPlayerState<APMPlayerState>();
    check(PMPlayerState);
    PMPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(PMPlayerState, this);
    AbilitySystemComponent = PMPlayerState->GetAbilitySystemComponent();
    AttributeSet = PMPlayerState->GetAttributeSet();
}
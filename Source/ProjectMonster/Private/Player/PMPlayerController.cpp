#include "Player/PMPlayerController.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "Interfaces/PlayerActionsInterface.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "AbilitySystem/PMAbilitySystemComponent.h"
#include "Input/PMInputComponent.h"
#include "Player/PMPlayerState.h"

void APMPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    // Verifica che sia presente EnhancedInputComponent
    if (UPMInputComponent* PMInputComponent = CastChecked<UPMInputComponent>(InputComponent))
    {
        // Ottieni il Local Player Subsystem
        if (ULocalPlayer* LP = GetLocalPlayer())
        {
            if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
            {
                // Aggiungi il mapping context (priorit� 0)
                if (DefaultInputMappingContext)
                {
                    Subsystem->AddMappingContext(DefaultInputMappingContext, 0);
                }
            }
        }
        // Move: tipicamente valore 2D (X,Y)
        if (IA_Move)
        {
            PMInputComponent->BindAction(IA_Move, ETriggerEvent::Triggered, this, &APMPlayerController::Move);
        }

        // Jump: azione binaria (pressed/released)
        if (IA_Jump)
        {
            PMInputComponent->BindAction(IA_Jump, ETriggerEvent::Started, this, &APMPlayerController::Jump);
            // Se vuoi anche fine salto:
            // EnhancedInputComponent->BindAction(IA_Jump, ETriggerEvent::Completed, this, &AMyPlayerController::StopJumping);
        }

        // Attack: azione binaria
        if (IA_Attack)
        {
            PMInputComponent->BindAction(IA_Attack, ETriggerEvent::Started, this, &APMPlayerController::Attack);
        }
        if (IA_Switch1)
        {
            PMInputComponent->BindAction(IA_Switch1,  ETriggerEvent::Started, this, &APMPlayerController::SwitchToMember1);
        }
        if (IA_Switch2)
        {
            PMInputComponent->BindAction(IA_Switch2,  ETriggerEvent::Started, this, &APMPlayerController::SwitchToMember2);
        }
        if (IA_Switch3)
        {
            PMInputComponent->BindAction(IA_Switch3,  ETriggerEvent::Started, this, &APMPlayerController::SwitchToMember3);
        }

        if (InputConfig)
        {
            PMInputComponent->BindAbilityActions(InputConfig, this, &ThisClass::AbilityInputTagPressed, &ThisClass::AbilityInputTagReleased, &ThisClass::AbilityInputTagHeld);
        }
        
    }
}

void APMPlayerController::Move(const FInputActionValue& Value)
{
    FVector2D MoveVector = Value.Get<FVector2D>();

    APawn* ControlledPawn = GetPawn();
    if (ControlledPawn && ControlledPawn->GetClass()->ImplementsInterface(UPlayerActionsInterface::StaticClass()))
    {
        IPlayerActionsInterface::Execute_Move(ControlledPawn, MoveVector);
    }
}

void APMPlayerController::Jump(const FInputActionValue& Value)
{
    APawn* ControlledPawn = GetPawn();
    if (ControlledPawn && ControlledPawn->GetClass()->ImplementsInterface(UPlayerActionsInterface::StaticClass()))
    {
        IPlayerActionsInterface::Execute_Jump(ControlledPawn);
    }
}

void APMPlayerController::Attack(const FInputActionValue& Value)
{
    APawn* ControlledPawn = GetPawn();
    if (ControlledPawn && ControlledPawn->GetClass()->ImplementsInterface(UPlayerActionsInterface::StaticClass()))
    {
        IPlayerActionsInterface::Execute_Attack(ControlledPawn);
    }
}

void APMPlayerController::SwitchToMember1()
{
    SwitchToMemberByIndex(0);

}

void APMPlayerController::SwitchToMember2()
{
    SwitchToMemberByIndex(1);

}

void APMPlayerController::SwitchToMember3()
{
    SwitchToMemberByIndex(2);

}

void APMPlayerController::AbilityInputTagPressed(FGameplayTag InputTag)
{
    GEngine->AddOnScreenDebugMessage(1, 3.f, FColor::Red, *InputTag.ToString());
}

void APMPlayerController::AbilityInputTagReleased(FGameplayTag InputTag)
{
    GEngine->AddOnScreenDebugMessage(2, 3.f, FColor::Blue, *InputTag.ToString());
    if (GetASC() == nullptr) return;
    GetASC()->AbilityInputTagReleased(InputTag);
}

void APMPlayerController::AbilityInputTagHeld(FGameplayTag InputTag)
{
    GEngine->AddOnScreenDebugMessage(3, 3.f, FColor::Green, *InputTag.ToString());
    if (GetASC() == nullptr) return;
    GetASC()->AbilityInputTagHeld(InputTag);
}

UPMAbilitySystemComponent* APMPlayerController::GetASC()
{
    if (PMAbilitySystemComponent == nullptr)
    {
        PMAbilitySystemComponent = Cast<UPMAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetPawn<APawn>()));
    }
    return PMAbilitySystemComponent;
}

void APMPlayerController::SwitchToMemberByIndex(int32 Index)
{
    APMPlayerState* PS = GetPlayerState<APMPlayerState>();
    if (PS)
    {
        PS->SwitchToPartyMember(Index);
    }
}

#include "Player/PMPlayerController.h"
#include "Interfaces/PlayerActionsInterface.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Player/PMPlayerState.h"

void APMPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    // Verifica che sia presente EnhancedInputComponent
    if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
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
            EnhancedInputComponent->BindAction(IA_Move, ETriggerEvent::Triggered, this, &APMPlayerController::Move);
        }

        // Jump: azione binaria (pressed/released)
        if (IA_Jump)
        {
            EnhancedInputComponent->BindAction(IA_Jump, ETriggerEvent::Started, this, &APMPlayerController::Jump);
            // Se vuoi anche fine salto:
            // EnhancedInputComponent->BindAction(IA_Jump, ETriggerEvent::Completed, this, &AMyPlayerController::StopJumping);
        }

        // Attack: azione binaria
        if (IA_Attack)
        {
            EnhancedInputComponent->BindAction(IA_Attack, ETriggerEvent::Started, this, &APMPlayerController::Attack);
        }
        if (IA_Switch1)
        {
            EnhancedInputComponent->BindAction(IA_Switch1,  ETriggerEvent::Started, this, &APMPlayerController::SwitchToMember1);
        }
        if (IA_Switch2)
        {
            EnhancedInputComponent->BindAction(IA_Switch2,  ETriggerEvent::Started, this, &APMPlayerController::SwitchToMember2);
        }
        if (IA_Switch3)
        {
            EnhancedInputComponent->BindAction(IA_Switch3,  ETriggerEvent::Started, this, &APMPlayerController::SwitchToMember3);
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

void APMPlayerController::SwitchToMemberByIndex(int32 Index)
{
    APMPlayerState* PS = GetPlayerState<APMPlayerState>();
    if (PS)
    {
        PS->SwitchToPartyMember(Index);
    }
}

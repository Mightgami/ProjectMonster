// Fill out your copyright notice in the Description page of Project Settings.


#include "AsyncTaskNode/AsyncFlyTo.h"
#include "Engine.h"
#include "Engine/World.h"
#include "Editor/EditorEngine.h"


UAsyncFlyTo* UAsyncFlyTo::AIFlyTo(
	UObject* WorldContextObject,
	APawn* ControlledPawn,
	//AActor* ActorToReach,
	const FVector LocationToReach,
	const float AcceptanceRadius,
	const bool bStopAfterTimeLimit,
	const float TimeLimit)
{
	// Crea una nuova instanza e setta le variabili per il nodo nell'editor
	UAsyncFlyTo* BlueprintNode = NewObject<UAsyncFlyTo>();
	BlueprintNode->WorldContextObject = WorldContextObject;
	BlueprintNode->PawnItself = ControlledPawn;
	// if (ActorToReach != nullptr)
	// {
	// 	BlueprintNode->TargetLocation = ActorToReach->GetActorLocation();
	// }
	// else
	// {
		BlueprintNode->TargetLocation = LocationToReach;
	//}
	BlueprintNode->MaxAcceptanceRadius = AcceptanceRadius;
	BlueprintNode->bShouldStopAfterTimeLimit = bStopAfterTimeLimit;
	BlueprintNode->MaxTimeLimit = TimeLimit;
	
	return BlueprintNode;
}

void UAsyncFlyTo::SetTargetLocation(const FVector& NewTargetLocation)
{
	TargetLocation = NewTargetLocation;
}

void UAsyncFlyTo::Activate()
{
	//Super::Activate();
	World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull);

	// le tre righe successive non servono se il codice funziona solo in game
	if (World == nullptr && GEditor != nullptr) // se World è nullo usa
	{
		World = GEditor->GetEditorWorldContext().World();
	}

	if (World == nullptr || PawnItself == nullptr)
	{
		OnFail.Broadcast();
		FinishAIFlyTo();
		return;
	}

	// Schedula UpdateAIFlyTo da chiamare ogni 0.05 secondi in modo ricorsivo
	World->GetTimerManager().SetTimer(TimerHandle, this, &UAsyncFlyTo::UpdateAIFlyTo, 0.05f, true, -1.0f);
}

void UAsyncFlyTo::UpdateAIFlyTo()
{
	OnUpdate.Broadcast();
	const float Distance = FVector::Dist(PawnItself->GetActorLocation(), TargetLocation);
	if (Distance > MaxAcceptanceRadius)
	{
		//if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("Your Vector: ") + TargetLocation.ToString());
		SetPawnVelocity(false);

		if (ShouldStop())
		{
			OnFail.Broadcast();
			FinishAIFlyTo();
			return;
		}
	}
	else
	{
		SetPawnVelocity(true);
		OnSuccess.Broadcast();
		FinishAIFlyTo();
		return;
	}
}

// void UAsyncFlyTo::CancelAIFlyTo()
// {
// 	bOutSuccess = false;
// 	OutInfoMessage = TEXT("Cancelled");
//
// 	//OnCanceled.Broadcast();
//
// 	FinishAIFlyTo();
// }

// void UAsyncFlyTo::UpdateAIFlyTo()
// {
// 	// aggiorna il timer
// 	TimerCurrentTime += TimerIntervals;
//
// 	//OnUpdated.Broadcast();
//
// 	if (TimerCurrentTime >= TimerFinalTime)
// 	{
// 		bOutSuccess = true;
// 		OutInfoMessage = TEXT("Success");
// 		//OnCompleted.Broadcast();
//
// 		FinishAIFlyTo();
// 	}
// }

void UAsyncFlyTo::FinishAIFlyTo()
{
	//ferma il timer e distruggi istanza
	if (TimerHandle.IsValid() && World != nullptr)
	{
		World->GetTimerManager().ClearTimer(TimerHandle);
		TimerHandle.Invalidate();
	}
	SetReadyToDestroy();
}

bool UAsyncFlyTo::ShouldStop()
{
	bool Result = false;
	if (bShouldStopAfterTimeLimit)
	{
		if (World)
		{
			if (World->GetTimerManager().GetTimerElapsed(TimerHandle) > MaxTimeLimit)
			{
				Result = true;
			}
		}
	}
	return Result;
}

void UAsyncFlyTo::SetPawnVelocity(bool ShouldStop) const
{
	if (PawnItself == nullptr) return;
	
	//ACharacter* Character = CastChecked<ACharacter>(PawnItself);
	if (const ACharacter* Character = Cast<ACharacter>(PawnItself))
	{
		const FVector Direction = (TargetLocation - PawnItself->GetActorLocation()).GetSafeNormal();
		const float FlyingSpeed = Character->GetCharacterMovement()->MaxFlySpeed;
		if (Direction.X > 0.0f)
		{
			PawnItself->SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
		}
		else if (Direction.X < 0.0f)
		{
			PawnItself->SetActorRotation(FRotator(0.0f, 180.0f, 0.0f));
		}
		Character->GetCharacterMovement()->Velocity = ShouldStop ? FVector::ZeroVector : Direction * FlyingSpeed;
	}
}

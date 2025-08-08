// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AsyncFlyTo.generated.h"

/**
 * 
 */

class UObject;
class UWorld;

// Delegati usati per creare tutti gli output pins
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAsyncFlyToOutputPin);

UCLASS(BlueprintType, meta = (ExposedAsyncProxy = AsyncAction)) // Proprietà necessari per il funzionamento, meta solo se voglio esporre la variabile AIFlyTo
class PROJECTMONSTER_API UAsyncFlyTo : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	/**
	 * Order a Pawn with AIController to Fly to a location
	 * 
	 * @param ControlledPawn					The Pawn Controller by the AI
	 // * @param ActorToReach						The Actor to reach if exist
	 * @param LocationToReach					The Location to reach if the Actor don't exist
	 * @param AcceptanceRadius					The Minimum distance to have a success
	 * @param bStopAfterTimeLimit				true = the AI will stop if have no target o after time limit, false = will continue to try to reach the goal
	 * @param TimeLimit							The Max Time Limit to move AI, after that the AI will stop moving
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "AI FlyTo", meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "AI")
	static UAsyncFlyTo* AIFlyTo(
		UObject* WorldContextObject,
		APawn* ControlledPawn,
		//AActor* ActorToReach,
		const FVector LocationToReach,
		const float AcceptanceRadius,
		const bool bStopAfterTimeLimit,
		const float TimeLimit);

	// Output pin called when timer is failed
	UPROPERTY(BlueprintAssignable, Category = "AI")
	FAsyncFlyToOutputPin OnUpdate;
	
	// Output pin called when timer is completed
	UPROPERTY(BlueprintAssignable, Category = "AI")
	FAsyncFlyToOutputPin OnSuccess;
	
	// Output pin called when timer is failed
	UPROPERTY(BlueprintAssignable, Category = "AI")
	FAsyncFlyToOutputPin OnFail;	
	
	UPROPERTY(BlueprintReadOnly, Category = "AI")
	APawn* PawnItself = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "AI")
	FVector TargetLocation = FVector::ZeroVector;

	UPROPERTY(BlueprintReadOnly, Category = "AI")
	float MaxAcceptanceRadius = 0.0f;
	
	UPROPERTY(BlueprintReadOnly, Category = "AI")
	bool bShouldStopAfterTimeLimit = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "AI")
	float MaxTimeLimit = 0.0f;

	
	/** Cambia la destinazione del Target */
	UFUNCTION(BlueprintCallable, Category = "AI")
	void SetTargetLocation(const FVector& NewTargetLocation);

	
	// // Action's intervals
	// UPROPERTY(BlueprintReadOnly, Category = "AI")
	// float TimerIntervals = 0.0f;
	//
	// // Action's intervals
	// UPROPERTY(BlueprintReadOnly, Category = "AI")
	// float TimerFinalTime = 0.0f;
	//
	// // Action's intervals
	// UPROPERTY(BlueprintReadOnly, Category = "AI")
	// float TimerCurrentTime = 0.0f;
	//
	// // Action's intervals
	// UPROPERTY(BlueprintReadOnly, Category = "AI")
	// bool bOutSuccess = false;
	//
	// // Action's intervals
	// UPROPERTY(BlueprintReadOnly, Category = "AI")
	// FString OutInfoMessage = "";

public:
	/**
	* Cancel the Action and trigger the OnCancelled pin
	*/ 
	// UFUNCTION(BlueprintCallable, Category = "AI")
	// void CancelAIFlyTo();

private:
	// Finish and clean the Action Object
	UFUNCTION(BlueprintCallable, Category = "AI")
	void FinishAIFlyTo();
	
	// Start the Action (automatically called when the Blueprint note is called)
	virtual void Activate() override;

	// Update the Action
	void UpdateAIFlyTo();


	bool ShouldStop();
	void SetPawnVelocity(bool ShouldStop) const;

	UObject* WorldContextObject;
	UWorld* World;
	FTimerHandle TimerHandle;
};

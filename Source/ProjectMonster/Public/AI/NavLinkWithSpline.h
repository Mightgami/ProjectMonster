// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Navigation/NavLinkProxy.h"
#include "NavLinkWithSpline.generated.h"

class USplineComponent;

/**
 * 
 */
UCLASS()
class PROJECTMONSTER_API ANavLinkProxyWithSpline : public ANavLinkProxy
{
	GENERATED_BODY()

public:
	ANavLinkProxyWithSpline();

protected:
	virtual void BeginPlay() override;

#if WITH_EDITOR
	virtual void PostEditMove(bool bFinished) override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
	
private:
	UPROPERTY(EditAnywhere, Category = "JumpTrajectory")
	TObjectPtr<USplineComponent> SplineComponent;
	
	UPROPERTY(EditAnywhere, Category = "JumpTrajectory")
	float ApexHeight = 50.f;
	
	UPROPERTY(EditAnywhere, Category = "JumpTrajectory", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float ApexDistanceFromTop = 0.33f;

	UPROPERTY(EditAnywhere, Category = "JumpTrajectory")
	bool bShouldBeEqualForSide = false;

	UPROPERTY(EditAnywhere, Category = "JumpTrajectory|Same", meta = (EditCondition = "bShouldBeEqualForSide", EditConditionHides))
	float Curvature = 100.f;

	UPROPERTY(EditAnywhere, Category = "JumpTrajectory|Same", meta = (EditCondition = "bShouldBeEqualForSide", EditConditionHides))
	float Flatness = 0.f;
	
	UPROPERTY(EditAnywhere, Category = "JumpTrajectory|Right", meta = (EditCondition = "!bShouldBeEqualForSide", EditConditionHides))
	float RightCurvature = 100.f;

	UPROPERTY(EditAnywhere, Category = "JumpTrajectory|Right", meta = (EditCondition = "!bShouldBeEqualForSide", EditConditionHides))
	float RightFlatness = 0.f;

	UPROPERTY(EditAnywhere, Category = "JumpTrajectory|Left", meta = (EditCondition = "!bShouldBeEqualForSide", EditConditionHides))
	float LeftCurvature = 100.f;

	UPROPERTY(EditAnywhere, Category = "JumpTrajectory|Left", meta = (EditCondition = "!bShouldBeEqualForSide", EditConditionHides))
	float LeftFlatness = 0.f;

private:
	void SetSplinePosition();
};
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
	/** NavLink Positioning **/
	float SnapValueToGrid(float DragPosition, const float Interval);
	void SnapRootToTileMap();
	void SnapEndLinkToTileMap();
	bool IsRootDragged = false;
	FVector RootPreviousLocation;
	bool bIsConstructed = false;
	
	UPROPERTY(EditAnywhere, Category = "NavLink Positioning")
	float SingleTileSize = 100.f;
	/** End NavLink Positioning **/

	/** Spline **/
	void SetSplinePosition();

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
	float Roundness = 0.f;
	
	UPROPERTY(EditAnywhere, Category = "JumpTrajectory|Right", meta = (EditCondition = "!bShouldBeEqualForSide", EditConditionHides))
	float RightCurvature = 100.f;

	UPROPERTY(EditAnywhere, Category = "JumpTrajectory|Right", meta = (EditCondition = "!bShouldBeEqualForSide", EditConditionHides))
	float RightRoundness = 0.f;

	UPROPERTY(EditAnywhere, Category = "JumpTrajectory|Left", meta = (EditCondition = "!bShouldBeEqualForSide", EditConditionHides))
	float LeftCurvature = 100.f;

	UPROPERTY(EditAnywhere, Category = "JumpTrajectory|Left", meta = (EditCondition = "!bShouldBeEqualForSide", EditConditionHides))
	float LeftRoundness = 0.f;
	/** End Spline **/
};
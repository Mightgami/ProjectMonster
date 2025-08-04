// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Navigation/NavLinkProxy.h"
#include "BasicSmartNavLinkProxy.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTMONSTER_API ABasicSmartNavLinkProxy : public ANavLinkProxy
{
	GENERATED_BODY()
protected:
	ABasicSmartNavLinkProxy();
	virtual void BeginPlay() override;

#if WITH_EDITOR
	virtual void PostEditMove(bool bFinished) override;
#endif

private:
	/** NavLink Positioning **/
	float SnapValueToGrid(float DragPosition, const float Interval);
	void SnapRootToTileMap();
	void SnapEndLinkToTileMap();
	bool IsRootDragged = false;
	FVector RootPreviousLocation;
	bool bIsConstructed = false;
	
	
	UPROPERTY(EditAnywhere, Category = "NavLinkSettings|Positioning")
	bool bIs2D = true;
	
	UPROPERTY(EditAnywhere, Category = "NavLinkSettings|Positioning")
	float SingleTileSize = 100.f;
	/** End NavLink Positioning **/
};

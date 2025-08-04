// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BasicSmartNavLinkProxy.h"


ABasicSmartNavLinkProxy::ABasicSmartNavLinkProxy()
{
	PrimaryActorTick.bCanEverTick = true;
	bSmartLinkIsRelevant = false;

	PointLinks[0].Left = FVector(0.f, 0.f, 0.f);
	PointLinks[0].Right = FVector(100.f, 0.f, 0.f);
}

void ABasicSmartNavLinkProxy::BeginPlay()
{
	Super::BeginPlay();
	PointLinks.Empty();
}

#if WITH_EDITOR
void ABasicSmartNavLinkProxy::PostEditMove(bool bFinished)
{
	Super::PostEditMove(bFinished);
	if (!IsRootDragged)
	{
		RootPreviousLocation.X = SnapValueToGrid(GetActorLocation().X, SingleTileSize);
		RootPreviousLocation.Y = 0;
		RootPreviousLocation.Z = SnapValueToGrid(GetActorLocation().Z, SingleTileSize);
		SetActorLocation(RootPreviousLocation, false, nullptr, ETeleportType::None);
		IsRootDragged = true;
	}
	
	PointLinks[0].Left = FVector(0.f, 0.f, 0.f);
	bSmartLinkIsRelevant = false;
	
	if (bFinished)
	{
		SnapRootToTileMap();
		SnapEndLinkToTileMap();
		CopyEndPointsFromSimpleLinkToSmartLink();
		IsRootDragged = false;
		bSmartLinkIsRelevant = true;
	}
}
#endif

float ABasicSmartNavLinkProxy::SnapValueToGrid(float DragPosition, const float Interval)
{
	if (Interval == 0.0f) return DragPosition;
	DragPosition = FMath::RoundToFloat(DragPosition / (0.5f * Interval)) * (0.5f * Interval);
	return DragPosition;
}

void ABasicSmartNavLinkProxy::SnapRootToTileMap()
{
	const FVector CurrentLocation = GetActorLocation();
	FVector SnapLocation;
	
	SnapLocation.X = SnapValueToGrid(CurrentLocation.X, SingleTileSize);
	SnapLocation.Y = 0;
	SnapLocation.Z = SnapValueToGrid(CurrentLocation.Z, SingleTileSize);
	
	if (SnapLocation != CurrentLocation)
	{
		SetActorLocation(SnapLocation, false, nullptr, ETeleportType::None);
	}
}

void ABasicSmartNavLinkProxy::SnapEndLinkToTileMap()
{
	const FVector RightCurrentLocation = PointLinks[0].Right;
	FVector RightSnapLocation;
	
	RightSnapLocation.X = SnapValueToGrid(RightCurrentLocation.X, SingleTileSize);
	RightSnapLocation.Y = 0;
	RightSnapLocation.Z = SnapValueToGrid(RightCurrentLocation.Z, SingleTileSize);
	
	if (RightSnapLocation != RightCurrentLocation)
	{
		PointLinks[0].Right = RightSnapLocation;
	}
}

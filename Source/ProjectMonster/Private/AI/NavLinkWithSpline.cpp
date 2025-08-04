// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/NavLinkWithSpline.h"

#include "Components/SplineComponent.h"

ANavLinkProxyWithSpline::ANavLinkProxyWithSpline()
{
	PrimaryActorTick.bCanEverTick = true;
	bSmartLinkIsRelevant = false;
	

	PointLinks[0].Left = FVector(0.f, 0.f, 0.f);
	PointLinks[0].Right = FVector(100.f, 0.f, 0.f);

	SplineComponent = CreateDefaultSubobject<USplineComponent>("JumpArc", false);
	SplineComponent->SetupAttachment(RootComponent);
	SplineComponent->SetMobility(EComponentMobility::Movable);

	if (SplineComponent)
	{
		TArray<FVector> Points;
		const FVector StartPoint = PointLinks[0].Left;
		const FVector MiddlePoint = FMath::Lerp(PointLinks[0].Left, PointLinks[0].Right, 0.5);
		const FVector EndPoint = PointLinks[0].Right;
		Points.Add(StartPoint);
		Points.Add(MiddlePoint + ApexDistanceFromTop);
		Points.Add(EndPoint);
		
		SplineComponent->SetSplinePoints(Points, ESplineCoordinateSpace::World, true);
		
		SplineComponent->SetSplinePointType(0, ESplinePointType::CurveClamped, true);
		SplineComponent->SetSplinePointType(2, ESplinePointType::CurveClamped, true);
		
	}
}

void ANavLinkProxyWithSpline::BeginPlay()
{
	Super::BeginPlay();
	bSmartLinkIsRelevant = true;
	CopyEndPointsFromSimpleLinkToSmartLink();
	SetSplinePosition();
	PointLinks.Empty();

	if (SplineComponent->GetNumberOfSplinePoints() > 3)
	{
		for (int32 i = SplineComponent->GetNumberOfSplinePoints() - 1; i >= 3; --i)
		{
			SplineComponent->RemoveSplinePoint(i, false);
		}
	}
}


#if WITH_EDITOR
void ANavLinkProxyWithSpline::PostEditMove(bool bFinished)
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

	if (bFinished)
	{
		SnapRootToTileMap();
		SnapEndLinkToTileMap();
		CopyEndPointsFromSimpleLinkToSmartLink();
		IsRootDragged = false;
		SetSplinePosition();
	}
}

void ANavLinkProxyWithSpline::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	// Controlla la proprietà modificata
	const FName PropertyName = PropertyChangedEvent.Property 
		? PropertyChangedEvent.Property->GetFName() 
		: NAME_None;

		// Se `SplineApexHeight` o `SplineApexDistanceFromTop` sono modificati
	if (
		PropertyName == GET_MEMBER_NAME_CHECKED(ANavLinkProxyWithSpline, SingleTileSize) ||
		PropertyName == GET_MEMBER_NAME_CHECKED(ANavLinkProxyWithSpline, SplineComponent) ||
		PropertyName == GET_MEMBER_NAME_CHECKED(ANavLinkProxyWithSpline, ApexHeight) ||
		PropertyName == GET_MEMBER_NAME_CHECKED(ANavLinkProxyWithSpline, ApexDistanceFromTop) ||
		PropertyName == GET_MEMBER_NAME_CHECKED(ANavLinkProxyWithSpline, bShouldBeEqualForSide) ||
		PropertyName == GET_MEMBER_NAME_CHECKED(ANavLinkProxyWithSpline, Curvature) ||
		PropertyName == GET_MEMBER_NAME_CHECKED(ANavLinkProxyWithSpline, Roundness) ||
		PropertyName == GET_MEMBER_NAME_CHECKED(ANavLinkProxyWithSpline, RightCurvature) ||
		PropertyName == GET_MEMBER_NAME_CHECKED(ANavLinkProxyWithSpline, RightRoundness) ||
		PropertyName == GET_MEMBER_NAME_CHECKED(ANavLinkProxyWithSpline, LeftCurvature) ||
		PropertyName == GET_MEMBER_NAME_CHECKED(ANavLinkProxyWithSpline, LeftRoundness))
		{
			SetSplinePosition(); // Esegui la funzione per aggiornare la spline
		}
	}

float ANavLinkProxyWithSpline::SnapValueToGrid(float DragPosition, const float Interval)
{
	if (Interval == 0.0f) return DragPosition;
	DragPosition = FMath::RoundToFloat(DragPosition / (0.5f * Interval)) * (0.5f * Interval);
	return DragPosition;
}

void ANavLinkProxyWithSpline::SnapRootToTileMap()
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

void ANavLinkProxyWithSpline::SnapEndLinkToTileMap()
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
#endif

void ANavLinkProxyWithSpline::SetSplinePosition()
{
	if (SplineComponent && PointLinks.Num() > 0)
	{
		SplineComponent->SetLocationAtSplinePoint(0, PointLinks[0].Right, ESplineCoordinateSpace::Local, false);
		SplineComponent->SetLocationAtSplinePoint(2, PointLinks[0].Left, ESplineCoordinateSpace::Local, false);

		FVector MiddleLocation = FVector::ZeroVector;

		if (PointLinks[0].Right.Z != PointLinks[0].Left.Z)
		{
			const float HeightDifference = PointLinks[0].Right.Z - PointLinks[0].Left.Z;
			if (HeightDifference > 0.f)
			{
				MiddleLocation = FMath::Lerp(PointLinks[0].Left, PointLinks[0].Right, 1 - ApexDistanceFromTop);
				MiddleLocation.Z = PointLinks[0].Right.Z + ApexHeight;
			}
			else if (HeightDifference < 0.f)
			{
				MiddleLocation = FMath::Lerp(PointLinks[0].Left, PointLinks[0].Right, ApexDistanceFromTop);
				MiddleLocation.Z = PointLinks[0].Left.Z + ApexHeight;
			}
		}
		else
		{
			MiddleLocation = FMath::Lerp(PointLinks[0].Left, PointLinks[0].Right, 0.5);
			MiddleLocation.Z = ApexHeight;
		}

		SplineComponent->SetLocationAtSplinePoint(1, MiddleLocation, ESplineCoordinateSpace::Local, false);

		if (bShouldBeEqualForSide)
		{
			const FVector Tangent = FVector(-Curvature, 0.f, Roundness);
			SplineComponent->SetTangentAtSplinePoint(1, Tangent, ESplineCoordinateSpace::Local, false);
		}
		else
		{
			int32 Side = 1;	
			if (PointLinks[0].Right.X > PointLinks[0].Left.X)
			{
				Side = -1;
			}
			const FVector ArriveTangent = FVector(Side * RightCurvature, 0.f, LeftRoundness);
			const FVector LeaveTangent = FVector(Side * LeftCurvature, 0.f, RightRoundness);
			SplineComponent->SetTangentsAtSplinePoint(1, ArriveTangent, LeaveTangent, ESplineCoordinateSpace::Local, false);
		}
	}

	SplineComponent->SetRelativeLocation(FVector::ZeroVector, true);
	SplineComponent->UpdateSpline();
}
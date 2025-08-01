// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/NavLinkWithSpline.h"

#include "Components/SplineComponent.h"

ANavLinkProxyWithSpline::ANavLinkProxyWithSpline()
{
	PrimaryActorTick.bCanEverTick = true;
	bSmartLinkIsRelevant = false;

	SplineComponent = CreateDefaultSubobject<USplineComponent>("JumpArc", false);
	SplineComponent->SetupAttachment(RootComponent);
	SplineComponent->SetMobility(EComponentMobility::Movable);

	if (SplineComponent)
	{
		// Disabilitare l'interazione della spline in editor
		//SplineComponent->SetAllowSplineEditingPerInstance(false);
		
		TArray<FVector> Points;
		const FVector StartPoint = FVector::ZeroVector;
		const FVector MiddlePoint = FVector(100.f, 0.f, 100.f);
		const FVector EndPoint = FVector(200.f, 0.f, 0.f);
		Points.Add(StartPoint);
		Points.Add(MiddlePoint);
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
}

#if WITH_EDITOR
void ANavLinkProxyWithSpline::PostEditMove(bool bFinished)
{
	Super::PostEditMove(bFinished);
	if (bFinished)
	{
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
	if (PropertyName == GET_MEMBER_NAME_CHECKED(ANavLinkProxyWithSpline, ApexHeight) ||
		PropertyName == GET_MEMBER_NAME_CHECKED(ANavLinkProxyWithSpline, ApexDistanceFromTop) ||
		PropertyName == GET_MEMBER_NAME_CHECKED(ANavLinkProxyWithSpline, bShouldBeEqualForSide) ||
		PropertyName == GET_MEMBER_NAME_CHECKED(ANavLinkProxyWithSpline, Curvature) ||
		PropertyName == GET_MEMBER_NAME_CHECKED(ANavLinkProxyWithSpline, Flatness) ||
		PropertyName == GET_MEMBER_NAME_CHECKED(ANavLinkProxyWithSpline, RightCurvature) ||
		PropertyName == GET_MEMBER_NAME_CHECKED(ANavLinkProxyWithSpline, RightFlatness) ||
		PropertyName == GET_MEMBER_NAME_CHECKED(ANavLinkProxyWithSpline, LeftCurvature) ||
		PropertyName == GET_MEMBER_NAME_CHECKED(ANavLinkProxyWithSpline, LeftFlatness))
		{
			SetSplinePosition(); // Esegui la funzione per aggiornare la spline
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
			const FVector Tangent = FVector(0.f, -Curvature, Flatness);
			SplineComponent->SetTangentAtSplinePoint(1, Tangent, ESplineCoordinateSpace::Local, true);
		}
		else
		{
			const FVector ArriveTangent = FVector(0.f, -RightCurvature, RightFlatness);
			const FVector LeaveTangent = FVector(0.f, -LeftCurvature, LeftFlatness);
			SplineComponent->SetTangentsAtSplinePoint(1, ArriveTangent, LeaveTangent, ESplineCoordinateSpace::Local, true);
		}
	}
}

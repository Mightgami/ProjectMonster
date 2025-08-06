// Fill out your copyright notice in the Description page of Project Settings.

#include "AI/EQS/EnvQueryGenerator_RadialGrid.h"
#include "EnvironmentQuery/Contexts/EnvQueryContext_Querier.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(EnvQueryGenerator_RadialGrid)

#define LOCTEXT_NAMESPACE "EnvQueryGenerator"

UEnvQueryGenerator_RadialGrid::UEnvQueryGenerator_RadialGrid(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	GenerateAround = UEnvQueryContext_Querier::StaticClass();
	Space = ERadialPlane::ERP_XY;
	bShouldStagger.DefaultValue = false;
	MinDistance.DefaultValue = 50.0f;
	MaxDistance.DefaultValue = 150.0f;
	Points.DefaultValue = 3;
	Rays.DefaultValue = 5;
}

void UEnvQueryGenerator_RadialGrid::GenerateItems(FEnvQueryInstance& QueryInstance) const
{
	const UObject* BindOwner = QueryInstance.Owner.Get();
	bShouldStagger.BindData(BindOwner, QueryInstance.QueryID);
	MinDistance.BindData(BindOwner, QueryInstance.QueryID);
	MaxDistance.BindData(BindOwner, QueryInstance.QueryID);
	Points.BindData(BindOwner, QueryInstance.QueryID);
	Rays.BindData(BindOwner, QueryInstance.QueryID);

	const float MinDistanceValue = MinDistance.GetValue();
	const float MaxDistanceValue = MaxDistance.GetValue();
	
	const bool bStagger = bShouldStagger.GetValue();
	
	const int32 PointsPerRay = Points.GetValue() - 1;
	const int32 RaysOnPlane = Rays.GetValue();

	const float RingDist = (MaxDistanceValue - MinDistanceValue) / PointsPerRay;

	TArray<FVector> ContextLocations;
	QueryInstance.PrepareContext(GenerateAround, ContextLocations);

	TArray<FNavLocation> ItemCandidates;

	for (const FVector& Center : ContextLocations)
	{
		for (int32 i = 0; i < RaysOnPlane; ++i)
		{
			for (int32 c = 0; c <= PointsPerRay; ++c)
			{
				const float AngleOffset = bStagger ? ((PI / RaysOnPlane) * c) : 0.0f;
				const float Angle = 2 * PI * i / RaysOnPlane + AngleOffset;

				FVector Dir;
				switch (Space)
				{
				case ERadialPlane::ERP_XY:
					Dir = FVector(FMath::Cos(Angle), FMath::Sin(Angle), 0);
					break;
				case ERadialPlane::ERP_XZ:
					Dir = FVector(FMath::Cos(Angle + PI / 2), 0, FMath::Sin(Angle + PI / 2));
					break;
				case ERadialPlane::ERP_YZ:
					Dir = FVector(0, FMath::Cos(Angle + PI / 2), FMath::Sin(Angle + PI / 2));
					break;
				default:
					Dir = FVector::ZeroVector;
					break;
				}

				const float Radius = RingDist * c;
				const FVector Point = Center + Dir * MinDistanceValue + Dir * Radius;
				ItemCandidates.Add(FNavLocation(Point));
			}
		}
	}
	ProjectAndFilterNavPoints(ItemCandidates, QueryInstance);
	StoreNavPoints(ItemCandidates, QueryInstance);
}
FText UEnvQueryGenerator_RadialGrid::GetDescriptionTitle() const
{
	return FText::Format(
		LOCTEXT("GenerateAroundContext", "{0}: generate around {1}"),
		Super::GetDescriptionTitle(),
		UEnvQueryTypes::DescribeContext(GenerateAround)
	);

}

FText UEnvQueryGenerator_RadialGrid::GetDescriptionDetails() const
{
	FText Desc = FText::Format(
		LOCTEXT("RadialGridDetails3D", "Space: {0}\nSpacing: {1}, Points: {2}, Rays: {3}"),
		FText::FromString(UEnum::GetValueAsString(Space)),
		FText::AsNumber(MaxDistance.DefaultValue),
		FText::AsNumber(Points.DefaultValue),
		FText::AsNumber(Rays.DefaultValue));


	FText ProjDesc = ProjectionData.ToText(FEnvTraceData::Brief);
	if (!ProjDesc.IsEmpty())
	{
		FFormatNamedArguments ProjArgs;
		ProjArgs.Add(TEXT("Description"), Desc);
		ProjArgs.Add(TEXT("ProjectionDescription"), ProjDesc);
		Desc = FText::Format(LOCTEXT("DescriptionWithProjection", "{Description}, {ProjectionDescription}"), ProjArgs);
	}

	return Desc;
}

#undef LOCTEXT_NAMESPACE
// Fill out your copyright notice in the Description page of Project Settings.

#include "AI/EQS/EnvQueryGenerator_SpatialGrid.h"
#include "EnvironmentQuery/Contexts/EnvQueryContext_Querier.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(EnvQueryGenerator_SpatialGrid)

#define LOCTEXT_NAMESPACE "EnvQueryGenerator"

UEnvQueryGenerator_SpatialGrid::UEnvQueryGenerator_SpatialGrid(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	GenerateAround = UEnvQueryContext_Querier::StaticClass();
	GridSpacing.DefaultValue = 100.0f;
//	Space2 = EGridPlane::EGP_XY;
	Rows.DefaultValue = 5;
	Columns.DefaultValue = 5;
	Depth.DefaultValue = 1;
}

void UEnvQueryGenerator_SpatialGrid::GenerateItems(FEnvQueryInstance& QueryInstance) const
{
	const UObject* BindOwner = QueryInstance.Owner.Get();
	GridSpacing.BindData(BindOwner, QueryInstance.QueryID);
	Rows.BindData(BindOwner, QueryInstance.QueryID);
	Columns.BindData(BindOwner, QueryInstance.QueryID);
	Depth.BindData(BindOwner, QueryInstance.QueryID);

	float CalculatedGridSpacing = GridSpacing.GetValue();
	int32 CalculatedRows = Rows.GetValue();
	int32 CalculatedColumns = Columns.GetValue();
	int32 CalculatedDepth = Depth.GetValue();

	TArray<FVector> ContextLocations;
	QueryInstance.PrepareContext(GenerateAround, ContextLocations);

	// Questo array conterrà i punti generati
	TArray<FNavLocation> ItemCandidates;
	const int32 DepthCount = (Space == EGridPlane::EGP_3D) ? CalculatedDepth : 1;
	ItemCandidates.Reserve(CalculatedRows * CalculatedColumns * DepthCount * ContextLocations.Num());

	// Calcolo gli "offset" per centrare la griglia attorno a ciascun ContextLocation
	const float GridWidth = (CalculatedColumns - 1) * CalculatedGridSpacing;
	const float GridHeight = (CalculatedRows - 1) * CalculatedGridSpacing;
	const float GridDepth = (CalculatedDepth - 1) * CalculatedGridSpacing;

	for (const FVector& Origin : ContextLocations)
	{
		for (int32 Row = 0; Row < CalculatedRows; ++Row)
		{
			for (int32 Column = 0; Column < CalculatedColumns; ++Column)
			{
				for (int32 DepthLevel = 0; DepthLevel < DepthCount; ++DepthLevel)
				{
					float OffsetX = Column * CalculatedGridSpacing - GridWidth / 2.0f;
					float OffsetY = Row * CalculatedGridSpacing - GridHeight / 2.0f;
					float OffsetZ = (Space == EGridPlane::EGP_3D) ? DepthLevel * CalculatedGridSpacing - GridDepth / 2.0f : 0.f;

					FVector PointLocation;
					switch (Space)
					{
					case EGridPlane::EGP_XY:
						PointLocation = Origin + FVector(OffsetX, OffsetY, 0.f);
						break;
					case EGridPlane::EGP_XZ:
						PointLocation = Origin + FVector(OffsetX, 0.f, OffsetY);
						break;
					case EGridPlane::EGP_YZ:
						PointLocation = Origin + FVector(0.f, OffsetX, OffsetY);
						break;
					case EGridPlane::EGP_3D:
						PointLocation = Origin + FVector(OffsetX, OffsetY, OffsetZ); 
						break;
					default:
						PointLocation = Origin + FVector(OffsetX, OffsetY, OffsetZ);
						break;
					}

					ItemCandidates.Add(FNavLocation(PointLocation));
				}
			}
		}
	}

	// Filtra i punti al di fuori dell'area di navigazione
	ProjectAndFilterNavPoints(ItemCandidates, QueryInstance);

	// Salva i punti generati nel risultato della Query
	StoreNavPoints(ItemCandidates, QueryInstance);
}

FText UEnvQueryGenerator_SpatialGrid::GetDescriptionTitle() const
{
	return FText::Format(
		LOCTEXT("GenerateAroundContext", "{0}: generate around {1}"),
		Super::GetDescriptionTitle(),
		UEnvQueryTypes::DescribeContext(GenerateAround)
	);

}

FText UEnvQueryGenerator_SpatialGrid::GetDescriptionDetails() const
{
	FText Desc = (Space == EGridPlane::EGP_3D) 
    ? FText::Format( // is 3D
        LOCTEXT("SpatialGridDetails3D", "Space: {0}, Spacing: {1}, Rows: {2}, Columns: {3}, Depths: {4}"),
        FText::FromString(UEnum::GetValueAsString(Space)),
        FText::AsNumber(GridSpacing.DefaultValue),
        FText::AsNumber(Rows.DefaultValue),
        FText::AsNumber(Columns.DefaultValue),
        FText::AsNumber(Depth.DefaultValue))
    : FText::Format( // is not 3D
        LOCTEXT("SpatialGridDetails2D", "Space: {0}, Spacing: {1}, Rows: {2}, Columns: {3}"),
        FText::FromString(UEnum::GetValueAsString(Space)),
        FText::AsNumber(GridSpacing.DefaultValue),
        FText::AsNumber(Rows.DefaultValue),
        FText::AsNumber(Columns.DefaultValue));

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
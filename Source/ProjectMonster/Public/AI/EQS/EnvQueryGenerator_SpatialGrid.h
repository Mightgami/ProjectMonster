// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "Templates/SubclassOf.h"
#include "DataProviders/AIDataProvider.h"
#include "EnvironmentQuery/EnvQueryContext.h"
#include "EnvironmentQuery/Generators/EnvQueryGenerator_ProjectedPoints.h"
#include "EnvQueryGenerator_SpatialGrid.generated.h"

// Enumeratore per specificare il piano di creazione della griglia
UENUM(BlueprintType)
enum class EGridPlane : uint8
{
	EGP_XY = 0 UMETA(DisplayName = "Piano XY"), // Default: XY
	EGP_XZ = 1 UMETA(DisplayName = "Piano XZ"),
	EGP_YZ = 2 UMETA(DisplayName = "Piano ZY"),
	EGP_3D = 3 UMETA(DisplayName = "3D")
};

UCLASS(meta = (Category = "CustomGenerators"), DisplayName = "SpatialGrid")
class PROJECTMONSTER_API UEnvQueryGenerator_SpatialGrid : public UEnvQueryGenerator_ProjectedPoints
{
	GENERATED_UCLASS_BODY()

public:
	/** Genera gli items in una griglia e li posiziona nell'ambiente */
	virtual void GenerateItems(FEnvQueryInstance& QueryInstance) const override;

	/* Distanza tra punti */
	UPROPERTY(EditAnywhere, Category = "GridSettings")
	FAIDataProviderFloatValue GridSpacing;
	
	/* Specifica il piano della griglia */
	UPROPERTY(EditAnywhere, Category = "GridSettings")
	EGridPlane Space;
	
	/* Numero di righe */
	UPROPERTY(EditAnywhere, Category = "GridSettings|Dimensions")
	FAIDataProviderFloatValue Rows;

	/* Numero di colonne */
	UPROPERTY(EditAnywhere, Category = "GridSettings|Dimensions")
	FAIDataProviderFloatValue Columns;

	/* Numero di livelli lungo Z (per la modalità 3D) */
	UPROPERTY(EditAnywhere, Category = "GridSettings|Dimensions", meta = (EditCondition = "Space == EGridPlane::EGP_3D", EditConditionHides))
	FAIDataProviderFloatValue Depth;
	
	UPROPERTY(EditAnywhere, Category = "Generator")
	TSubclassOf<UEnvQueryContext> GenerateAround;

	virtual FText GetDescriptionTitle() const override;
	virtual FText GetDescriptionDetails() const override;
};

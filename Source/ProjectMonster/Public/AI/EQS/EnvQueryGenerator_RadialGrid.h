// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "Templates/SubclassOf.h"
#include "DataProviders/AIDataProvider.h"
#include "EnvironmentQuery/EnvQueryContext.h"
#include "EnvironmentQuery/Generators/EnvQueryGenerator_ProjectedPoints.h"
#include "EnvQueryGenerator_RadialGrid.generated.h"

// Enumeratore per specificare il piano di creazione della griglia
UENUM(BlueprintType)
enum class ERadialPlane : uint8
{
	ERP_XY = 0 UMETA(DisplayName = "Piano XY"), // Default: XY
	ERP_XZ = 1 UMETA(DisplayName = "Piano XZ"),
	ERP_YZ = 2 UMETA(DisplayName = "Piano ZY"),
};

UCLASS(meta = (Category = "CustomGenerators"), DisplayName = "RadialGrid")
class PROJECTMONSTER_API UEnvQueryGenerator_RadialGrid : public UEnvQueryGenerator_ProjectedPoints
{
	GENERATED_UCLASS_BODY()

public:
	/** Genera gli items in una griglia e li posiziona nell'ambiente */
	virtual void GenerateItems(FEnvQueryInstance& QueryInstance) const override;

	/* Piano su cui si genera la distribuzione */
	UPROPERTY(EditAnywhere, Category = "RadialSettings")
	ERadialPlane Space;
	
	/* Abilita/disabilita lo sfasamento angolare dei punti su anelli diversi */
	UPROPERTY(EditAnywhere, Category = "RadialSettings", DisplayName = "Stagger")
	FAIDataProviderBoolValue bShouldStagger;

	/* Spaziatura tra le circonferenze */
	UPROPERTY(EditAnywhere, Category = "RadialSettings")
	FAIDataProviderFloatValue MinDistance;
	
	/* Spaziatura tra le circonferenze */
	UPROPERTY(EditAnywhere, Category = "RadialSettings")
	FAIDataProviderFloatValue MaxDistance;

	/* Numero di circonferenze concentriche */	
	UPROPERTY(EditAnywhere, Category = "RadialSettings|Dimensions")
	FAIDataProviderIntValue Points;

	/* Numero di punti su ogni circonferenza */
	UPROPERTY(EditAnywhere, Category = "RadialSettings|Dimensions")
	FAIDataProviderIntValue Rays;
	
	UPROPERTY(EditAnywhere, Category = "Generator|Dimensions")
	TSubclassOf<UEnvQueryContext> GenerateAround;

	virtual FText GetDescriptionTitle() const override;
	virtual FText GetDescriptionDetails() const override;
};

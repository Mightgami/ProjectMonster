// By Anthony Fedeli.

#pragma once

#include "CoreMinimal.h"
#include "Actors/PMEffectActor.h"
#include "PMEffectActor_ProjectileBase.generated.h"

class UProjectileMovementComponent;
class USphereComponent;


/**
 * 
 */
UCLASS()
class PROJECTMONSTER_API APMEffectActor_ProjectileBase : public APMEffectActor
{
	GENERATED_BODY()
	
public:
	APMEffectActor_ProjectileBase();
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<USphereComponent> SphereCollision;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UProjectileMovementComponent> ProjectileMovement;
};

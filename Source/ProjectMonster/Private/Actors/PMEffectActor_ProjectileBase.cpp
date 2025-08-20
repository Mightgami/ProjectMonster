// By Anthony Fedeli.


#include "Actors/PMEffectActor_ProjectileBase.h"

#include "PaperFlipBookComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "PaperZDAnimationComponent.h"

APMEffectActor_ProjectileBase::APMEffectActor_ProjectileBase()
{
	PrimaryActorTick.bCanEverTick = true;
	SphereCollision = CreateDefaultSubobject<USphereComponent>("SphereCollision");
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovement");
	RemoveOwnedComponent(GetRootComponent());
	SetRootComponent(SphereCollision);
}

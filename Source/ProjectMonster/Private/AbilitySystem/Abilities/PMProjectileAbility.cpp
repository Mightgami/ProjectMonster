// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/PMProjectileAbility.h"

#include "Actors/PMProjectile.h"
#include "Kismet/KismetSystemLibrary.h"

void UPMProjectileAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
										   const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
										   const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	FTransform SpawnTransform;
	FVector newLocation = GetAvatarActorFromActorInfo()->GetActorLocation() + FVector(20, 20 , 20);
	SpawnTransform.SetLocation(newLocation);
	//TODO: Set the Projectile Rotation
		
	APMProjectile* Projectile = GetWorld()->SpawnActorDeferred<APMProjectile>(
		ProjectileClass,
		SpawnTransform,
		GetOwningActorFromActorInfo(),
		Cast<APawn>(GetOwningActorFromActorInfo()),
		ESpawnActorCollisionHandlingMethod::AlwaysSpawn);

	//TODO: Give the Projectile a Gameplay Effect Spec for causing Damage.
		
	Projectile->FinishSpawning(SpawnTransform);
}
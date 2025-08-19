// Fill out your copyright notice in the Description page of Project Settings.


#include "PMAssetManager.h"
#include "PMGameplayTags.h"

UPMAssetManager& UPMAssetManager::Get()
{
	check(GEngine);
	
	UPMAssetManager* PMAssetManager = Cast<UPMAssetManager>(GEngine->AssetManager);
	return *PMAssetManager;
}

void UPMAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	FPMGameplayTags::InitializeNativeGameplayTags();
}

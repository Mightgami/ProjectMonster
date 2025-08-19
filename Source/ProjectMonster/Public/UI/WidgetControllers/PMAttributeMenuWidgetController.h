// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetControllers/PMWidgetController.h"
#include "PMAttributeMenuWidgetController.generated.h"


class UAttributeInfo;
struct FGameplayAttribute;
struct FPMAttributeInfo;
struct FGameplayTag;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAttributeInfoSignature, const FPMAttributeInfo&, Info);

UCLASS(BlueprintType, Blueprintable)
class PROJECTMONSTER_API UPMAttributeMenuWidgetController : public UPMWidgetController
{
	GENERATED_BODY()
public:
	virtual void BindCallBacksToDependencies() override;
	virtual void BroadcastInitialValues() override;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FAttributeInfoSignature AttributeInfoDelegate;

protected:

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UAttributeInfo> AttributeInfo;


private:

	void BroadcastAttributeInfo(const FGameplayTag& AttributeTag, const FGameplayAttribute& Attribute) const;	
};

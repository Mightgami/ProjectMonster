// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "PMAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)


USTRUCT()
struct FEffectProperties
{
	GENERATED_BODY()

	FEffectProperties(){}

	FGameplayEffectContextHandle EffectContextHandle;

	UPROPERTY()
	UAbilitySystemComponent* SourceASC = nullptr;

	UPROPERTY()
	AActor* SourceAvatarActor = nullptr;

	UPROPERTY()
	AController* SourceController = nullptr;

	UPROPERTY()
	ACharacter* SourceCharacter = nullptr;

	UPROPERTY()
	UAbilitySystemComponent* TargetASC = nullptr;

	UPROPERTY()
	AActor* TargetAvatarActor = nullptr;

	UPROPERTY()
	AController* TargetController = nullptr;

	UPROPERTY()
	ACharacter* TargetCharacter = nullptr;
};


UCLASS()
class PROJECTMONSTER_API UPMAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UPMAttributeSet();
	
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;

	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	/*
	 *Primary Attributes
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Primary Attributes")
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(UPMAttributeSet, Strength);

	UPROPERTY(BlueprintReadOnly, Category = "Primary Attributes")
	FGameplayAttributeData Dexterity;
	ATTRIBUTE_ACCESSORS(UPMAttributeSet, Dexterity);

	UPROPERTY(BlueprintReadOnly, Category = "Primary Attributes")
	FGameplayAttributeData Constitution;
	ATTRIBUTE_ACCESSORS(UPMAttributeSet, Constitution);

	UPROPERTY(BlueprintReadOnly, Category = "Primary Attributes")
	FGameplayAttributeData Intelligence;
	ATTRIBUTE_ACCESSORS(UPMAttributeSet, Intelligence);

	UPROPERTY(BlueprintReadOnly, Category = "Primary Attributes")
	FGameplayAttributeData Wisdom;
	ATTRIBUTE_ACCESSORS(UPMAttributeSet, Wisdom);

	UPROPERTY(BlueprintReadOnly, Category = "Primary Attributes")
	FGameplayAttributeData Charisma;
	ATTRIBUTE_ACCESSORS(UPMAttributeSet, Charisma);
	
	/*
	 *Seconary Attributes
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Vital Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UPMAttributeSet, Health);
	
	UPROPERTY(BlueprintReadOnly, Category = "Vital Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UPMAttributeSet, MaxHealth);
	UPROPERTY(BlueprintReadOnly, Category = "Vital Attributes")
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(UPMAttributeSet, Stamina);
	UPROPERTY(BlueprintReadOnly, Category = "Vital Attributes")
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS(UPMAttributeSet, MaxStamina);

private:

	void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const;
};

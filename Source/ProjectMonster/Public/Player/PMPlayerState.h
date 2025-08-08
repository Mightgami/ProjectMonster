// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/PMAttributeSet.h"
#include "GameFramework/PlayerState.h"
#include "PMPlayerState.generated.h"

struct FGameplayTag;
class UAbilitySystemComponent;
class UPaperZDAnimInstance;
class UAttributeSet;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSwitchCharacter, TSubclassOf<UPaperZDAnimInstance>, PaperZDAnimInstance);

UCLASS()
class PROJECTMONSTER_API APMPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
public:
	APMPlayerState();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }
	
	TMap<FGameplayTag, FPartyMemberAttributes> PartyMembersAttributesMap;
	
	UPROPERTY(EditDefaultsOnly, Category="GAS|Characters")
	TArray<FGameplayTag> PartyOrderTags; // Ordine dinamico

	UPROPERTY()
	int32 CurrentMemberIndex;
	
	UPROPERTY(EditDefaultsOnly, Category="GAS|Characters")
	TSubclassOf<class UGameplayEffect> SetAttributesGEClass;

	UPROPERTY(EditDefaultsOnly, Category="GAS|Characters")
	TMap<FGameplayTag, TSubclassOf<UPaperZDAnimInstance>> PaperZDAnimInstanceMap;
	
	UFUNCTION(BlueprintCallable)
	void SwitchToPartyMember(int32 NewIndex);

	// Evento delegato che può essere assegnato in Blueprint
	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnSwitchCharacter OnSwitchCharacter;

protected:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
	
	virtual void BeginPlay() override;

	// Salva gli attributi correnti nel party map
	void SaveCurrentAttributes();

	// Carica gli attributi dal party map nel ASC usando GameplayEffect
	void LoadAttributesForTag(const FGameplayTag& MemberTag);

	// Aiuto per applicare il GameplayEffect con set by caller
	void ApplySetAttributesGE(const FPartyMemberAttributes& Attr) const;

	// Rimuove il tag active e rimuove il tag membro precedente
	void ClearActiveTags();

	// Aggiunge i tag per membro attivo
	void AddActiveTags(const FGameplayTag& MemberTag) const;

	// Notifica al character il cambio mesh/anim
	void NotifyCharacterSwitch(const FGameplayTag& MemberTag);


};

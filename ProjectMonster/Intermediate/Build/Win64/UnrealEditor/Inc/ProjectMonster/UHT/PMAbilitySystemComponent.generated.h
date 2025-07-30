// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AbilitySystem/PMAbilitySystemComponent.h"

#ifdef PROJECTMONSTER_PMAbilitySystemComponent_generated_h
#error "PMAbilitySystemComponent.generated.h already included, missing '#pragma once' in PMAbilitySystemComponent.h"
#endif
#define PROJECTMONSTER_PMAbilitySystemComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UPMAbilitySystemComponent ************************************************
PROJECTMONSTER_API UClass* Z_Construct_UClass_UPMAbilitySystemComponent_NoRegister();

#define FID_Git_ProjectMonster_Source_ProjectMonster_Public_AbilitySystem_PMAbilitySystemComponent_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPMAbilitySystemComponent(); \
	friend struct Z_Construct_UClass_UPMAbilitySystemComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PROJECTMONSTER_API UClass* Z_Construct_UClass_UPMAbilitySystemComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UPMAbilitySystemComponent, UAbilitySystemComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectMonster"), Z_Construct_UClass_UPMAbilitySystemComponent_NoRegister) \
	DECLARE_SERIALIZER(UPMAbilitySystemComponent)


#define FID_Git_ProjectMonster_Source_ProjectMonster_Public_AbilitySystem_PMAbilitySystemComponent_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPMAbilitySystemComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPMAbilitySystemComponent(UPMAbilitySystemComponent&&) = delete; \
	UPMAbilitySystemComponent(const UPMAbilitySystemComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPMAbilitySystemComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPMAbilitySystemComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPMAbilitySystemComponent) \
	NO_API virtual ~UPMAbilitySystemComponent();


#define FID_Git_ProjectMonster_Source_ProjectMonster_Public_AbilitySystem_PMAbilitySystemComponent_h_12_PROLOG
#define FID_Git_ProjectMonster_Source_ProjectMonster_Public_AbilitySystem_PMAbilitySystemComponent_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Git_ProjectMonster_Source_ProjectMonster_Public_AbilitySystem_PMAbilitySystemComponent_h_15_INCLASS_NO_PURE_DECLS \
	FID_Git_ProjectMonster_Source_ProjectMonster_Public_AbilitySystem_PMAbilitySystemComponent_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPMAbilitySystemComponent;

// ********** End Class UPMAbilitySystemComponent **************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Git_ProjectMonster_Source_ProjectMonster_Public_AbilitySystem_PMAbilitySystemComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS

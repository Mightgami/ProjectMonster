// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AbilitySystem/PMAttributeSet.h"

#ifdef PROJECTMONSTER_PMAttributeSet_generated_h
#error "PMAttributeSet.generated.h already included, missing '#pragma once' in PMAttributeSet.h"
#endif
#define PROJECTMONSTER_PMAttributeSet_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UPMAttributeSet **********************************************************
PROJECTMONSTER_API UClass* Z_Construct_UClass_UPMAttributeSet_NoRegister();

#define FID_Git_ProjectMonster_Source_ProjectMonster_Public_AbilitySystem_PMAttributeSet_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPMAttributeSet(); \
	friend struct Z_Construct_UClass_UPMAttributeSet_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PROJECTMONSTER_API UClass* Z_Construct_UClass_UPMAttributeSet_NoRegister(); \
public: \
	DECLARE_CLASS2(UPMAttributeSet, UAttributeSet, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ProjectMonster"), Z_Construct_UClass_UPMAttributeSet_NoRegister) \
	DECLARE_SERIALIZER(UPMAttributeSet)


#define FID_Git_ProjectMonster_Source_ProjectMonster_Public_AbilitySystem_PMAttributeSet_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPMAttributeSet(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPMAttributeSet(UPMAttributeSet&&) = delete; \
	UPMAttributeSet(const UPMAttributeSet&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPMAttributeSet); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPMAttributeSet); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPMAttributeSet) \
	NO_API virtual ~UPMAttributeSet();


#define FID_Git_ProjectMonster_Source_ProjectMonster_Public_AbilitySystem_PMAttributeSet_h_12_PROLOG
#define FID_Git_ProjectMonster_Source_ProjectMonster_Public_AbilitySystem_PMAttributeSet_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Git_ProjectMonster_Source_ProjectMonster_Public_AbilitySystem_PMAttributeSet_h_15_INCLASS_NO_PURE_DECLS \
	FID_Git_ProjectMonster_Source_ProjectMonster_Public_AbilitySystem_PMAttributeSet_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPMAttributeSet;

// ********** End Class UPMAttributeSet ************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Git_ProjectMonster_Source_ProjectMonster_Public_AbilitySystem_PMAttributeSet_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS

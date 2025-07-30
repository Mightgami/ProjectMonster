// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Player/PMPlayerState.h"

#ifdef PROJECTMONSTER_PMPlayerState_generated_h
#error "PMPlayerState.generated.h already included, missing '#pragma once' in PMPlayerState.h"
#endif
#define PROJECTMONSTER_PMPlayerState_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class APMPlayerState ***********************************************************
PROJECTMONSTER_API UClass* Z_Construct_UClass_APMPlayerState_NoRegister();

#define FID_Git_ProjectMonster_Source_ProjectMonster_Public_Player_PMPlayerState_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPMPlayerState(); \
	friend struct Z_Construct_UClass_APMPlayerState_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PROJECTMONSTER_API UClass* Z_Construct_UClass_APMPlayerState_NoRegister(); \
public: \
	DECLARE_CLASS2(APMPlayerState, APlayerState, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectMonster"), Z_Construct_UClass_APMPlayerState_NoRegister) \
	DECLARE_SERIALIZER(APMPlayerState)


#define FID_Git_ProjectMonster_Source_ProjectMonster_Public_Player_PMPlayerState_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APMPlayerState(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	APMPlayerState(APMPlayerState&&) = delete; \
	APMPlayerState(const APMPlayerState&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APMPlayerState); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APMPlayerState); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APMPlayerState) \
	NO_API virtual ~APMPlayerState();


#define FID_Git_ProjectMonster_Source_ProjectMonster_Public_Player_PMPlayerState_h_12_PROLOG
#define FID_Git_ProjectMonster_Source_ProjectMonster_Public_Player_PMPlayerState_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Git_ProjectMonster_Source_ProjectMonster_Public_Player_PMPlayerState_h_15_INCLASS_NO_PURE_DECLS \
	FID_Git_ProjectMonster_Source_ProjectMonster_Public_Player_PMPlayerState_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class APMPlayerState;

// ********** End Class APMPlayerState *************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Git_ProjectMonster_Source_ProjectMonster_Public_Player_PMPlayerState_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS

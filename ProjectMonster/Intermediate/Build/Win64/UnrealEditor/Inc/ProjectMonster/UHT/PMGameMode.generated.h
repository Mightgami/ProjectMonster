// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Game/PMGameMode.h"

#ifdef PROJECTMONSTER_PMGameMode_generated_h
#error "PMGameMode.generated.h already included, missing '#pragma once' in PMGameMode.h"
#endif
#define PROJECTMONSTER_PMGameMode_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class APMGameMode **************************************************************
PROJECTMONSTER_API UClass* Z_Construct_UClass_APMGameMode_NoRegister();

#define FID_Git_ProjectMonster_Source_ProjectMonster_Public_Game_PMGameMode_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPMGameMode(); \
	friend struct Z_Construct_UClass_APMGameMode_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PROJECTMONSTER_API UClass* Z_Construct_UClass_APMGameMode_NoRegister(); \
public: \
	DECLARE_CLASS2(APMGameMode, AGameMode, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectMonster"), Z_Construct_UClass_APMGameMode_NoRegister) \
	DECLARE_SERIALIZER(APMGameMode)


#define FID_Git_ProjectMonster_Source_ProjectMonster_Public_Game_PMGameMode_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APMGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	APMGameMode(APMGameMode&&) = delete; \
	APMGameMode(const APMGameMode&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APMGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APMGameMode); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APMGameMode) \
	NO_API virtual ~APMGameMode();


#define FID_Git_ProjectMonster_Source_ProjectMonster_Public_Game_PMGameMode_h_12_PROLOG
#define FID_Git_ProjectMonster_Source_ProjectMonster_Public_Game_PMGameMode_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Git_ProjectMonster_Source_ProjectMonster_Public_Game_PMGameMode_h_15_INCLASS_NO_PURE_DECLS \
	FID_Git_ProjectMonster_Source_ProjectMonster_Public_Game_PMGameMode_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class APMGameMode;

// ********** End Class APMGameMode ****************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Git_ProjectMonster_Source_ProjectMonster_Public_Game_PMGameMode_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS

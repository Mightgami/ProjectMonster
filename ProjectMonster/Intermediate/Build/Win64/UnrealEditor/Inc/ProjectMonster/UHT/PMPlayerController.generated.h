// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Player/PMPlayerController.h"

#ifdef PROJECTMONSTER_PMPlayerController_generated_h
#error "PMPlayerController.generated.h already included, missing '#pragma once' in PMPlayerController.h"
#endif
#define PROJECTMONSTER_PMPlayerController_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class APMPlayerController ******************************************************
PROJECTMONSTER_API UClass* Z_Construct_UClass_APMPlayerController_NoRegister();

#define FID_Git_ProjectMonster_Source_ProjectMonster_Public_Player_PMPlayerController_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPMPlayerController(); \
	friend struct Z_Construct_UClass_APMPlayerController_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PROJECTMONSTER_API UClass* Z_Construct_UClass_APMPlayerController_NoRegister(); \
public: \
	DECLARE_CLASS2(APMPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectMonster"), Z_Construct_UClass_APMPlayerController_NoRegister) \
	DECLARE_SERIALIZER(APMPlayerController)


#define FID_Git_ProjectMonster_Source_ProjectMonster_Public_Player_PMPlayerController_h_18_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APMPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	APMPlayerController(APMPlayerController&&) = delete; \
	APMPlayerController(const APMPlayerController&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APMPlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APMPlayerController); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APMPlayerController) \
	NO_API virtual ~APMPlayerController();


#define FID_Git_ProjectMonster_Source_ProjectMonster_Public_Player_PMPlayerController_h_15_PROLOG
#define FID_Git_ProjectMonster_Source_ProjectMonster_Public_Player_PMPlayerController_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Git_ProjectMonster_Source_ProjectMonster_Public_Player_PMPlayerController_h_18_INCLASS_NO_PURE_DECLS \
	FID_Git_ProjectMonster_Source_ProjectMonster_Public_Player_PMPlayerController_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class APMPlayerController;

// ********** End Class APMPlayerController ********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Git_ProjectMonster_Source_ProjectMonster_Public_Player_PMPlayerController_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS

// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Game/PMGameInstance.h"

#ifdef PROJECTMONSTER_PMGameInstance_generated_h
#error "PMGameInstance.generated.h already included, missing '#pragma once' in PMGameInstance.h"
#endif
#define PROJECTMONSTER_PMGameInstance_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UPMGameInstance **********************************************************
PROJECTMONSTER_API UClass* Z_Construct_UClass_UPMGameInstance_NoRegister();

#define FID_Git_ProjectMonster_Source_ProjectMonster_Public_Game_PMGameInstance_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPMGameInstance(); \
	friend struct Z_Construct_UClass_UPMGameInstance_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PROJECTMONSTER_API UClass* Z_Construct_UClass_UPMGameInstance_NoRegister(); \
public: \
	DECLARE_CLASS2(UPMGameInstance, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/ProjectMonster"), Z_Construct_UClass_UPMGameInstance_NoRegister) \
	DECLARE_SERIALIZER(UPMGameInstance)


#define FID_Git_ProjectMonster_Source_ProjectMonster_Public_Game_PMGameInstance_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPMGameInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPMGameInstance(UPMGameInstance&&) = delete; \
	UPMGameInstance(const UPMGameInstance&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPMGameInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPMGameInstance); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPMGameInstance) \
	NO_API virtual ~UPMGameInstance();


#define FID_Git_ProjectMonster_Source_ProjectMonster_Public_Game_PMGameInstance_h_12_PROLOG
#define FID_Git_ProjectMonster_Source_ProjectMonster_Public_Game_PMGameInstance_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Git_ProjectMonster_Source_ProjectMonster_Public_Game_PMGameInstance_h_15_INCLASS_NO_PURE_DECLS \
	FID_Git_ProjectMonster_Source_ProjectMonster_Public_Game_PMGameInstance_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPMGameInstance;

// ********** End Class UPMGameInstance ************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Git_ProjectMonster_Source_ProjectMonster_Public_Game_PMGameInstance_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS

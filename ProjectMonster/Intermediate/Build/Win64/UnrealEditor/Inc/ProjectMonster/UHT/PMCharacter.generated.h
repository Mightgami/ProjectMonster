// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Character/PMCharacter.h"

#ifdef PROJECTMONSTER_PMCharacter_generated_h
#error "PMCharacter.generated.h already included, missing '#pragma once' in PMCharacter.h"
#endif
#define PROJECTMONSTER_PMCharacter_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class APMCharacter *************************************************************
PROJECTMONSTER_API UClass* Z_Construct_UClass_APMCharacter_NoRegister();

#define FID_Git_ProjectMonster_Source_ProjectMonster_Public_Character_PMCharacter_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPMCharacter(); \
	friend struct Z_Construct_UClass_APMCharacter_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PROJECTMONSTER_API UClass* Z_Construct_UClass_APMCharacter_NoRegister(); \
public: \
	DECLARE_CLASS2(APMCharacter, APaperZDCharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectMonster"), Z_Construct_UClass_APMCharacter_NoRegister) \
	DECLARE_SERIALIZER(APMCharacter) \
	virtual UObject* _getUObject() const override { return const_cast<APMCharacter*>(this); }


#define FID_Git_ProjectMonster_Source_ProjectMonster_Public_Character_PMCharacter_h_20_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	APMCharacter(APMCharacter&&) = delete; \
	APMCharacter(const APMCharacter&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APMCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APMCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APMCharacter) \
	NO_API virtual ~APMCharacter();


#define FID_Git_ProjectMonster_Source_ProjectMonster_Public_Character_PMCharacter_h_17_PROLOG
#define FID_Git_ProjectMonster_Source_ProjectMonster_Public_Character_PMCharacter_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Git_ProjectMonster_Source_ProjectMonster_Public_Character_PMCharacter_h_20_INCLASS_NO_PURE_DECLS \
	FID_Git_ProjectMonster_Source_ProjectMonster_Public_Character_PMCharacter_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class APMCharacter;

// ********** End Class APMCharacter ***************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Git_ProjectMonster_Source_ProjectMonster_Public_Character_PMCharacter_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS

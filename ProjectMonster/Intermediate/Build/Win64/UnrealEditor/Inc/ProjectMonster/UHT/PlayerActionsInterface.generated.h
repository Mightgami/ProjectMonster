// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Interfaces/PlayerActionsInterface.h"

#ifdef PROJECTMONSTER_PlayerActionsInterface_generated_h
#error "PlayerActionsInterface.generated.h already included, missing '#pragma once' in PlayerActionsInterface.h"
#endif
#define PROJECTMONSTER_PlayerActionsInterface_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Interface UPlayerActionsInterface **********************************************
#define FID_Git_ProjectMonster_Source_ProjectMonster_Public_Interfaces_PlayerActionsInterface_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void Attack_Implementation() {}; \
	virtual void Jump_Implementation() {}; \
	virtual void Move_Implementation(FVector2D const& MovementVector) {}; \
	DECLARE_FUNCTION(execAttack); \
	DECLARE_FUNCTION(execJump); \
	DECLARE_FUNCTION(execMove);


#define FID_Git_ProjectMonster_Source_ProjectMonster_Public_Interfaces_PlayerActionsInterface_h_14_CALLBACK_WRAPPERS
PROJECTMONSTER_API UClass* Z_Construct_UClass_UPlayerActionsInterface_NoRegister();

#define FID_Git_ProjectMonster_Source_ProjectMonster_Public_Interfaces_PlayerActionsInterface_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	PROJECTMONSTER_API UPlayerActionsInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPlayerActionsInterface(UPlayerActionsInterface&&) = delete; \
	UPlayerActionsInterface(const UPlayerActionsInterface&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(PROJECTMONSTER_API, UPlayerActionsInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPlayerActionsInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPlayerActionsInterface) \
	virtual ~UPlayerActionsInterface() = default;


#define FID_Git_ProjectMonster_Source_ProjectMonster_Public_Interfaces_PlayerActionsInterface_h_14_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUPlayerActionsInterface(); \
	friend struct Z_Construct_UClass_UPlayerActionsInterface_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PROJECTMONSTER_API UClass* Z_Construct_UClass_UPlayerActionsInterface_NoRegister(); \
public: \
	DECLARE_CLASS2(UPlayerActionsInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/ProjectMonster"), Z_Construct_UClass_UPlayerActionsInterface_NoRegister) \
	DECLARE_SERIALIZER(UPlayerActionsInterface)


#define FID_Git_ProjectMonster_Source_ProjectMonster_Public_Interfaces_PlayerActionsInterface_h_14_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Git_ProjectMonster_Source_ProjectMonster_Public_Interfaces_PlayerActionsInterface_h_14_GENERATED_UINTERFACE_BODY() \
	FID_Git_ProjectMonster_Source_ProjectMonster_Public_Interfaces_PlayerActionsInterface_h_14_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Git_ProjectMonster_Source_ProjectMonster_Public_Interfaces_PlayerActionsInterface_h_14_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IPlayerActionsInterface() {} \
public: \
	typedef UPlayerActionsInterface UClassType; \
	typedef IPlayerActionsInterface ThisClass; \
	static void Execute_Attack(UObject* O); \
	static void Execute_Jump(UObject* O); \
	static void Execute_Move(UObject* O, FVector2D const& MovementVector); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Git_ProjectMonster_Source_ProjectMonster_Public_Interfaces_PlayerActionsInterface_h_11_PROLOG
#define FID_Git_ProjectMonster_Source_ProjectMonster_Public_Interfaces_PlayerActionsInterface_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Git_ProjectMonster_Source_ProjectMonster_Public_Interfaces_PlayerActionsInterface_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Git_ProjectMonster_Source_ProjectMonster_Public_Interfaces_PlayerActionsInterface_h_14_CALLBACK_WRAPPERS \
	FID_Git_ProjectMonster_Source_ProjectMonster_Public_Interfaces_PlayerActionsInterface_h_14_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPlayerActionsInterface;

// ********** End Interface UPlayerActionsInterface ************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Git_ProjectMonster_Source_ProjectMonster_Public_Interfaces_PlayerActionsInterface_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS

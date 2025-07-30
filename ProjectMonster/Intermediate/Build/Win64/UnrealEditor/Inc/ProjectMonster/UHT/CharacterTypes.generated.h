// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Character/CharacterTypes.h"

#ifdef PROJECTMONSTER_CharacterTypes_generated_h
#error "CharacterTypes.generated.h already included, missing '#pragma once' in CharacterTypes.h"
#endif
#define PROJECTMONSTER_CharacterTypes_generated_h

#include "Templates/IsUEnumClass.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Git_ProjectMonster_Source_ProjectMonster_Public_Character_CharacterTypes_h

// ********** Begin Enum EActionState **************************************************************
#define FOREACH_ENUM_EACTIONSTATE(op) \
	op(EActionState::EAS_Unoccupied) \
	op(EActionState::EAS_Attacking) 

enum class EActionState : uint8;
template<> struct TIsUEnumClass<EActionState> { enum { Value = true }; };
template<> PROJECTMONSTER_API UEnum* StaticEnum<EActionState>();
// ********** End Enum EActionState ****************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS

// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Character/PMCharacter.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodePMCharacter() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
PAPERZD_API UClass* Z_Construct_UClass_APaperZDCharacter();
PROJECTMONSTER_API UClass* Z_Construct_UClass_APMCharacter();
PROJECTMONSTER_API UClass* Z_Construct_UClass_APMCharacter_NoRegister();
PROJECTMONSTER_API UClass* Z_Construct_UClass_UAttackEndInterface_NoRegister();
PROJECTMONSTER_API UClass* Z_Construct_UClass_UPlayerActionsInterface_NoRegister();
PROJECTMONSTER_API UEnum* Z_Construct_UEnum_ProjectMonster_EActionState();
UPackage* Z_Construct_UPackage__Script_ProjectMonster();
// ********** End Cross Module References **********************************************************

// ********** Begin Class APMCharacter *************************************************************
void APMCharacter::StaticRegisterNativesAPMCharacter()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_APMCharacter;
UClass* APMCharacter::GetPrivateStaticClass()
{
	using TClass = APMCharacter;
	if (!Z_Registration_Info_UClass_APMCharacter.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("PMCharacter"),
			Z_Registration_Info_UClass_APMCharacter.InnerSingleton,
			StaticRegisterNativesAPMCharacter,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_APMCharacter.InnerSingleton;
}
UClass* Z_Construct_UClass_APMCharacter_NoRegister()
{
	return APMCharacter::GetPrivateStaticClass();
}
struct Z_Construct_UClass_APMCharacter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *\n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Character/PMCharacter.h" },
		{ "ModuleRelativePath", "Public/Character/PMCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[] = {
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Spring arm to offset the camera from the character */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Character/PMCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Spring arm to offset the camera from the character" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FollowCamera_MetaData[] = {
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Camera that follows the character */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Character/PMCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Camera that follows the character" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentState_MetaData[] = {
		{ "Category", "Character State" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Stato attuale del personaggio\n" },
#endif
		{ "ModuleRelativePath", "Public/Character/PMCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Stato attuale del personaggio" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraBoom;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FollowCamera;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CurrentState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_CurrentState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APMCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APMCharacter_Statics::NewProp_CameraBoom = { "CameraBoom", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APMCharacter, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraBoom_MetaData), NewProp_CameraBoom_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APMCharacter_Statics::NewProp_FollowCamera = { "FollowCamera", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APMCharacter, FollowCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FollowCamera_MetaData), NewProp_FollowCamera_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_APMCharacter_Statics::NewProp_CurrentState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_APMCharacter_Statics::NewProp_CurrentState = { "CurrentState", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APMCharacter, CurrentState), Z_Construct_UEnum_ProjectMonster_EActionState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentState_MetaData), NewProp_CurrentState_MetaData) }; // 1644827099
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APMCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APMCharacter_Statics::NewProp_CameraBoom,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APMCharacter_Statics::NewProp_FollowCamera,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APMCharacter_Statics::NewProp_CurrentState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APMCharacter_Statics::NewProp_CurrentState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APMCharacter_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_APMCharacter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APaperZDCharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_ProjectMonster,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APMCharacter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_APMCharacter_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UPlayerActionsInterface_NoRegister, (int32)VTABLE_OFFSET(APMCharacter, IPlayerActionsInterface), false },  // 4223796920
	{ Z_Construct_UClass_UAttackEndInterface_NoRegister, (int32)VTABLE_OFFSET(APMCharacter, IAttackEndInterface), false },  // 3262056511
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_APMCharacter_Statics::ClassParams = {
	&APMCharacter::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_APMCharacter_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_APMCharacter_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x009001A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APMCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_APMCharacter_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_APMCharacter()
{
	if (!Z_Registration_Info_UClass_APMCharacter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APMCharacter.OuterSingleton, Z_Construct_UClass_APMCharacter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_APMCharacter.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(APMCharacter);
APMCharacter::~APMCharacter() {}
// ********** End Class APMCharacter ***************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Git_ProjectMonster_Source_ProjectMonster_Public_Character_PMCharacter_h__Script_ProjectMonster_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_APMCharacter, APMCharacter::StaticClass, TEXT("APMCharacter"), &Z_Registration_Info_UClass_APMCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APMCharacter), 1344880357U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_ProjectMonster_Source_ProjectMonster_Public_Character_PMCharacter_h__Script_ProjectMonster_3094739498(TEXT("/Script/ProjectMonster"),
	Z_CompiledInDeferFile_FID_Git_ProjectMonster_Source_ProjectMonster_Public_Character_PMCharacter_h__Script_ProjectMonster_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_ProjectMonster_Source_ProjectMonster_Public_Character_PMCharacter_h__Script_ProjectMonster_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS

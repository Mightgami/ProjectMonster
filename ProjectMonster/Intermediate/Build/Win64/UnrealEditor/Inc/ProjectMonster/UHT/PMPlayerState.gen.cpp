// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Player/PMPlayerState.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodePMPlayerState() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_APlayerState();
PROJECTMONSTER_API UClass* Z_Construct_UClass_APMPlayerState();
PROJECTMONSTER_API UClass* Z_Construct_UClass_APMPlayerState_NoRegister();
UPackage* Z_Construct_UPackage__Script_ProjectMonster();
// ********** End Cross Module References **********************************************************

// ********** Begin Class APMPlayerState ***********************************************************
void APMPlayerState::StaticRegisterNativesAPMPlayerState()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_APMPlayerState;
UClass* APMPlayerState::GetPrivateStaticClass()
{
	using TClass = APMPlayerState;
	if (!Z_Registration_Info_UClass_APMPlayerState.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("PMPlayerState"),
			Z_Registration_Info_UClass_APMPlayerState.InnerSingleton,
			StaticRegisterNativesAPMPlayerState,
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
	return Z_Registration_Info_UClass_APMPlayerState.InnerSingleton;
}
UClass* Z_Construct_UClass_APMPlayerState_NoRegister()
{
	return APMPlayerState::GetPrivateStaticClass();
}
struct Z_Construct_UClass_APMPlayerState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "Player/PMPlayerState.h" },
		{ "ModuleRelativePath", "Public/Player/PMPlayerState.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APMPlayerState>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_APMPlayerState_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerState,
	(UObject* (*)())Z_Construct_UPackage__Script_ProjectMonster,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APMPlayerState_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_APMPlayerState_Statics::ClassParams = {
	&APMPlayerState::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009003A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APMPlayerState_Statics::Class_MetaDataParams), Z_Construct_UClass_APMPlayerState_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_APMPlayerState()
{
	if (!Z_Registration_Info_UClass_APMPlayerState.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APMPlayerState.OuterSingleton, Z_Construct_UClass_APMPlayerState_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_APMPlayerState.OuterSingleton;
}
APMPlayerState::APMPlayerState(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(APMPlayerState);
APMPlayerState::~APMPlayerState() {}
// ********** End Class APMPlayerState *************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Git_ProjectMonster_Source_ProjectMonster_Public_Player_PMPlayerState_h__Script_ProjectMonster_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_APMPlayerState, APMPlayerState::StaticClass, TEXT("APMPlayerState"), &Z_Registration_Info_UClass_APMPlayerState, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APMPlayerState), 4126048690U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_ProjectMonster_Source_ProjectMonster_Public_Player_PMPlayerState_h__Script_ProjectMonster_4275925913(TEXT("/Script/ProjectMonster"),
	Z_CompiledInDeferFile_FID_Git_ProjectMonster_Source_ProjectMonster_Public_Player_PMPlayerState_h__Script_ProjectMonster_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_ProjectMonster_Source_ProjectMonster_Public_Player_PMPlayerState_h__Script_ProjectMonster_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS

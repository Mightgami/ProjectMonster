// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Game/PMGameInstance.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodePMGameInstance() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UGameInstance();
PROJECTMONSTER_API UClass* Z_Construct_UClass_UPMGameInstance();
PROJECTMONSTER_API UClass* Z_Construct_UClass_UPMGameInstance_NoRegister();
UPackage* Z_Construct_UPackage__Script_ProjectMonster();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UPMGameInstance **********************************************************
void UPMGameInstance::StaticRegisterNativesUPMGameInstance()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UPMGameInstance;
UClass* UPMGameInstance::GetPrivateStaticClass()
{
	using TClass = UPMGameInstance;
	if (!Z_Registration_Info_UClass_UPMGameInstance.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("PMGameInstance"),
			Z_Registration_Info_UClass_UPMGameInstance.InnerSingleton,
			StaticRegisterNativesUPMGameInstance,
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
	return Z_Registration_Info_UClass_UPMGameInstance.InnerSingleton;
}
UClass* Z_Construct_UClass_UPMGameInstance_NoRegister()
{
	return UPMGameInstance::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UPMGameInstance_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Game/PMGameInstance.h" },
		{ "ModuleRelativePath", "Public/Game/PMGameInstance.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPMGameInstance>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UPMGameInstance_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstance,
	(UObject* (*)())Z_Construct_UPackage__Script_ProjectMonster,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPMGameInstance_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UPMGameInstance_Statics::ClassParams = {
	&UPMGameInstance::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009000A8u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPMGameInstance_Statics::Class_MetaDataParams), Z_Construct_UClass_UPMGameInstance_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UPMGameInstance()
{
	if (!Z_Registration_Info_UClass_UPMGameInstance.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPMGameInstance.OuterSingleton, Z_Construct_UClass_UPMGameInstance_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UPMGameInstance.OuterSingleton;
}
UPMGameInstance::UPMGameInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UPMGameInstance);
UPMGameInstance::~UPMGameInstance() {}
// ********** End Class UPMGameInstance ************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Git_ProjectMonster_Source_ProjectMonster_Public_Game_PMGameInstance_h__Script_ProjectMonster_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UPMGameInstance, UPMGameInstance::StaticClass, TEXT("UPMGameInstance"), &Z_Registration_Info_UClass_UPMGameInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPMGameInstance), 403360096U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_ProjectMonster_Source_ProjectMonster_Public_Game_PMGameInstance_h__Script_ProjectMonster_409710464(TEXT("/Script/ProjectMonster"),
	Z_CompiledInDeferFile_FID_Git_ProjectMonster_Source_ProjectMonster_Public_Game_PMGameInstance_h__Script_ProjectMonster_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_ProjectMonster_Source_ProjectMonster_Public_Game_PMGameInstance_h__Script_ProjectMonster_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS

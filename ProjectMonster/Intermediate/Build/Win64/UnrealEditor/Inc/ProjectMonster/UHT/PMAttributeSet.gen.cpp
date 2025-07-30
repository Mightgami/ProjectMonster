// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AbilitySystem/PMAttributeSet.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodePMAttributeSet() {}

// ********** Begin Cross Module References ********************************************************
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAttributeSet();
PROJECTMONSTER_API UClass* Z_Construct_UClass_UPMAttributeSet();
PROJECTMONSTER_API UClass* Z_Construct_UClass_UPMAttributeSet_NoRegister();
UPackage* Z_Construct_UPackage__Script_ProjectMonster();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UPMAttributeSet **********************************************************
void UPMAttributeSet::StaticRegisterNativesUPMAttributeSet()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UPMAttributeSet;
UClass* UPMAttributeSet::GetPrivateStaticClass()
{
	using TClass = UPMAttributeSet;
	if (!Z_Registration_Info_UClass_UPMAttributeSet.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("PMAttributeSet"),
			Z_Registration_Info_UClass_UPMAttributeSet.InnerSingleton,
			StaticRegisterNativesUPMAttributeSet,
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
	return Z_Registration_Info_UClass_UPMAttributeSet.InnerSingleton;
}
UClass* Z_Construct_UClass_UPMAttributeSet_NoRegister()
{
	return UPMAttributeSet::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UPMAttributeSet_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "AbilitySystem/PMAttributeSet.h" },
		{ "ModuleRelativePath", "Public/AbilitySystem/PMAttributeSet.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPMAttributeSet>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UPMAttributeSet_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAttributeSet,
	(UObject* (*)())Z_Construct_UPackage__Script_ProjectMonster,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPMAttributeSet_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UPMAttributeSet_Statics::ClassParams = {
	&UPMAttributeSet::StaticClass,
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
	0x003000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPMAttributeSet_Statics::Class_MetaDataParams), Z_Construct_UClass_UPMAttributeSet_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UPMAttributeSet()
{
	if (!Z_Registration_Info_UClass_UPMAttributeSet.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPMAttributeSet.OuterSingleton, Z_Construct_UClass_UPMAttributeSet_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UPMAttributeSet.OuterSingleton;
}
UPMAttributeSet::UPMAttributeSet(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UPMAttributeSet);
UPMAttributeSet::~UPMAttributeSet() {}
// ********** End Class UPMAttributeSet ************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Git_ProjectMonster_Source_ProjectMonster_Public_AbilitySystem_PMAttributeSet_h__Script_ProjectMonster_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UPMAttributeSet, UPMAttributeSet::StaticClass, TEXT("UPMAttributeSet"), &Z_Registration_Info_UClass_UPMAttributeSet, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPMAttributeSet), 1854782137U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_ProjectMonster_Source_ProjectMonster_Public_AbilitySystem_PMAttributeSet_h__Script_ProjectMonster_2213943711(TEXT("/Script/ProjectMonster"),
	Z_CompiledInDeferFile_FID_Git_ProjectMonster_Source_ProjectMonster_Public_AbilitySystem_PMAttributeSet_h__Script_ProjectMonster_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_ProjectMonster_Source_ProjectMonster_Public_AbilitySystem_PMAttributeSet_h__Script_ProjectMonster_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS

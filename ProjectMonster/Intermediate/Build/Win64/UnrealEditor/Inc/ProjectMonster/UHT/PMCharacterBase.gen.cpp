// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Character/PMCharacterBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodePMCharacterBase() {}

// ********** Begin Cross Module References ********************************************************
PAPERZD_API UClass* Z_Construct_UClass_APaperZDCharacter();
PROJECTMONSTER_API UClass* Z_Construct_UClass_APMCharacterBase();
PROJECTMONSTER_API UClass* Z_Construct_UClass_APMCharacterBase_NoRegister();
UPackage* Z_Construct_UPackage__Script_ProjectMonster();
// ********** End Cross Module References **********************************************************

// ********** Begin Class APMCharacterBase *********************************************************
void APMCharacterBase::StaticRegisterNativesAPMCharacterBase()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_APMCharacterBase;
UClass* APMCharacterBase::GetPrivateStaticClass()
{
	using TClass = APMCharacterBase;
	if (!Z_Registration_Info_UClass_APMCharacterBase.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("PMCharacterBase"),
			Z_Registration_Info_UClass_APMCharacterBase.InnerSingleton,
			StaticRegisterNativesAPMCharacterBase,
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
	return Z_Registration_Info_UClass_APMCharacterBase.InnerSingleton;
}
UClass* Z_Construct_UClass_APMCharacterBase_NoRegister()
{
	return APMCharacterBase::GetPrivateStaticClass();
}
struct Z_Construct_UClass_APMCharacterBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Character/PMCharacterBase.h" },
		{ "ModuleRelativePath", "Public/Character/PMCharacterBase.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APMCharacterBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_APMCharacterBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APaperZDCharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_ProjectMonster,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APMCharacterBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_APMCharacterBase_Statics::ClassParams = {
	&APMCharacterBase::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009001A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APMCharacterBase_Statics::Class_MetaDataParams), Z_Construct_UClass_APMCharacterBase_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_APMCharacterBase()
{
	if (!Z_Registration_Info_UClass_APMCharacterBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APMCharacterBase.OuterSingleton, Z_Construct_UClass_APMCharacterBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_APMCharacterBase.OuterSingleton;
}
APMCharacterBase::APMCharacterBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(APMCharacterBase);
APMCharacterBase::~APMCharacterBase() {}
// ********** End Class APMCharacterBase ***********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Git_ProjectMonster_Source_ProjectMonster_Public_Character_PMCharacterBase_h__Script_ProjectMonster_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_APMCharacterBase, APMCharacterBase::StaticClass, TEXT("APMCharacterBase"), &Z_Registration_Info_UClass_APMCharacterBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APMCharacterBase), 642091812U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_ProjectMonster_Source_ProjectMonster_Public_Character_PMCharacterBase_h__Script_ProjectMonster_1914408186(TEXT("/Script/ProjectMonster"),
	Z_CompiledInDeferFile_FID_Git_ProjectMonster_Source_ProjectMonster_Public_Character_PMCharacterBase_h__Script_ProjectMonster_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_ProjectMonster_Source_ProjectMonster_Public_Character_PMCharacterBase_h__Script_ProjectMonster_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS

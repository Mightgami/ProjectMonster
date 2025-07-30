// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AbilitySystem/PMAbilitySystemComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodePMAbilitySystemComponent() {}

// ********** Begin Cross Module References ********************************************************
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAbilitySystemComponent();
PROJECTMONSTER_API UClass* Z_Construct_UClass_UPMAbilitySystemComponent();
PROJECTMONSTER_API UClass* Z_Construct_UClass_UPMAbilitySystemComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_ProjectMonster();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UPMAbilitySystemComponent ************************************************
void UPMAbilitySystemComponent::StaticRegisterNativesUPMAbilitySystemComponent()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UPMAbilitySystemComponent;
UClass* UPMAbilitySystemComponent::GetPrivateStaticClass()
{
	using TClass = UPMAbilitySystemComponent;
	if (!Z_Registration_Info_UClass_UPMAbilitySystemComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("PMAbilitySystemComponent"),
			Z_Registration_Info_UClass_UPMAbilitySystemComponent.InnerSingleton,
			StaticRegisterNativesUPMAbilitySystemComponent,
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
	return Z_Registration_Info_UClass_UPMAbilitySystemComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UPMAbilitySystemComponent_NoRegister()
{
	return UPMAbilitySystemComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UPMAbilitySystemComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Object LOD Lighting Transform Sockets TextureStreaming Object LOD Lighting Transform Sockets TextureStreaming" },
		{ "IncludePath", "AbilitySystem/PMAbilitySystemComponent.h" },
		{ "ModuleRelativePath", "Public/AbilitySystem/PMAbilitySystemComponent.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPMAbilitySystemComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UPMAbilitySystemComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAbilitySystemComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_ProjectMonster,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPMAbilitySystemComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UPMAbilitySystemComponent_Statics::ClassParams = {
	&UPMAbilitySystemComponent::StaticClass,
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
	0x00B010A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPMAbilitySystemComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UPMAbilitySystemComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UPMAbilitySystemComponent()
{
	if (!Z_Registration_Info_UClass_UPMAbilitySystemComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPMAbilitySystemComponent.OuterSingleton, Z_Construct_UClass_UPMAbilitySystemComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UPMAbilitySystemComponent.OuterSingleton;
}
UPMAbilitySystemComponent::UPMAbilitySystemComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UPMAbilitySystemComponent);
UPMAbilitySystemComponent::~UPMAbilitySystemComponent() {}
// ********** End Class UPMAbilitySystemComponent **************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Git_ProjectMonster_Source_ProjectMonster_Public_AbilitySystem_PMAbilitySystemComponent_h__Script_ProjectMonster_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UPMAbilitySystemComponent, UPMAbilitySystemComponent::StaticClass, TEXT("UPMAbilitySystemComponent"), &Z_Registration_Info_UClass_UPMAbilitySystemComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPMAbilitySystemComponent), 3406469740U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_ProjectMonster_Source_ProjectMonster_Public_AbilitySystem_PMAbilitySystemComponent_h__Script_ProjectMonster_2607950060(TEXT("/Script/ProjectMonster"),
	Z_CompiledInDeferFile_FID_Git_ProjectMonster_Source_ProjectMonster_Public_AbilitySystem_PMAbilitySystemComponent_h__Script_ProjectMonster_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_ProjectMonster_Source_ProjectMonster_Public_AbilitySystem_PMAbilitySystemComponent_h__Script_ProjectMonster_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS

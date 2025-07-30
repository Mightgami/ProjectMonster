// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Interfaces/AttackEndInterface.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeAttackEndInterface() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
PROJECTMONSTER_API UClass* Z_Construct_UClass_UAttackEndInterface();
PROJECTMONSTER_API UClass* Z_Construct_UClass_UAttackEndInterface_NoRegister();
UPackage* Z_Construct_UPackage__Script_ProjectMonster();
// ********** End Cross Module References **********************************************************

// ********** Begin Interface UAttackEndInterface Function EndAttack *******************************
void IAttackEndInterface::EndAttack()
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_EndAttack instead.");
}
static FName NAME_UAttackEndInterface_EndAttack = FName(TEXT("EndAttack"));
void IAttackEndInterface::Execute_EndAttack(UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UAttackEndInterface::StaticClass()));
	UFunction* const Func = O->FindFunction(NAME_UAttackEndInterface_EndAttack);
	if (Func)
	{
		O->ProcessEvent(Func, NULL);
	}
	else if (auto I = (IAttackEndInterface*)(O->GetNativeInterfaceAddress(UAttackEndInterface::StaticClass())))
	{
		I->EndAttack_Implementation();
	}
}
struct Z_Construct_UFunction_UAttackEndInterface_EndAttack_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "EndAttack" },
		{ "ModuleRelativePath", "Public/Interfaces/AttackEndInterface.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAttackEndInterface_EndAttack_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAttackEndInterface, nullptr, "EndAttack", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAttackEndInterface_EndAttack_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAttackEndInterface_EndAttack_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UAttackEndInterface_EndAttack()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAttackEndInterface_EndAttack_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IAttackEndInterface::execEndAttack)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->EndAttack_Implementation();
	P_NATIVE_END;
}
// ********** End Interface UAttackEndInterface Function EndAttack *********************************

// ********** Begin Interface UAttackEndInterface **************************************************
void UAttackEndInterface::StaticRegisterNativesUAttackEndInterface()
{
	UClass* Class = UAttackEndInterface::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "EndAttack", &IAttackEndInterface::execEndAttack },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UAttackEndInterface;
UClass* UAttackEndInterface::GetPrivateStaticClass()
{
	using TClass = UAttackEndInterface;
	if (!Z_Registration_Info_UClass_UAttackEndInterface.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("AttackEndInterface"),
			Z_Registration_Info_UClass_UAttackEndInterface.InnerSingleton,
			StaticRegisterNativesUAttackEndInterface,
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
	return Z_Registration_Info_UClass_UAttackEndInterface.InnerSingleton;
}
UClass* Z_Construct_UClass_UAttackEndInterface_NoRegister()
{
	return UAttackEndInterface::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UAttackEndInterface_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Interfaces/AttackEndInterface.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UAttackEndInterface_EndAttack, "EndAttack" }, // 3721971352
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IAttackEndInterface>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UAttackEndInterface_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_ProjectMonster,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAttackEndInterface_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAttackEndInterface_Statics::ClassParams = {
	&UAttackEndInterface::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x000840A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAttackEndInterface_Statics::Class_MetaDataParams), Z_Construct_UClass_UAttackEndInterface_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UAttackEndInterface()
{
	if (!Z_Registration_Info_UClass_UAttackEndInterface.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAttackEndInterface.OuterSingleton, Z_Construct_UClass_UAttackEndInterface_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAttackEndInterface.OuterSingleton;
}
UAttackEndInterface::UAttackEndInterface(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UAttackEndInterface);
// ********** End Interface UAttackEndInterface ****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Git_ProjectMonster_Source_ProjectMonster_Public_Interfaces_AttackEndInterface_h__Script_ProjectMonster_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAttackEndInterface, UAttackEndInterface::StaticClass, TEXT("UAttackEndInterface"), &Z_Registration_Info_UClass_UAttackEndInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAttackEndInterface), 3262056511U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_ProjectMonster_Source_ProjectMonster_Public_Interfaces_AttackEndInterface_h__Script_ProjectMonster_139275985(TEXT("/Script/ProjectMonster"),
	Z_CompiledInDeferFile_FID_Git_ProjectMonster_Source_ProjectMonster_Public_Interfaces_AttackEndInterface_h__Script_ProjectMonster_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_ProjectMonster_Source_ProjectMonster_Public_Interfaces_AttackEndInterface_h__Script_ProjectMonster_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS

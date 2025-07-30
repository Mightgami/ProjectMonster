// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Interfaces/PlayerActionsInterface.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodePlayerActionsInterface() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
PROJECTMONSTER_API UClass* Z_Construct_UClass_UPlayerActionsInterface();
PROJECTMONSTER_API UClass* Z_Construct_UClass_UPlayerActionsInterface_NoRegister();
UPackage* Z_Construct_UPackage__Script_ProjectMonster();
// ********** End Cross Module References **********************************************************

// ********** Begin Interface UPlayerActionsInterface Function Attack ******************************
void IPlayerActionsInterface::Attack()
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_Attack instead.");
}
static FName NAME_UPlayerActionsInterface_Attack = FName(TEXT("Attack"));
void IPlayerActionsInterface::Execute_Attack(UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UPlayerActionsInterface::StaticClass()));
	UFunction* const Func = O->FindFunction(NAME_UPlayerActionsInterface_Attack);
	if (Func)
	{
		O->ProcessEvent(Func, NULL);
	}
	else if (auto I = (IPlayerActionsInterface*)(O->GetNativeInterfaceAddress(UPlayerActionsInterface::StaticClass())))
	{
		I->Attack_Implementation();
	}
}
struct Z_Construct_UFunction_UPlayerActionsInterface_Attack_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Attacco\n" },
#endif
		{ "ModuleRelativePath", "Public/Interfaces/PlayerActionsInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Attacco" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPlayerActionsInterface_Attack_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPlayerActionsInterface, nullptr, "Attack", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlayerActionsInterface_Attack_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPlayerActionsInterface_Attack_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UPlayerActionsInterface_Attack()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPlayerActionsInterface_Attack_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IPlayerActionsInterface::execAttack)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Attack_Implementation();
	P_NATIVE_END;
}
// ********** End Interface UPlayerActionsInterface Function Attack ********************************

// ********** Begin Interface UPlayerActionsInterface Function Jump ********************************
void IPlayerActionsInterface::Jump()
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_Jump instead.");
}
static FName NAME_UPlayerActionsInterface_Jump = FName(TEXT("Jump"));
void IPlayerActionsInterface::Execute_Jump(UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UPlayerActionsInterface::StaticClass()));
	UFunction* const Func = O->FindFunction(NAME_UPlayerActionsInterface_Jump);
	if (Func)
	{
		O->ProcessEvent(Func, NULL);
	}
	else if (auto I = (IPlayerActionsInterface*)(O->GetNativeInterfaceAddress(UPlayerActionsInterface::StaticClass())))
	{
		I->Jump_Implementation();
	}
}
struct Z_Construct_UFunction_UPlayerActionsInterface_Jump_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Salto\n" },
#endif
		{ "ModuleRelativePath", "Public/Interfaces/PlayerActionsInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Salto" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPlayerActionsInterface_Jump_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPlayerActionsInterface, nullptr, "Jump", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlayerActionsInterface_Jump_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPlayerActionsInterface_Jump_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UPlayerActionsInterface_Jump()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPlayerActionsInterface_Jump_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IPlayerActionsInterface::execJump)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Jump_Implementation();
	P_NATIVE_END;
}
// ********** End Interface UPlayerActionsInterface Function Jump **********************************

// ********** Begin Interface UPlayerActionsInterface Function Move ********************************
struct PlayerActionsInterface_eventMove_Parms
{
	FVector2D MovementVector;
};
void IPlayerActionsInterface::Move(FVector2D const& MovementVector)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_Move instead.");
}
static FName NAME_UPlayerActionsInterface_Move = FName(TEXT("Move"));
void IPlayerActionsInterface::Execute_Move(UObject* O, FVector2D const& MovementVector)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UPlayerActionsInterface::StaticClass()));
	PlayerActionsInterface_eventMove_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UPlayerActionsInterface_Move);
	if (Func)
	{
		Parms.MovementVector=MovementVector;
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (IPlayerActionsInterface*)(O->GetNativeInterfaceAddress(UPlayerActionsInterface::StaticClass())))
	{
		I->Move_Implementation(MovementVector);
	}
}
struct Z_Construct_UFunction_UPlayerActionsInterface_Move_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Movimento, input vettore 2D\n" },
#endif
		{ "ModuleRelativePath", "Public/Interfaces/PlayerActionsInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Movimento, input vettore 2D" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MovementVector_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_MovementVector;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPlayerActionsInterface_Move_Statics::NewProp_MovementVector = { "MovementVector", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PlayerActionsInterface_eventMove_Parms, MovementVector), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MovementVector_MetaData), NewProp_MovementVector_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPlayerActionsInterface_Move_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPlayerActionsInterface_Move_Statics::NewProp_MovementVector,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlayerActionsInterface_Move_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPlayerActionsInterface_Move_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPlayerActionsInterface, nullptr, "Move", Z_Construct_UFunction_UPlayerActionsInterface_Move_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPlayerActionsInterface_Move_Statics::PropPointers), sizeof(PlayerActionsInterface_eventMove_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0CC20C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlayerActionsInterface_Move_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPlayerActionsInterface_Move_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(PlayerActionsInterface_eventMove_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPlayerActionsInterface_Move()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPlayerActionsInterface_Move_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IPlayerActionsInterface::execMove)
{
	P_GET_STRUCT_REF(FVector2D,Z_Param_Out_MovementVector);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Move_Implementation(Z_Param_Out_MovementVector);
	P_NATIVE_END;
}
// ********** End Interface UPlayerActionsInterface Function Move **********************************

// ********** Begin Interface UPlayerActionsInterface **********************************************
void UPlayerActionsInterface::StaticRegisterNativesUPlayerActionsInterface()
{
	UClass* Class = UPlayerActionsInterface::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "Attack", &IPlayerActionsInterface::execAttack },
		{ "Jump", &IPlayerActionsInterface::execJump },
		{ "Move", &IPlayerActionsInterface::execMove },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UPlayerActionsInterface;
UClass* UPlayerActionsInterface::GetPrivateStaticClass()
{
	using TClass = UPlayerActionsInterface;
	if (!Z_Registration_Info_UClass_UPlayerActionsInterface.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("PlayerActionsInterface"),
			Z_Registration_Info_UClass_UPlayerActionsInterface.InnerSingleton,
			StaticRegisterNativesUPlayerActionsInterface,
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
	return Z_Registration_Info_UClass_UPlayerActionsInterface.InnerSingleton;
}
UClass* Z_Construct_UClass_UPlayerActionsInterface_NoRegister()
{
	return UPlayerActionsInterface::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UPlayerActionsInterface_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Interfaces/PlayerActionsInterface.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UPlayerActionsInterface_Attack, "Attack" }, // 435323858
		{ &Z_Construct_UFunction_UPlayerActionsInterface_Jump, "Jump" }, // 3850157520
		{ &Z_Construct_UFunction_UPlayerActionsInterface_Move, "Move" }, // 1292739668
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IPlayerActionsInterface>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UPlayerActionsInterface_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_ProjectMonster,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerActionsInterface_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UPlayerActionsInterface_Statics::ClassParams = {
	&UPlayerActionsInterface::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerActionsInterface_Statics::Class_MetaDataParams), Z_Construct_UClass_UPlayerActionsInterface_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UPlayerActionsInterface()
{
	if (!Z_Registration_Info_UClass_UPlayerActionsInterface.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPlayerActionsInterface.OuterSingleton, Z_Construct_UClass_UPlayerActionsInterface_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UPlayerActionsInterface.OuterSingleton;
}
UPlayerActionsInterface::UPlayerActionsInterface(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UPlayerActionsInterface);
// ********** End Interface UPlayerActionsInterface ************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Git_ProjectMonster_Source_ProjectMonster_Public_Interfaces_PlayerActionsInterface_h__Script_ProjectMonster_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UPlayerActionsInterface, UPlayerActionsInterface::StaticClass, TEXT("UPlayerActionsInterface"), &Z_Registration_Info_UClass_UPlayerActionsInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPlayerActionsInterface), 4223796920U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_ProjectMonster_Source_ProjectMonster_Public_Interfaces_PlayerActionsInterface_h__Script_ProjectMonster_1722748124(TEXT("/Script/ProjectMonster"),
	Z_CompiledInDeferFile_FID_Git_ProjectMonster_Source_ProjectMonster_Public_Interfaces_PlayerActionsInterface_h__Script_ProjectMonster_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_ProjectMonster_Source_ProjectMonster_Public_Interfaces_PlayerActionsInterface_h__Script_ProjectMonster_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS

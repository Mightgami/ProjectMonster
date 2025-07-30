// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeProjectMonster_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_ProjectMonster;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_ProjectMonster()
	{
		if (!Z_Registration_Info_UPackage__Script_ProjectMonster.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/ProjectMonster",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0xB4A33B24,
				0x0CC51B60,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_ProjectMonster.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_ProjectMonster.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_ProjectMonster(Z_Construct_UPackage__Script_ProjectMonster, TEXT("/Script/ProjectMonster"), Z_Registration_Info_UPackage__Script_ProjectMonster, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xB4A33B24, 0x0CC51B60));
PRAGMA_ENABLE_DEPRECATION_WARNINGS

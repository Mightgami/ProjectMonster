// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ProjectMonster : ModuleRules
{
	public ProjectMonster(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			// Default Node
			"Core",
			"CoreUObject",
			"Engine",
			
			// New Module
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"GameplayAbilities",
			"Paper2D",
			"PaperZD",
			
			// New Module - Editor Only
			"UnrealEd",
			"UMG"
		});

		PrivateDependencyModuleNames.AddRange(new string[] {"GameplayTags","GameplayTasks" });


		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}

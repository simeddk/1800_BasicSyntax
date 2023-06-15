// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class U04_BasicSyntax : ModuleRules
{
	public U04_BasicSyntax(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		//PrivateDependencyModuleNames.AddRange(new string[] {  });
		PublicIncludePaths.Add(ModuleDirectory);

	}
}

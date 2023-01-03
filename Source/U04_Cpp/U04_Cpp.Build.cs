// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class U04_Cpp : ModuleRules
{
	public U04_Cpp(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

        PublicIncludePaths.Add(ModuleDirectory);

	}
}

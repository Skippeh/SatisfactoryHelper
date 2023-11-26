// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class FactoryGameTarget : TargetRules
{
	public FactoryGameTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		BuildEnvironment = TargetBuildEnvironment.Shared;
		LinkType = TargetLinkType.Modular;

		ExtraModuleNames.AddRange( new string[] { "FactoryGame", "SatisfactoryHelper" } );
		CppStandard = CppStandardVersion.Cpp20;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		
		bOverrideAppNameForSharedBuild = true;

		bUseChecksInShipping = true;
		bUseLoggingInShipping = true;
		
		WindowsPlatform.bEnableRayTracing = false;
		LinuxPlatform.bEnableRayTracing = false;
	}
}

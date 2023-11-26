// Fill out your copyright notice in the Description page of Project Settings.

using System;
using System.IO;
using System.Runtime.InteropServices;
using System.Text;
using EpicGames.Core;
using UnrealBuildTool;

public class SatisfactoryHelper : ModuleRules
{
    public SatisfactoryHelper(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bLegacyPublicIncludePaths = true;
        ShadowVariableWarningLevel = WarningLevel.Warning;

        PublicDependencyModuleNames.AddRange(new[] {
            "SML",
            "FactoryGame"
        });

        // FactoryGame transitive dependencies
        // Not all of these are required, but including the extra ones saves you from having to add them later.
        PublicDependencyModuleNames.AddRange(new string[] {
            "Core", "CoreUObject",
            "Engine",
            "DeveloperSettings",
            "PhysicsCore",
            "InputCore",
            "OnlineSubsystem", "OnlineSubsystemUtils", "OnlineSubsystemNull",
            "SignificanceManager",
            "GeometryCollectionEngine",
            "ChaosVehiclesCore", "ChaosVehicles", "ChaosSolverEngine",
            "AnimGraphRuntime",
            "AkAudio",
            "AssetRegistry",
            "NavigationSystem",
            "ReplicationGraph",
            "AIModule",
            "GameplayTasks",
            "SlateCore", "Slate", "UMG",
            "RenderCore",
            "CinematicCamera",
            "Foliage",
            "Niagara",
            "EnhancedInput",
            "GameplayCameras",
            "TemplateSequence",
            "NetCore",
            "GameplayTags"
        });

        // FactoryGame plugins
        PublicDependencyModuleNames.AddRange(new[] {
            "AbstractInstance",
            "SignificanceISPC"
        });

        // Header stubs
        PublicDependencyModuleNames.AddRange(new[] {
            "DummyHeaders",
        });

        if (Target.Type == TargetRules.TargetType.Editor)
        {
            PublicDependencyModuleNames.AddRange(new string[] {
                "OnlineBlueprintSupport",
                "AnimGraph"
            });
        }
    }
}

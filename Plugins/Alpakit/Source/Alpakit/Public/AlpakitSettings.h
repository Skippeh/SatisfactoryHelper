#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Editor/DetailCustomizations/Public/DetailCustomizations.h"
#include "Editor/PropertyEditor/Public/IDetailCustomization.h"
#include "DetailLayoutBuilder.h"
#include "AlpakitSettings.generated.h"

USTRUCT()
struct FAlpakitMod
{
	GENERATED_BODY()
public:
	/* Should this mod be paked? */
	UPROPERTY(EditAnywhere, config)
	bool Enabled = true;

	/* mod_reference in data.json, your mod folder name */
	UPROPERTY(EditAnywhere, config)
	FString Name;

	/* The mod name that players see */
	UPROPERTY(EditAnywhere, config)
	FString DisplayName;

	UPROPERTY(EditAnywhere, config)
	FString Description;

	/* Your mod version, format: X.Y.Z */
	UPROPERTY(EditAnywhere, config)
	FString Version;

	UPROPERTY(EditAnywhere, config)
	TArray<FString> Authors;

	/* Can include paths to vanilla assets, or other mod assets that you wish to replace with your version. You don't need to add your mod here */
	UPROPERTY(EditAnywhere, config)
	TArray<FString> OverwritePaths;
};

USTRUCT()
struct FGamePath
{
	GENERATED_BODY();
public:
	UPROPERTY(EditAnywhere, config)
	bool Enabled = true;

	UPROPERTY(EditAnywhere, config)
	FDirectoryPath Directory;

	UPROPERTY(EditAnywhere, config)
	FString LaunchArguments;
};

UCLASS(config = Game)
class UAlpakitSettings : public UObject
{
	GENERATED_BODY()

public:
	UAlpakitSettings(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, config, Category = Config)
	TArray<FGamePath> SatisfactoryGamePaths;
	
	UPROPERTY(EditAnywhere, config, Category = Mods)
	TArray<FAlpakitMod> Mods;

	UPROPERTY(EditAnywhere, config, Category = Config)
	bool CopyModsToGame;

	UPROPERTY(EditAnywhere, config, Category = Config)
	bool StartGame;

	/** If enabled all games will be started. Otherwise only the first game will be. */
	UPROPERTY(EditAnywhere, config, Category = Config, meta = (EditCondition = "StartGame"))
	bool StartAllGames;
};
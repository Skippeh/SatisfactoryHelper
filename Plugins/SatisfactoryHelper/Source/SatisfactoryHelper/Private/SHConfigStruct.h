#pragma once
#include "CoreMinimal.h"
#include "Configuration/ConfigManager.h"
#include "Engine/Engine.h"
#include "SHConfigStruct.generated.h"

struct FSHConfigStruct_PersonalSettings;

USTRUCT(BlueprintType)
struct FSHConfigStruct_PersonalSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite)
    bool bShowAllRecipes;
};

/* Struct generated from Mod Configuration Asset '/SatisfactoryHelper/SHConfig' */
USTRUCT(BlueprintType)
struct FSHConfigStruct {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite)
    FSHConfigStruct_PersonalSettings PersonalSettings;

    /* Retrieves active configuration value and returns object of this struct containing it */
    static FSHConfigStruct GetActiveConfig() {
        FSHConfigStruct ConfigStruct{};
        FConfigId ConfigId{"SatisfactoryHelper", ""};
        UConfigManager* ConfigManager = GEngine->GetEngineSubsystem<UConfigManager>();
        ConfigManager->FillConfigurationStruct(ConfigId, FDynamicStructInfo{FSHConfigStruct::StaticStruct(), &ConfigStruct});
        return ConfigStruct;
    }
};


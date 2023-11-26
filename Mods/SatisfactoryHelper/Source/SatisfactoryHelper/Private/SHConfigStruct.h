#pragma once
#include "CoreMinimal.h"
#include "Configuration/ConfigManager.h"
#include "Engine/Engine.h"
#include "Engine/GameInstance.h"
#include "SHConfigStruct.generated.h"

/* Struct generated from Mod Configuration Asset '/SatisfactoryHelper/SHConfig' */
USTRUCT(BlueprintType)
struct FSHConfigStruct {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite)
    bool ShowAllRecipes{};

    /* Retrieves active configuration value and returns object of this struct containing it */
    static FSHConfigStruct GetActiveConfig(const UObject* WorldContext) {
        FSHConfigStruct ConfigStruct;

        if (const UWorld* World = GEngine->GetWorldFromContextObject(WorldContext, EGetWorldErrorMode::ReturnNull))
        {
            UConfigManager* ConfigManager = World->GetGameInstance()->GetSubsystem<UConfigManager>();
            
            const FConfigId ConfigId {"SatisfactoryHelper", ""};
            ConfigManager->FillConfigurationStruct(ConfigId, FDynamicStructInfo{FSHConfigStruct::StaticStruct(), &ConfigStruct});
        }

        return ConfigStruct;
    }
};


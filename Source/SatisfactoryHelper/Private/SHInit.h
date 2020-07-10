#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "Subsystems/LocalPlayerSubsystem.h"
#include "Subsystems/SHCheatSubsystem.h"
#include "SHInit.generated.h"

class AUIManager;
class ASHInputManager;
class UContentManager;
class ASHItemInfoSubsystem;
class ASHSaveManager;

USTRUCT(BlueprintType)
struct FSHUserConfig
{
	GENERATED_USTRUCT_BODY()

	FSHUserConfig()
		: bShowAllRecipes(false)
	{
	}

	UPROPERTY(BlueprintReadWrite)
	bool bShowAllRecipes;

	UPROPERTY(BlueprintReadWrite)
	FString ItemsMenuKey = EKeys::F2.ToString();
};

USTRUCT(BlueprintType)
struct FSHConfig
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly)
	FSHUserConfig UserConfig;

	FSHConfig()
	{
	}
};

UCLASS(Blueprintable, Abstract)
class ASHInit : public AInfo
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	AUIManager* GetUIManager() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	ASHInputManager* GetInputManager() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	UContentManager* GetContentManager() const;

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void SaveConfig(const FSHConfig& InUserConfig);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FSHUserConfig GetUserConfig() const;

	UFUNCTION(BlueprintCallable)
	void SetUserConfig(const FSHUserConfig& InUserConfig, bool bSaveToDisk = true);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	TSubclassOf<UFGItemDescriptor> GetVehicleFuelItemClass() const { return VehicleFuelItemClass; }

protected:
	void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<AUIManager> UIManagerClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<ASHInputManager> InputManagerClass;

	UFUNCTION(BlueprintImplementableEvent)
	FSHConfig LoadConfig();

	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<class USHItemInfo>> ItemInfoClasses;

	UFUNCTION(BlueprintNativeEvent)
	void OnPurchasedSchematic(TSubclassOf<UFGSchematic> SchematicClass);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UFGItemDescriptor> VehicleFuelItemClass;

private:
	UPROPERTY()
	AUIManager* UIManager;

	UPROPERTY()
	ASHInputManager* InputManager;

	UPROPERTY()
	UContentManager* ContentManager;

	UPROPERTY()
	ASHSaveManager* SaveManager;

	UPROPERTY()
	FSHConfig Config;

#pragma region Singleton
public:
	static ASHInit* GetSingleton(const UObject* InWorldContext);
#pragma endregion
};
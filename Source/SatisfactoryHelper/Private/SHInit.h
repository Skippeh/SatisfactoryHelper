#pragma once

#include "CoreMinimal.h"
#include "Subsystems/LocalPlayerSubsystem.h"
#include "Subsystems/SHCheatSubsystem.h"
#include "SHInit.generated.h"

class AUIManager;
class ASHInputManager;
class UContentManager;
class ASHItemInfoSubsystem;

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
};

USTRUCT(BlueprintType)
struct FSHConfig
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly)
	FEnabledCheats Cheats;

	UPROPERTY(BlueprintReadOnly)
	FSHUserConfig UserConfig;

	FSHConfig()
		: Cheats(false)
	{
	}
};

UCLASS(Blueprintable, Abstract)
class ASHInit : public AActor
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

private:
	UPROPERTY()
	AUIManager* UIManager;

	UPROPERTY()
	ASHInputManager* InputManager;

	UPROPERTY()
	UContentManager* ContentManager;

	UPROPERTY()
	FSHConfig Config;

#pragma region Singleton
public:
	static ASHInit* GetSingleton(const UObject* InWorldContext);
#pragma endregion
};
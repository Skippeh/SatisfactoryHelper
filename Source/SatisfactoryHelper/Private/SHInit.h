#pragma once

#include "CoreMinimal.h"
#include "Subsystems/LocalPlayerSubsystem.h"
#include "Subsystems/SHCheatSubsystem.h"
#include "SHInit.generated.h"

class AUIManager;
class ASHInputManager;
class UContentManager;
class ASHItemInfoManager;

USTRUCT(BlueprintType)
struct FSHConfig
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly)
	FEnabledCheats Cheats;

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

	UFUNCTION(BlueprintCallable, BlueprintPure)
	ASHItemInfoManager* GetItemInfoManager() const;

	UPROPERTY(BlueprintReadOnly)
	FSHConfig Config;

protected:
	void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<AUIManager> UIManagerClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<ASHInputManager> InputManagerClass;

	UFUNCTION(BlueprintImplementableEvent)
	FSHConfig LoadConfig();

private:
	UPROPERTY()
	AUIManager* UIManager;

	UPROPERTY()
	ASHInputManager* InputManager;

	UPROPERTY()
	UContentManager* ContentManager;
	
	UPROPERTY()
	ASHItemInfoManager* ItemInfoManager;

#pragma region Singleton
public:
	static ASHInit* GetSingleton(const UObject* InWorldContext);
#pragma endregion
};
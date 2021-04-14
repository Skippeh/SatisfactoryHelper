#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "SHInit.generated.h"

class UFGSchematic;
class UFGItemDescriptor;
class AUIManager;
class ASHInputManager;
class UContentManager;
class ASHItemInfoSubsystem;
class ASHSaveManager;

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

	UFUNCTION(BlueprintCallable, BlueprintPure)
	TSubclassOf<UFGItemDescriptor> GetVehicleFuelItemClass() const { return VehicleFuelItemClass; }

protected:
	void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<AUIManager> UIManagerClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<ASHInputManager> InputManagerClass;

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

#pragma region Singleton
public:
	static ASHInit* GetSingleton(const UObject* InWorldContext);
#pragma endregion
};
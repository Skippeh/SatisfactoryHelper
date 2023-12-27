#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "SHInit.generated.h"

class UFGSchematic;
class UFGItemDescriptor;
class AUIManager;
class UContentManager;
class ASHItemInfoSubsystem;
class ASHSaveManager;

UCLASS(Blueprintable, Abstract)
class ASHInit : public AInfo
{
	GENERATED_BODY()
	
public:
	ASHInit()
	{
		PrimaryActorTick.bCanEverTick = true;
	}
	
	UFUNCTION(BlueprintCallable, BlueprintPure)
	AUIManager* GetUIManager() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	UContentManager* GetContentManager() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	TSubclassOf<UFGItemDescriptor> GetVehicleFuelItemClass() const { return VehicleFuelItemClass; }

protected:
	void BeginPlay() override;
	void Tick(float DeltaSeconds) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<AUIManager> UIManagerClass;

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
	UContentManager* ContentManager;

	UPROPERTY()
	ASHSaveManager* SaveManager;

	UPROPERTY()
	bool RegisteredPurchasedSchematicEvent;

#pragma region Singleton
public:
	static ASHInit* GetSingleton(const UObject* InWorldContext);
#pragma endregion
};
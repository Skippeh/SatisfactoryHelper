#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "FGSaveInterface.h"
#include "DelegateCombinations.h"
#include "Resources/FGItemDescriptor.h"
#include "SHSaveManager.generated.h"

class UFGItemDescriptor;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnItemPinChanged, TSubclassOf<UFGItemDescriptor>, ItemDescriptor, bool, bIsPinned);

/**
 * Handles saving and loading map data related to Satisfactory Helper.
 */
UCLASS()
class SATISFACTORYHELPER_API ASHSaveManager : public AInfo, public IFGSaveInterface
{
	GENERATED_BODY()

#pragma region IFGSaveInterface implementation
	void PreSaveGame_Implementation(int32 saveVersion, int32 gameVersion) override;
	void PostSaveGame_Implementation(int32 saveVersion, int32 gameVersion) override;
	void PreLoadGame_Implementation(int32 saveVersion, int32 gameVersion) override;
	void PostLoadGame_Implementation(int32 saveVersion, int32 gameVersion) override;
	void GatherDependencies_Implementation(TArray<UObject*>& out_dependentObjects) override { }
	bool ShouldSave_Implementation() const override { return true; }
	bool NeedTransform_Implementation() override { return false; }
#pragma endregion

	ASHSaveManager();

public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	TArray<TSubclassOf<UFGItemDescriptor>> GetPinnedItems() const { return PinnedItems; }

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void AddPinnedItem(TSubclassOf<UFGItemDescriptor> ItemDescriptor);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void RemovePinnedItem(TSubclassOf<UFGItemDescriptor> ItemDescriptor);

	UPROPERTY(BlueprintAssignable)
	FOnItemPinChanged OnItemPinChanged;

private:
	UPROPERTY(SaveGame, Replicated)
	TArray<TSubclassOf<UFGItemDescriptor>> PinnedItems;

	UFUNCTION(NetMulticast, Reliable)
	void RPC_OnToggledPinnedItem(TSubclassOf<UFGItemDescriptor> ItemDescriptor, bool bIsPinned);
};
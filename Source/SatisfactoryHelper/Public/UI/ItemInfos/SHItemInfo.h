#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ItemInfoData/SHItemData.h"
#include "SHItemInfo.generated.h"

class UFGItemDescriptor;

UCLASS(Abstract)
class USHItemInfo : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	bool SetItemDescriptor(TSubclassOf<UFGItemDescriptor> NewItemDescriptor);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE TSubclassOf<UFGItemDescriptor> GetItemDescriptor() const { return ItemDescriptor; }

protected:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE bool HasValidDescriptor() const { return IsValid(ItemDescriptor); }

	/** Called when a new item descriptor has been set. */
	UFUNCTION(BlueprintNativeEvent)
	void OnDescriptorSet(TSubclassOf<UFGItemDescriptor> NewDescriptor, USHItemData* ItemData);
	
	/** The ItemDescriptor that this item is currently displaying info for. */
	UPROPERTY(BlueprintReadOnly, Meta = (ExposeOnSpawn = "true"))
	TSubclassOf<UFGItemDescriptor> ItemDescriptor;

	/** The data class this ItemInfo reads from. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<USHItemData> DataClass;

	/** The title to set on the container collapsible widget. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText Title;

	/** Gets the ItemInfoManager instance. */
	UFUNCTION(BlueprintCallable, BlueprintPure)
	ASHItemInfoManager* GetItemInfoManager();

private:
	ASHItemInfoManager* CachedInfoManager = nullptr;
};
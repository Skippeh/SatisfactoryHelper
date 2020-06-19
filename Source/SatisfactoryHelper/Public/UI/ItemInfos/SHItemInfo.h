#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ItemInfoData/SHItemData.h"
#include "SHItemInfo.generated.h"

class UFGItemDescriptor;

UCLASS(Abstract)
class SATISFACTORYHELPER_API USHItemInfo : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	bool SetItemDescriptor(TSubclassOf<UFGItemDescriptor> NewItemDescriptor);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE TSubclassOf<UFGItemDescriptor> GetItemDescriptor() const { return ItemDescriptor; }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE FText GetTitle() const { return Title; }

	/** Gets the main data class that this info widget gets its data from. */
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE TSubclassOf<USHItemData> GetDataClass() const { return DataClass; }

protected:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE bool HasValidDescriptor() const { return IsValid(ItemDescriptor); }

	/** Returns true if the specified item descriptor is valid for this widget. If false then this widget won't be shown for this item. Default is true. */
	UFUNCTION(BlueprintNativeEvent)
	bool ShouldShowForItemDescriptor(TSubclassOf<UFGItemDescriptor> ItemClass) const;

	/** Called when a new item descriptor has been set. */
	UFUNCTION(BlueprintNativeEvent)
	void OnDescriptorSet(TSubclassOf<UFGItemDescriptor> NewDescriptor, USHItemData* ItemData);
	
	/** The ItemDescriptor that this item is currently displaying info for. */
	UPROPERTY(BlueprintReadOnly, Meta = (ExposeOnSpawn = "true"))
	TSubclassOf<UFGItemDescriptor> ItemDescriptor;

	/** REQUIRED! The data class this ItemInfo reads from. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<USHItemData> DataClass;

	/** The title to set on the container collapsible widget. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText Title;

	/** Gets the ItemInfoManager instance. */
	UFUNCTION(BlueprintCallable, BlueprintPure)
	ASHItemInfoSubsystem* GetItemInfoSubsystem();

	void NativeOnInitialized() override;

private:
	UPROPERTY()
	ASHItemInfoSubsystem* CachedInfoSubsystem = nullptr;
};
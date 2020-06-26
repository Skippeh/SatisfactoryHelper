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

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE int32 GetListPriority() const { return ListPriority; }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE bool GetCollapsedByDefault() const { return bCollapsedByDefault; }

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

	/** The order of appearance in the info panels view. Higher value means appearing further up the list. Default value is 0. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 ListPriority;

	/** If true then this panel will be collapsed by default. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	bool bCollapsedByDefault;

	/** Gets the ItemInfoManager instance. */
	UFUNCTION(BlueprintCallable, BlueprintPure)
	ASHItemInfoSubsystem* GetItemInfoSubsystem();

	/** Returns true if we should show all items or just unlocked ones. */
	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool GetShowAllItems() const;

	void NativeOnInitialized() override;

private:
	UPROPERTY()
	ASHItemInfoSubsystem* CachedInfoSubsystem = nullptr;
};
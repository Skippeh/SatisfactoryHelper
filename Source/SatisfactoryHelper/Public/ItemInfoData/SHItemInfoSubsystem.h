#pragma once

#include "CoreMinimal.h"
#include "FGSubsystem.h"
#include "ItemInfoData/SHItemData.h"
#include "SHItemInfoSubsystem.generated.h"

USTRUCT()
struct FCachedItemData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	TMap<TSubclassOf<USHItemData>, USHItemData*> Map;
};

UCLASS()
class SATISFACTORYHELPER_API ASHItemInfoSubsystem : public AFGSubsystem
{
	GENERATED_BODY()
	
public:
	/** Gets the item data for the specific item descriptor. If the item data doesn't support the given DescriptorClass null will be returned. */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Item Data"))
	USHItemData* GetItemData(TSubclassOf<class UFGItemDescriptor> DescriptorClass, TSubclassOf<USHItemData> ItemDataClass);

	/** Gets all registered classes that inherit the USHItemInfo widget base class. Optionally sort array by priority and title. */
	UFUNCTION(BlueprintCallable, BlueprintPure)
	void GetItemInfoClasses(TArray<TSubclassOf<class USHItemInfo>>& OutArray, bool bSortByPriorityAndTitle = false);

	/** Register an item info class. This needs to be called in order for an item info to show up on an item. Returns false if the class is already registered, or if it's abstract. */
	UFUNCTION(BlueprintCallable)
	bool RegisterItemInfoClass(TSubclassOf<class USHItemInfo> ItemInfoClass);

	/** Registers the item info classes. This needs to be called in order for an item info to show up on an item. Returns the number of classes that were successfully registered. */
	UFUNCTION(BlueprintCallable)
	int32 RegisterItemInfoClasses(const TArray<TSubclassOf<class USHItemInfo>>& InItemInfoClasses);

private:
	UPROPERTY()
	TMap<TSubclassOf<class UFGItemDescriptor>, FCachedItemData> CachedItemDataMap;

	/** List of registered item info classes */
	UPROPERTY()
	TArray<TSubclassOf<class USHItemInfo>> ItemInfoClasses;
};
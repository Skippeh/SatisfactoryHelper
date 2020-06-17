#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemInfoData/SHItemData.h"
#include "SHItemInfoManager.generated.h"

UCLASS()
class ASHItemInfoManager : public AActor
{
	GENERATED_BODY()
	
public:
	/** Gets the item data for the specific item descriptor. */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Item Data"))
	class USHItemData* GetItemData(TSubclassOf<class UFGItemDescriptor> DescriptorClass, TSubclassOf<USHItemData> ItemDataClass);

private:
	TMap<TSubclassOf<class UFGItemDescriptor>, TMap<TSubclassOf<USHItemData>, USHItemData*>> CachedItemDataMap;
};
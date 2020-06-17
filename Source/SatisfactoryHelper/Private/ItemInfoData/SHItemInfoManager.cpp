#include "SHItemInfoManager.h"
#include "Resources/FGItemDescriptor.h"

USHItemData* ASHItemInfoManager::GetItemData(TSubclassOf<UFGItemDescriptor> DescriptorClass, TSubclassOf<USHItemData> ItemDataClass)
{
	check(!ItemDataClass->HasAnyClassFlags(CLASS_Abstract));

	auto DataMap = CachedItemDataMap.FindOrAdd(DescriptorClass);
	USHItemData* ItemData = nullptr;
	USHItemData** ExistingDataPtr = DataMap.Find(ItemDataClass);

	if (ExistingDataPtr != nullptr)
		ItemData = *ExistingDataPtr;

	if (ItemData == nullptr)
	{
		ItemData = NewObject<USHItemData>(this, ItemDataClass);
		ItemData->SetPropertiesFromItemDescriptor(DescriptorClass);
		DataMap.Add(ItemDataClass, ItemData);
	}

	return ItemData;
}
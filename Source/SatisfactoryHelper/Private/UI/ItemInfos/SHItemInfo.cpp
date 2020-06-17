#include "SHItemInfo.h"
#include "Resources/FGItemDescriptor.h"
#include "ItemInfoData/SHItemInfoManager.h"
#include "SHInit.h"

bool USHItemInfo::SetItemDescriptor(TSubclassOf<UFGItemDescriptor> NewItemDescriptor)
{
	if (!IsValid(NewItemDescriptor))
		return false;

	if (NewItemDescriptor->HasAnyClassFlags(CLASS_Abstract))
		return false;

	ItemDescriptor = NewItemDescriptor;

	check(IsValid(DataClass));
	auto ItemInfoManager = GetItemInfoManager();
	auto ItemData = ItemInfoManager->GetItemData(NewItemDescriptor, DataClass);

	OnDescriptorSet(NewItemDescriptor, ItemData);
	return true;
}

void USHItemInfo::OnDescriptorSet_Implementation(TSubclassOf<UFGItemDescriptor> NewItemDescriptor, USHItemData* ItemData) { /* no default impl */ }

ASHItemInfoManager* USHItemInfo::GetItemInfoManager()
{
	if (!IsValid(CachedInfoManager))
	{
		CachedInfoManager = ASHInit::GetSingleton(GetOuter()->GetWorld())->GetItemInfoManager();
	}

	return CachedInfoManager;
}
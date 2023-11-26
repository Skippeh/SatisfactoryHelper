#include "UI/ItemInfos/SHItemInfo.h"
#include "Resources/FGItemDescriptor.h"
#include "ItemInfoData/SHItemInfoSubsystem.h"
#include "SHInit.h"
#include "SHBlueprintFunctionLibrary.h"
#include "SHConfigStruct.h"

void USHItemInfo::NativeOnInitialized()
{
	verify(IsValid(DataClass)); // Fail early in case DataClass is not set.
}

bool USHItemInfo::SetItemDescriptor(TSubclassOf<UFGItemDescriptor> NewItemDescriptor)
{
	if (!IsValid(NewItemDescriptor))
		return false;

	if (NewItemDescriptor->HasAnyClassFlags(CLASS_Abstract))
		return false;

	if (!ShouldShowForItemDescriptor(NewItemDescriptor))
		return false;

	ItemDescriptor = NewItemDescriptor;

	auto ItemInfoManager = GetItemInfoSubsystem();
	auto ItemData = ItemInfoManager->GetItemData(NewItemDescriptor, DataClass);

	OnDescriptorSet(NewItemDescriptor, ItemData);
	return true;
}

bool USHItemInfo::ShouldShowForItemDescriptor_Implementation(TSubclassOf<UFGItemDescriptor> ItemClass) const { return true; }
void USHItemInfo::OnDescriptorSet_Implementation(TSubclassOf<UFGItemDescriptor> NewItemDescriptor, USHItemData* ItemData) { unimplemented(); /* no default impl */ }

ASHItemInfoSubsystem* USHItemInfo::GetItemInfoSubsystem()
{
	if (!IsValid(CachedInfoSubsystem))
	{
		CachedInfoSubsystem = USHBlueprintFunctionLibrary::GetItemInfoSubsystem(GetWorld());
	}

	return CachedInfoSubsystem;
}

bool USHItemInfo::GetShowAllItems() const
{
	const auto Config = FSHConfigStruct::GetActiveConfig(this);
	return Config.ShowAllRecipes;
}
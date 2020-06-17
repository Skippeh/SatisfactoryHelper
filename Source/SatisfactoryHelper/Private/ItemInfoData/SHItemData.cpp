#include "SHItemData.h"
#include "SHItemInfoManager.h"

void USHItemData::SetPropertiesFromItemDescriptor_Implementation(TSubclassOf<UFGItemDescriptor> ItemDescriptor) { }

ASHItemInfoManager* USHItemData::GetItemInfoManager() const
{
	return CastChecked<ASHItemInfoManager>(GetOuter());
}
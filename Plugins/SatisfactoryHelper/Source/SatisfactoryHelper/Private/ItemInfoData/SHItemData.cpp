#include "SHItemData.h"
#include "SHItemInfoSubsystem.h"

void USHItemData::SetPropertiesFromItemDescriptor_Implementation(TSubclassOf<UFGItemDescriptor> ItemDescriptor) { }
bool USHItemData::SupportsItemDescriptor_Implementation(TSubclassOf<UFGItemDescriptor> DescriptorClass) const { return true; }

ASHItemInfoSubsystem* USHItemData::GetItemInfoSubsystem() const
{
	return CastChecked<ASHItemInfoSubsystem>(GetOuter());
}
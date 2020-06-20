#include "ItemDebugData.h"
#include "Resources/FGItemDescriptor.h"
#include "SHBlueprintFunctionLibrary.h"

void UItemDebugData::SetPropertiesFromItemDescriptor_Implementation(TSubclassOf<UFGItemDescriptor> ItemDescriptor)
{
	UpdateClassInheritancePath(ItemDescriptor);
}

void UItemDebugData::UpdateClassInheritancePath(TSubclassOf<UFGItemDescriptor> Descriptor)
{
	ClassInheritancePath = USHBlueprintFunctionLibrary::GetClassInheritancePathString(*Descriptor);
}
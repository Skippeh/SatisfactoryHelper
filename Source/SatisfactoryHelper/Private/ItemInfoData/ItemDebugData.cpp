#include "ItemDebugData.h"
#include "Resources/FGItemDescriptor.h"

void UItemDebugData::SetPropertiesFromItemDescriptor_Implementation(TSubclassOf<UFGItemDescriptor> ItemDescriptor)
{
	UpdateClassInheritancePath(ItemDescriptor);
}

void UItemDebugData::UpdateClassInheritancePath(TSubclassOf<UFGItemDescriptor> Descriptor)
{
	TArray<UClass*> ParentClasses;
	UClass* CurrentClass = Descriptor.Get();

	do
	{
		ParentClasses.Add(CurrentClass);
		CurrentClass = CurrentClass->GetSuperClass();
	} while (IsValid(CurrentClass));

	ClassInheritancePath = FString::JoinBy(ParentClasses, TEXT(" <- "), [](UClass* Class)
	{
		return Class->GetName();
	});
}
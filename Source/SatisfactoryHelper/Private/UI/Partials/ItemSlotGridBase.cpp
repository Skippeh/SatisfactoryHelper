#include "ItemSlotGridBase.h"
#include "Blueprint/WidgetTree.h"

void UItemSlotGridBase::AddStack(const FInventoryStack& InInventoryStack)
{
	AddChild(ConstructSlotWidget(InInventoryStack));
}

void UItemSlotGridBase::AddDescriptor(TSubclassOf<UFGItemDescriptor> ItemDescriptor)
{
	FInventoryStack InventoryStack(1, ItemDescriptor);
	AddChild(ConstructSlotWidget(InventoryStack));
}

void UItemSlotGridBase::AddStacks(const TArray<FInventoryStack>& InInventoryStacks)
{
	for (const FInventoryStack& InventoryStack : InInventoryStacks)
	{
		AddChild(ConstructSlotWidget(InventoryStack));
	}
}

void UItemSlotGridBase::AddDescriptors(const TArray<TSubclassOf<UFGItemDescriptor>>& InItemDescriptors)
{
	TArray<FInventoryStack> InventoryStacks;

	for (auto Descriptor : InItemDescriptors)
	{
		InventoryStacks.Add(FInventoryStack(1, Descriptor));
	}

	AddStacks(InventoryStacks);
}

void UItemSlotGridBase::ClearAndAddStacks(const TArray<FInventoryStack>& InInventoryStacks)	
{
	ClearChildren();
	AddStacks(InInventoryStacks);
}

void UItemSlotGridBase::ClearAndAddDescriptors(const TArray<TSubclassOf<UFGItemDescriptor>>& InItemDescriptors)
{
	ClearChildren();
	AddDescriptors(InItemDescriptors);
}
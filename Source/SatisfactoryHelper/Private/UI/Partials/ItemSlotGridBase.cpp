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

void UItemSlotGridBase::AddItemAmount(const FItemAmount& InItemAmount)
{
	FInventoryStack InventoryStack(InItemAmount.Amount, InItemAmount.ItemClass);
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

void UItemSlotGridBase::AddItemAmounts(const TArray<FItemAmount>& InItemAmounts)
{
	TArray<FInventoryStack> InventoryStacks;

	for (auto ItemAmount : InItemAmounts)
	{
		InventoryStacks.Add(FInventoryStack(ItemAmount.Amount, ItemAmount.ItemClass));
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

void UItemSlotGridBase::ClearAndAddItemAmounts(const TArray<FItemAmount>& InItemAmounts)
{
	ClearChildren();
	AddItemAmounts(InItemAmounts);
}
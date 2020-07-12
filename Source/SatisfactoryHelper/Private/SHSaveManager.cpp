#include "SHSaveManager.h"
#include "UnrealNetwork.h"
#include "util/Logging.h"
#include "SHBlueprintFunctionLibrary.h"

#pragma region IFGSaveInterface implementation
void ASHSaveManager::PreLoadGame_Implementation(int32 saveVersion, int32 gameVersion)
{
}

void ASHSaveManager::PostLoadGame_Implementation(int32 saveVersion, int32 gameVersion)
{
	// Remove item descriptors from mods that have been deleted or have been deprecated.
	TArray<TSubclassOf<UFGItemDescriptor>> PendingRemoval;

	for (const auto& ItemDescriptor : PinnedItems)
	{
		if (!IsValid(ItemDescriptor) || !IsValid(ItemDescriptor.Get()) || ItemDescriptor->HasAnyClassFlags(CLASS_Deprecated))
			PendingRemoval.Add(ItemDescriptor);
	}

	for (const auto& ItemDescriptor : PendingRemoval)
	{
		PinnedItems.Remove(ItemDescriptor);
	}

	USHBlueprintFunctionLibrary::GetCheatSubsystem(this)->SetEnabledCheats(EnabledCheats);
}

void ASHSaveManager::PreSaveGame_Implementation(int32 saveVersion, int32 gameVersion)
{
	EnabledCheats = USHBlueprintFunctionLibrary::GetCheatSubsystem(this)->GetEnabledCheats();
}

void ASHSaveManager::PostSaveGame_Implementation(int32 saveVersion, int32 gameVersion)
{
}
#pragma endregion

ASHSaveManager::ASHSaveManager()
{
	bReplicates = true;
	bAlwaysRelevant = true;
}

void ASHSaveManager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	DOREPLIFETIME(ASHSaveManager, PinnedItems);
}

void ASHSaveManager::AddPinnedItem(TSubclassOf<UFGItemDescriptor> ItemDescriptor)
{
	if (PinnedItems.Contains(ItemDescriptor))
		return;

	PinnedItems.Add(ItemDescriptor);
	RPC_OnToggledPinnedItem(ItemDescriptor, true);
}

void ASHSaveManager::RemovePinnedItem(TSubclassOf<UFGItemDescriptor> ItemDescriptor)
{
	if (PinnedItems.Remove(ItemDescriptor) == 0)
		return;

	RPC_OnToggledPinnedItem(ItemDescriptor, false);
}

void ASHSaveManager::RPC_OnToggledPinnedItem_Implementation(TSubclassOf<UFGItemDescriptor> ItemDescriptor, bool bIsPinned)
{
	OnItemPinChanged.Broadcast(ItemDescriptor, bIsPinned);
}
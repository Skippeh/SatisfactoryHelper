#include "SHSaveManager.h"
#include "UnrealNetwork.h"
#include "util/Logging.h"

#pragma region IFGSaveInterface implementation
void ASHSaveManager::PostLoadGame_Implementation(int32 saveVersion, int32 gameVersion)
{
}

void ASHSaveManager::PreLoadGame_Implementation(int32 saveVersion, int32 gameVersion)
{
}

void ASHSaveManager::PostSaveGame_Implementation(int32 saveVersion, int32 gameVersion)
{
}

void ASHSaveManager::PreSaveGame_Implementation(int32 saveVersion, int32 gameVersion)
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
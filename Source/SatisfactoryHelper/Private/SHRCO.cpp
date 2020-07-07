#include "SHRCO.h"
#include "Net/UnrealNetwork.h"
#include "Resources/FGItemDescriptor.h"
#include "Resources/FGBuildDescriptor.h"
#include "FGPlayerController.h"
#include "FGPlayerState.h"
#include "Content/ContentManager.h"
#include "FGInventoryComponent.h"
#include "util/Logging.h"
#include "SHInit.h"
#include "SHBlueprintFunctionLibrary.h"
#include "mod/ModSubsystems.h"
#include "Subsystems/SHCheatSubsystem.h"
#include "SHSaveManager.h"

bool ItemClassIsValid(TSubclassOf<UFGItemDescriptor> ItemClass)
{
	if (!IsValid(ItemClass))
		return false;

	if (ItemClass->HasAnyClassFlags(CLASS_Deprecated | CLASS_Abstract))
		return false;

	return true;
}

void USHRCO::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(USHRCO, bDummy);
}

bool USHRCO::GiveItem_Validate(TSubclassOf<UFGItemDescriptor> ItemClass, int32 NumItems)
{
	if (!USHBlueprintFunctionLibrary::GetCheatSubsystem(GetOuter())->GetEnabledCheats().bSpawnItemsAllowed)
		return false;

	if (!ItemClassIsValid(ItemClass))
		return false;

	if (NumItems <= 0 || NumItems > UFGItemDescriptor::GetStackSize(ItemClass))
		return false;

	if (GetOuterFGPlayerController()->NeedRespawn())
		return false;

	if (ItemClass->IsChildOf(UFGBuildDescriptor::StaticClass()))
		return false;

	return true;
}

void USHRCO::GiveItem_Implementation(TSubclassOf<UFGItemDescriptor> ItemClass, int32 NumItems)
{
	AFGPlayerController* PlayerController = GetOuterFGPlayerController();
	UFGInventoryComponent* Inventory = Cast<UFGInventoryComponent>(PlayerController->GetPawn()->GetComponentByClass(UFGInventoryComponent::StaticClass()));

	if (!IsValid(Inventory))
		return;

	FInventoryStack ItemStack(NumItems, ItemClass);
	int32 AddedAmount = Inventory->AddStack(ItemStack, true);
}

bool USHRCO::TogglePinItem_Validate(TSubclassOf<UFGItemDescriptor> ItemClass, bool bPinItem)
{
	if (!ItemClassIsValid(ItemClass))
		return false;

	return true;
}

void USHRCO::TogglePinItem_Implementation(TSubclassOf<UFGItemDescriptor> ItemClass, bool bPinItem)
{
	ASHSaveManager* SaveManager = USHBlueprintFunctionLibrary::GetSaveManager(GetOuter());
	
	if (bPinItem)
		SaveManager->AddPinnedItem(ItemClass);
	else
		SaveManager->RemovePinnedItem(ItemClass);
}
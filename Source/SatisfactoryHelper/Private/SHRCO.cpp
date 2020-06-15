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

void USHRCO::Init()
{
	CheatsSubsystem = USHBlueprintFunctionLibrary::GetCheatSubsystem(GetOuter());
}

void USHRCO::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(USHRCO, bDummy);
}

bool USHRCO::GiveItem_Validate(TSubclassOf<UFGItemDescriptor> ItemClass, int32 NumItems)
{
	// Todo: Check is cheats are enabled

	if (!IsValid(ItemClass))
		return false;

	if (ItemClass->HasAnyClassFlags(CLASS_Deprecated | CLASS_Abstract))
		return false;

	if (NumItems <= 0 || NumItems > UFGItemDescriptor::GetStackSize(ItemClass))
		return false;

	if (GetOuterFGPlayerController()->NeedRespawn())
		return false;

	if (ItemClass->IsChildOf(UFGBuildDescriptor::StaticClass()))
		return false;

	if (USHBlueprintFunctionLibrary::IsItemDescriptorAnInvalidClass(ItemClass))
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
#include "SHRCO.h"
#include "Net/UnrealNetwork.h"
#include "Resources/FGItemDescriptor.h"
#include "Resources/FGBuildDescriptor.h"
#include "Resources/FGVehicleDescriptor.h"
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
#include "Camera/CameraComponent.h"
#include "FGVehicle.h"

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

bool USHRCO::SpawnVehicle_Validate(TSubclassOf<class UFGVehicleDescriptor> VehicleClass)
{
	FEnabledCheats EnabledCheats = USHBlueprintFunctionLibrary::GetCheatSubsystem(GetOuter())->GetEnabledCheats();

	if (!EnabledCheats.bSpawnItemsAllowed)
		return false;

	if (!ItemClassIsValid(TSubclassOf<UFGItemDescriptor>(VehicleClass)))
		return false;
	
	if (GetOuterFGPlayerController()->NeedRespawn())
		return false;

	return true;
}

void USHRCO::SpawnVehicle_Implementation(TSubclassOf<UFGVehicleDescriptor> VehicleClass)
{
	bool bSpawnWithFuel = USHBlueprintFunctionLibrary::GetCheatSubsystem(GetOuter())->GetEnabledCheats().bSpawnVehiclesWithFuel;
	UCameraComponent* Camera = GetOuterFGPlayerController()->GetPawn()->FindComponentByClass<UCameraComponent>();

	FHitResult HitResult;
	FVector Location = Camera->GetComponentLocation();
	FVector ForwardVector = Camera->GetForwardVector();
	if (GetWorld()->LineTraceSingleByChannel(HitResult, Location, Location + (ForwardVector * 10000), ECC_Visibility))
	{
		TSubclassOf<AFGVehicle> VehicleActorClass = UFGVehicleDescriptor::GetVehicleClass(VehicleClass);
		FActorSpawnParameters SpawnParameters;
		SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
		FRotator SpawnRotation = ForwardVector.Rotation();
		SpawnRotation.Pitch = 0;
		AFGVehicle* Vehicle = GetWorld()->SpawnActor<AFGVehicle>(VehicleActorClass, HitResult.Location, SpawnRotation, SpawnParameters);

		// Vehicle won't spawn if there's no space
		if (bSpawnWithFuel && IsValid(Vehicle))
		{
			TArray<UActorComponent*> Inventories = Vehicle->GetComponentsByClass(UFGInventoryComponent::StaticClass());
			
			for (UActorComponent* InventoryComponent : Inventories)
			{
				auto* Inventory = CastChecked<UFGInventoryComponent>(InventoryComponent);
				
				if (Inventory->GetSizeLinear() == 1)
				{
					TSubclassOf<UFGItemDescriptor> FuelClass = USHBlueprintFunctionLibrary::GetInit(this)->GetVehicleFuelItemClass();
					int32 StackSize = UFGItemDescriptor::GetStackSize(FuelClass);
					Inventory->AddStack(FInventoryStack(StackSize, FuelClass));
				}
			}
		}
	}
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
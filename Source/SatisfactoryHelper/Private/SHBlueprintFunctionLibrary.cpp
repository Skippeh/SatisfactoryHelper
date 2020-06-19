#include "SHBlueprintFunctionLibrary.h"
#include "Content/ContentManager.h"
#include "Resources/FGItemDescriptor.h"
#include "SHInit.h"
#include "SHRCO.h"
#include "FGPlayerController.h"
#include "mod/ModSubsystems.h"
#include "FGSubsystem.h"
#include "SHSubsystemHolder.h"
#include "Subsystems/SHCheatSubsystem.h"
#include "ItemInfoData/SHItemInfoSubsystem.h"
#include "SatisfactoryModLoader.h"

UContentManager* USHBlueprintFunctionLibrary::GetContentManager(UObject* InWorldContext)
{
	return UContentManager::GetSingleton(InWorldContext);
}

ASHInit* USHBlueprintFunctionLibrary::GetInit(UObject* InWorldContext)
{
	return ASHInit::GetSingleton(InWorldContext);
}

USHRCO* USHBlueprintFunctionLibrary::GetRCO(UObject* InWorldContext)
{
	AFGPlayerController* PlayerController = CastChecked<AFGPlayerController>(GEngine->GetFirstLocalPlayerController(InWorldContext->GetWorld()));
	return GetRCOFromPlayer(PlayerController);
}

USHRCO* USHBlueprintFunctionLibrary::GetRCOFromPlayer(AFGPlayerController* PlayerController)
{
	USHRCO* RCO = Cast<USHRCO>(PlayerController->GetRemoteCallObjectOfClass(USHRCO::StaticClass()));
	return RCO;
}

bool USHBlueprintFunctionLibrary::IsItemDescriptorAnInvalidClass(TSubclassOf<UFGItemDescriptor> InDescriptorClass)
{
	auto InvalidClasses = UContentManager::GetInvalidItemDescriptorClasses();

	for (auto InvalidClass : InvalidClasses)
	{
		if (InDescriptorClass->IsChildOf(InvalidClass))
			return true;
	}

	return false;
}

USHSubsystemHolder* USHBlueprintFunctionLibrary::GetSHSubsystemHolder(UObject* WorldContext)
{
	USHSubsystemHolder* SubsystemHolder = GetSubsystemHolder<USHSubsystemHolder>(WorldContext);
	return SubsystemHolder;
}

ASHCheatSubsystem* USHBlueprintFunctionLibrary::GetCheatSubsystem(UObject* WorldContext)
{
	auto SubsystemHolder = GetSHSubsystemHolder(WorldContext);

	if (!IsValid(SubsystemHolder))
		return nullptr;

	return SubsystemHolder->GetCheatSubsystem();
}

ASHItemInfoSubsystem* USHBlueprintFunctionLibrary::GetItemInfoSubsystem(UObject* WorldContext)
{
	auto SubsystemHolder = GetSHSubsystemHolder(WorldContext);

	if (!IsValid(SubsystemHolder))
		return nullptr;

	return SubsystemHolder->GetItemInfoSubsystem();
}

bool USHBlueprintFunctionLibrary::IsDebugModeEnabled()
{
	return SML::getSMLConfig().debugLogOutput;
}
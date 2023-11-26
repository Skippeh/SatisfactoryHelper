#include "SHBlueprintFunctionLibrary.h"
#include "Content/ContentManager.h"
#include "Resources/FGItemDescriptor.h"
#include "SHInit.h"
#include "SHRCO.h"
#include "FGPlayerController.h"
#include "SHSaveManager.h"
#include "Subsystems/SHCheatSubsystem.h"
#include "ItemInfoData/SHItemInfoSubsystem.h"
#include "FGSchematicManager.h"
#include "FGRecipeManager.h"
#include "ModLoadingLibrary.h"
#include "SubsystemActorManager.h"
#include "Configuration/ConfigManager.h"

template<class T>
T* GetManagerClass(UObject* WorldContext)
{
	TArray<AActor*> OutActors;
	UGameplayStatics::GetAllActorsOfClass(WorldContext, T::StaticClass(), OutActors);

	if (OutActors.Num() <= 0)
		return nullptr;

	return CastChecked<T>(OutActors[0]);
}

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

ASHCheatSubsystem* USHBlueprintFunctionLibrary::GetCheatSubsystem(UObject* WorldContext)
{
	return WorldContext->GetWorld()->GetSubsystem<USubsystemActorManager>()->GetSubsystemActor<ASHCheatSubsystem>();
}

ASHItemInfoSubsystem* USHBlueprintFunctionLibrary::GetItemInfoSubsystem(UObject* WorldContext)
{
	return WorldContext->GetWorld()->GetSubsystem<USubsystemActorManager>()->GetSubsystemActor<ASHItemInfoSubsystem>();
}

AFGRecipeManager* USHBlueprintFunctionLibrary::GetRecipeManager(UObject* WorldContext)
{
	return GetManagerClass<AFGRecipeManager>(WorldContext);
}

AFGSchematicManager* USHBlueprintFunctionLibrary::GetSchematicManager(UObject* WorldContext)
{
	return AFGSchematicManager::Get(WorldContext);
}

ASHSaveManager* USHBlueprintFunctionLibrary::GetSaveManager(UObject* WorldContext)
{
	return GetManagerClass<ASHSaveManager>(WorldContext);
}

bool USHBlueprintFunctionLibrary::IsDebugModeEnabled()
{
	// This used to return true if SML development mode was enabled, but it was
	// removed at some point. Now we're just returning false instead.
	return false;
}

FString USHBlueprintFunctionLibrary::GetClassInheritancePathString(UClass* Class)
{
	if (!IsValid(Class))
		return FString(TEXT("INVALID_PTR"));

	TArray<UClass*> ParentClasses;
	UClass* CurrentClass = Class;

	do
	{
		ParentClasses.Add(CurrentClass);
		CurrentClass = CurrentClass->GetSuperClass();
	} while (IsValid(CurrentClass));

	return FString::JoinBy(ParentClasses, TEXT(" <- "), [](UClass* Class)
	{
		return Class->GetName();
	});
}

int32 USHBlueprintFunctionLibrary::GetClassInheritanceLength(UClass* Class)
{
	if (!IsValid(Class))
		return 0;

	int32 NumClasses = 0;
	UClass* CurrentClass = Class;

	while (IsValid(CurrentClass))
	{
		CurrentClass = CurrentClass->GetSuperClass();

		if (IsValid(CurrentClass))
			++NumClasses;
	}

	return NumClasses;
}
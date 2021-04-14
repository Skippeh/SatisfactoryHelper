#include "SHInit.h"
#include "UI/UIManager.h"
#include "Input/SHInputManager.h"
#include "Content/ContentManager.h"
//#include "util/Logging.h"
#include "FGGameMode.h"
#include "FGSchematicManager.h"
#include "SHRCO.h"
#include "SHBlueprintFunctionLibrary.h"
#include "ItemInfoData/SHItemInfoSubsystem.h"
#include "SHSaveManager.h"
#include "Kismet/GameplayStatics.h"

AUIManager* ASHInit::GetUIManager() const { return UIManager; }
ASHInputManager* ASHInit::GetInputManager() const { return InputManager; }
UContentManager* ASHInit::GetContentManager() const { return ContentManager; }

void ASHInit::BeginPlay()
{
	verify(IsValid(UIManagerClass));
	verify(IsValid(InputManagerClass));
	ContentManager = NewObject<UContentManager>(this);

	ASHItemInfoSubsystem* ItemInfoSubsystem = USHBlueprintFunctionLibrary::GetItemInfoSubsystem(GetWorld());
	//SML::Logging::debug(TEXT("[SatisfactoryHelper] ItemInfoSubsystem is valid: "), IsValid(ItemInfoSubsystem));
	ItemInfoSubsystem->RegisterItemInfoClasses(ItemInfoClasses);

	if (GetNetMode() != ENetMode::NM_Client)
	{
		SaveManager = USHBlueprintFunctionLibrary::GetSaveManager(GetWorld());
		
		if (SaveManager == nullptr) // Will be null if new world or loading a save that didn't have this mod beforehand
			SaveManager = GetWorld()->SpawnActor<ASHSaveManager>(ASHSaveManager::StaticClass());
	}
	else
	{
		SaveManager = USHBlueprintFunctionLibrary::GetSaveManager(GetWorld()); // gets replicated host actor
	}

	InputManager = GetWorld()->SpawnActor<ASHInputManager>(InputManagerClass);
	UIManager = GetWorld()->SpawnActor<AUIManager>(UIManagerClass);
	
	if (GetNetMode() != ENetMode::NM_Client)
	{
		AFGGameMode* GameMode = CastChecked<AFGGameMode>(GetWorld()->GetAuthGameMode());
		GameMode->RegisterRemoteCallObjectClass(USHRCO::StaticClass());
	}

	// Cache all item descriptors (subsequent calls returns from cache instead of searching assets again)
	TArray<TSubclassOf<UFGItemDescriptor>> Descriptors;
	ContentManager->FindAllDescriptors(Descriptors, false);

	auto SchematicManager = USHBlueprintFunctionLibrary::GetSchematicManager(GetWorld());
	SchematicManager->PurchasedSchematicDelegate.AddDynamic(this, &ASHInit::OnPurchasedSchematic);
}

ASHInit* ASHInit::GetSingleton(const UObject* InWorldContext)
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(InWorldContext, ASHInit::StaticClass(), FoundActors);

	if (FoundActors.Num() <= 0)
		return nullptr;

	return Cast<ASHInit>(FoundActors[0]);
}

void ASHInit::OnPurchasedSchematic_Implementation(TSubclassOf<UFGSchematic> SchematicClass)
{
}
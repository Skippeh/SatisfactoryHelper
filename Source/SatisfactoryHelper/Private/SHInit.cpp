#include "SHInit.h"
#include "UI/UIManager.h"
#include "Input/SHInputManager.h"
#include "Content/ContentManager.h"
#include "util/Logging.h"
#include "FGGameMode.h"
#include "SHRCO.h"
#include "Content/ContentManager.h"
#include "SHBlueprintFunctionLibrary.h"
#include "Subsystems/SHCheatSubsystem.h"
#include "ItemInfoData/SHItemInfoSubsystem.h"
#include "FGSchematicManager.h"
#include "SHSaveManager.h"

AUIManager* ASHInit::GetUIManager() const { return UIManager; }
ASHInputManager* ASHInit::GetInputManager() const { return InputManager; }
UContentManager* ASHInit::GetContentManager() const { return ContentManager; }

void ASHInit::BeginPlay()
{
	verify(IsValid(UIManagerClass));
	verify(IsValid(InputManagerClass));
	Config = LoadConfig();
	ContentManager = NewObject<UContentManager>(this);

	ASHItemInfoSubsystem* ItemInfoSubsystem = USHBlueprintFunctionLibrary::GetItemInfoSubsystem(GetWorld());
	SML::Logging::debug(TEXT("[SatisfactoryHelper] ItemInfoSubsystem is valid: "), IsValid(ItemInfoSubsystem));
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

	SML::Logging::debug(*FString::Printf(TEXT("Found %d descriptor(s)"), Descriptors.Num()));

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

FSHUserConfig ASHInit::GetUserConfig() const
{
	return Config.UserConfig;
}

void ASHInit::SetUserConfig(const FSHUserConfig& InUserConfig, bool bSaveToDisk)
{
	Config.UserConfig = InUserConfig;

	if (bSaveToDisk)
		SaveConfig(Config);
}

void ASHInit::OnPurchasedSchematic_Implementation(TSubclassOf<UFGSchematic> SchematicClass)
{
}
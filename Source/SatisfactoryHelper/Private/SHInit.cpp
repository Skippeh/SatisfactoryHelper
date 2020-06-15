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

AUIManager* ASHInit::GetUIManager() const { return UIManager; }
ASHInputManager* ASHInit::GetInputManager() const { return InputManager; }
UContentManager* ASHInit::GetContentManager() const { return ContentManager; }

void ASHInit::BeginPlay()
{
	check(IsValid(UIManagerClass));
	check(IsValid(InputManagerClass));
	ContentManager = NewObject<UContentManager>(this);
	UIManager = GetWorld()->SpawnActor<AUIManager>(UIManagerClass);
	InputManager = GetWorld()->SpawnActor<ASHInputManager>(InputManagerClass);

	Config = LoadConfig();

	if (HasAuthority())
	{
		AFGGameMode* GameMode = CastChecked<AFGGameMode>(GetWorld()->GetAuthGameMode());
		GameMode->RegisterRemoteCallObjectClass(USHRCO::StaticClass());
		USHBlueprintFunctionLibrary::GetRCO(GetWorld())->Init();
		USHBlueprintFunctionLibrary::GetCheatSubsystem(GetWorld())->SetEnabledCheats(Config.Cheats);
	}

	// Cache all item descriptors (subsequent calls returns from cache instead of searching assets again)
	TArray<TSubclassOf<UFGItemDescriptor>> Descriptors;
	UContentManager::GetSingleton(GetWorld())->FindAllDescriptors(Descriptors, false);

	SML::Logging::debug(*FString::Printf(TEXT("Found %d descriptor(s)"), Descriptors.Num()));
}

ASHInit* ASHInit::GetSingleton(const UObject* InWorldContext)
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(InWorldContext, ASHInit::StaticClass(), FoundActors);

	if (FoundActors.Num() <= 0)
		return nullptr;

	return Cast<ASHInit>(FoundActors[0]);
}
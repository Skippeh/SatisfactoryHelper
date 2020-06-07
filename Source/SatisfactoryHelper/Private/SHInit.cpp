#include "SHInit.h"
#include "UI/UIManager.h"
#include "Input/SHInputManager.h"
#include "Content/ContentManager.h"
#include "util/Logging.h"

ASHInit* ASHInit::Instance = nullptr;

AUIManager* ASHInit::GetUIManager() { return UIManager; }
ASHInputManager* ASHInit::GetInputManager() { return InputManager; }

void ASHInit::BeginPlay()
{
	if (!Instance)
	{
		Instance = this;
	}

	check(IsValid(UIManagerClass));
	check(IsValid(InputManagerClass));
	UIManager = GetWorld()->SpawnActor<AUIManager>(UIManagerClass);
	InputManager = GetWorld()->SpawnActor<ASHInputManager>(InputManagerClass);

	TArray<TSoftClassPtr<UFGItemDescriptor>> Descriptors;
	UContentManager::GetSingleton()->FindAllDescriptors(Descriptors, false);

	SML::Logging::debug(*FString::Printf(TEXT("Found %d descriptor(s)"), Descriptors.Num()));
}
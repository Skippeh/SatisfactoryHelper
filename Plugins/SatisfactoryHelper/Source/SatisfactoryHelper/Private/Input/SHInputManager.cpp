#include "SHInputManager.h"
#include "FGPlayerController.h"
#include "UI/UIManager.h"
#include "SHInit.h"
#include "UI/ItemsWindowWidgetBase.h"

// Called when the game starts or when spawned
void ASHInputManager::BeginPlay()
{
	Super::BeginPlay();
	auto PlayerController = CastChecked<AFGPlayerController>(GEngine->GetFirstLocalPlayerController(GetWorld()));

	PlayerController->InputComponent->BindAction("SatisfactoryHelper.ToggleItemsMenu", IE_Pressed, this, &ASHInputManager::ToggleItemsMenuKeyPressed);
}

void ASHInputManager::ToggleItemsMenuKeyPressed()
{
	ASHInit::GetSingleton(GetWorld())->GetUIManager()->GetItemsWindow()->ToggleWindowVisibility();
}
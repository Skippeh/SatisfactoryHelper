#include "SHInputManager.h"
#include "FGPlayerController.h"
#include "util/Logging.h"
#include "UI/UIManager.h"
#include "SHInit.h"
#include "UI/ItemsWindowWidgetBase.h"

// Called when the game starts or when spawned
void ASHInputManager::BeginPlay()
{
	Super::BeginPlay();
	PlayerController = CastChecked<AFGPlayerController>(GEngine->GetFirstLocalPlayerController(GetWorld()));
}

void ASHInputManager::Tick(float DeltaTime)
{
	if (PlayerController->WasInputKeyJustPressed(ToggleItemsMenuKey))
	{
		ASHInit::GetSingleton(GetWorld())->GetUIManager()->GetItemsWindow()->ToggleWindowVisibility();
	}
}
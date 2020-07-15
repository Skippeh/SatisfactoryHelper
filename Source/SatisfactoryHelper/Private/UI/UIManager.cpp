#include "UIManager.h"
#include "FGPlayerController.h"
#include "UI/ItemsWindowWidgetBase.h"
#include "util/Logging.h"
#include "UI/FGVirtualCursorFunctionLibrary.h"
#include "FGHUD.h"

void AUIManager::BeginPlay()
{
	Super::BeginPlay();
	PlayerController = CastChecked<AFGPlayerController>(GEngine->GetFirstLocalPlayerController(GetWorld()));
	HUD = CastChecked<AFGHUD>(PlayerController->GetHUD());

	verify(IsValid(PlayerController));
	verify(IsValid(HUD));
	verify(IsValid(ItemsWindowClass));

	ItemsWindow = CreateWidget<UItemsWindowWidgetBase>(PlayerController, ItemsWindowClass);
	ItemsWindow->SetOwningPlayer(PlayerController);
	ItemsWindow->AddToViewport();
}

UItemsWindowWidgetBase* AUIManager::GetItemsWindow() const
{
	return ItemsWindow;
}

void AUIManager::ToggleCursor(bool bShowCursor)
{
	CursorShowAmount = FMath::Max(0, CursorShowAmount + (bShowCursor ? 1 : -1));

	if (CursorShowAmount > 0)
	{
		PlayerController->SetIgnoreLookInput(true);
		UFGVirtualCursorFunctionLibrary::EnableVirtualCursor(PlayerController);
		PlayerController->bShowMouseCursor = true;
	}
	else
	{
		bool bIsGamePaused = false; // todo: find out if the game is paused

		if (!bIsGamePaused)
		{
			PlayerController->SetIgnoreLookInput(false);
			UFGVirtualCursorFunctionLibrary::DisableVirtualCursor(PlayerController);
			PlayerController->bShowMouseCursor = false;
		}
	}
}
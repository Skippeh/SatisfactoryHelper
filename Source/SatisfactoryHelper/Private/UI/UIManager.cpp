#include "UIManager.h"
#include "FGPlayerController.h"
#include "UI/ItemsWindowWidgetBase.h"
#include "util/Logging.h"
#include "UI/FGVirtualCursorFunctionLibrary.h"

void AUIManager::BeginPlay()
{
	Super::BeginPlay();
	PlayerController = CastChecked<AFGPlayerController>(GEngine->GetFirstLocalPlayerController(GetWorld()));
	
	check(IsValid(ItemsWindowClass));
	ItemsWindow = NewObject<UItemsWindowWidgetBase>(PlayerController, ItemsWindowClass);
	ItemsWindow->SetOwningPlayer(PlayerController);
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
		SetInputEnabled(false);
		UFGVirtualCursorFunctionLibrary::EnableVirtualCursor(PlayerController);
		PlayerController->bShowMouseCursor = true;
	}
	else
	{
		PlayerController->SetIgnoreLookInput(false);
		SetInputEnabled(true);
		UFGVirtualCursorFunctionLibrary::DisableVirtualCursor(PlayerController);
		PlayerController->bShowMouseCursor = false;
	}
}

void AUIManager::SetInputEnabled(bool bInputEnabled)
{
	FDisabledInputGate DisabledInput(!bInputEnabled);
	PlayerController->SetDisabledInputGate(DisabledInput);
}
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
	ItemsWindow = NewObject<UItemsWindowWidgetBase>(this, ItemsWindowClass);
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
		PlayerController->bShowMouseCursor = true;
		PlayerController->SetIgnoreLookInput(true);
	}
	else
	{
		PlayerController->bShowMouseCursor = false;
		PlayerController->SetIgnoreLookInput(false);
	}
}
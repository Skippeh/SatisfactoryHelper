#include "UIManager.h"
#include "FGPlayerController.h"
#include "UI/ItemsWindowWidgetBase.h"
#include "util/Logging.h"

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
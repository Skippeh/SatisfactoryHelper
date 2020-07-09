#include "SHInputManager.h"
#include "FGPlayerController.h"
#include "util/Logging.h"
#include "UI/UIManager.h"
#include "SHInit.h"
#include "UI/ItemsWindowWidgetBase.h"
#include "SHBlueprintFunctionLibrary.h"

// Called when the game starts or when spawned
void ASHInputManager::BeginPlay()
{
	Super::BeginPlay();
	PlayerController = CastChecked<AFGPlayerController>(GEngine->GetFirstLocalPlayerController(GetWorld()));

	Init = USHBlueprintFunctionLibrary::GetInit(this);
	ToggleItemsMenuKey = FKey(*Init->GetUserConfig().ItemsMenuKey);
}

void ASHInputManager::Tick(float DeltaTime)
{
	if (PlayerController->WasInputKeyJustPressed(ToggleItemsMenuKey) || AlternateKeyJustPressed())
	{
		ASHInit::GetSingleton(GetWorld())->GetUIManager()->GetItemsWindow()->ToggleWindowVisibility();
	}
}

bool ASHInputManager::AlternateKeyJustPressed() const
{
	return PlayerController->WasInputKeyJustPressed(EKeys::F2) && (PlayerController->IsInputKeyDown(EKeys::LeftControl) || PlayerController->IsInputKeyDown(EKeys::RightControl));
}
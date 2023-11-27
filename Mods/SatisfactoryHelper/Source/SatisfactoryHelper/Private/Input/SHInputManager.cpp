#include "SHInputManager.h"
#include "FGCharacterPlayer.h"
#include "FGEnhancedInputComponent.h"
#include "FGPlayerController.h"
#include "UI/UIManager.h"
#include "SHInit.h"
#include "SHModule.h"
#include "UI/ItemsWindowWidgetBase.h"
#include "Components/InputComponent.h"

ASHInputManager::ASHInputManager()
{
	PrimaryActorTick.bCanEverTick = false;
	AFGCharacterPlayer::OnPlayerInputInitialized.AddUObject(this, &ASHInputManager::OnPlayerInputInitialized);
}

void ASHInputManager::OnPlayerInputInitialized(AFGCharacterPlayer* Player, UInputComponent* Input)
{
	if (UFGEnhancedInputComponent* EnhancedInput = CastChecked<UFGEnhancedInputComponent>(Input))
	{
		EnhancedInput->BindAction(ToggleMenuAction, ETriggerEvent::Triggered, this, &ASHInputManager::ToggleItemsMenuKeyPressed);
	}
	else
	{
		UE_LOG(LogSatisfactoryHelper, Display, TEXT("Could not cast to UFGEnhancedInputComponent, Input class = %s"), *Input->GetClass()->GetFullName());
	}
}

void ASHInputManager::ToggleItemsMenuKeyPressed()
{
	if (const auto Init = ASHInit::GetSingleton(GetWorld()))
	{
		Init->GetUIManager()->GetItemsWindow()->ToggleWindowVisibility();
	}
}
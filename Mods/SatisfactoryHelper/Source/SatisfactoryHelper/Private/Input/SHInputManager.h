#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "SHInputManager.generated.h"

class AFGCharacterPlayer;
class UInputAction;

UCLASS(Blueprintable, Abstract)
class ASHInputManager : public AInfo
{
	GENERATED_BODY()

public:
	ASHInputManager();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* ToggleMenuAction;

private:
	void OnPlayerInputInitialized(AFGCharacterPlayer* Player, UInputComponent* Input);
	void ToggleItemsMenuKeyPressed();
};
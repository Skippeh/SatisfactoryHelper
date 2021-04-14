#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "SHInputManager.generated.h"

UCLASS(Blueprintable, Abstract)
class ASHInputManager : public AInfo
{
	GENERATED_BODY()

	ASHInputManager() { PrimaryActorTick.bCanEverTick = false; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	void ToggleItemsMenuKeyPressed();
};
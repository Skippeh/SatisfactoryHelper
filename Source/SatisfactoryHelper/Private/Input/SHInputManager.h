// ILikeBanas

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "SHInputManager.generated.h"

UCLASS(Blueprintable, Abstract)
class ASHInputManager : public AInfo
{
	GENERATED_BODY()

	ASHInputManager() { PrimaryActorTick.bCanEverTick = true; }
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FKey ToggleItemsMenuKey = EKeys::F2;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY()
	class AFGPlayerController* PlayerController;
};
// ILikeBanas

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SHInputManager.generated.h"

UCLASS(Blueprintable, Abstract)
class ASHInputManager : public AActor
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
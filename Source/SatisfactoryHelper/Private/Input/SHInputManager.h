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
	UFUNCTION(BlueprintCallable)
	void SetToggleItemsMenuKey(FKey NewKey) { ToggleItemsMenuKey = NewKey; }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FKey GetToggleItemsMenuKey() const { return ToggleItemsMenuKey; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY()
	class AFGPlayerController* PlayerController;

	UPROPERTY()
	FKey ToggleItemsMenuKey;

	UPROPERTY()
	class ASHInit* Init;

	UFUNCTION()
	bool AlternateKeyJustPressed() const;
};
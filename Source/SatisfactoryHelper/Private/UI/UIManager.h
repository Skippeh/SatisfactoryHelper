#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UIManager.generated.h"

UCLASS(Blueprintable, Abstract)
class AUIManager : public AActor
{
	GENERATED_BODY()

	void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	class UItemsWindowWidgetBase* GetItemsWindow() const;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<class UItemsWindowWidgetBase> ItemsWindowClass;

private:
	class AFGPlayerController* PlayerController;
	class UItemsWindowWidgetBase* ItemsWindow;
};

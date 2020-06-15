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

	/** Show or hide the cursor. If ToggleCursor(true) is called twice, ToggleCursor(false) will have to be called twice as well to hide the cursor. */
	UFUNCTION(BlueprintCallable)
	void ToggleCursor(bool bShowCursor);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<class UItemsWindowWidgetBase> ItemsWindowClass;

	UPROPERTY(BlueprintReadOnly)
	class AFGPlayerController* PlayerController;

	UPROPERTY(BlueprintReadOnly)
	class AFGHUD* HUD;

private:
	UPROPERTY()
	class UItemsWindowWidgetBase* ItemsWindow;

	/** If > 0 it means the cursor is visible. Used in ToggleCursor */
	int32 CursorShowAmount = 0;

	void SetInputEnabled(bool bInputEnabled);
};

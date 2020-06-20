#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/GridPanel.h"
#include "FGInventoryComponent.h"
#include "ItemSlotGridBase.generated.h"

UCLASS(Abstract)
class UItemSlotGridBase : public UGridPanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AddStack(const FInventoryStack& InInventoryStack);

	UFUNCTION(BlueprintCallable)
	void AddDescriptor(TSubclassOf<UFGItemDescriptor> ItemDescriptor);

	UFUNCTION(BlueprintCallable)
	void AddStacks(const TArray<FInventoryStack>& InInventoryStacks);

	UFUNCTION(BlueprintCallable)
	void AddDescriptors(const TArray<TSubclassOf<UFGItemDescriptor>>& InItemDescriptors);

	UFUNCTION(BlueprintCallable)
	void ClearAndAddStacks(const TArray<FInventoryStack>& InInventoryStacks);

	UFUNCTION(BlueprintCallable)
	void ClearAndAddDescriptors(const TArray<TSubclassOf<UFGItemDescriptor>>& InItemDescriptors);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	UUserWidget* ConstructSlotWidget(const FInventoryStack& InInventoryStack);
};

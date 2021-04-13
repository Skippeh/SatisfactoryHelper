#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/HorizontalBox.h"
#include "FGInventoryComponent.h"
#include "ItemSlotGridBase.generated.h"

UCLASS(Abstract)
class UItemSlotGridBase : public UHorizontalBox
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AddStack(const FInventoryStack& InInventoryStack);

	UFUNCTION(BlueprintCallable)
	void AddDescriptor(TSubclassOf<UFGItemDescriptor> ItemDescriptor);

	UFUNCTION(BlueprintCallable)
	void AddItemAmount(const FItemAmount& InItemAmount);

	UFUNCTION(BlueprintCallable)
	void AddStacks(const TArray<FInventoryStack>& InInventoryStacks);

	UFUNCTION(BlueprintCallable)
	void AddDescriptors(const TArray<TSubclassOf<UFGItemDescriptor>>& InItemDescriptors);

	UFUNCTION(BlueprintCallable)
	void AddItemAmounts(const TArray<FItemAmount>& InItemAmounts);

	UFUNCTION(BlueprintCallable)
	void ClearAndAddStacks(const TArray<FInventoryStack>& InInventoryStacks);

	UFUNCTION(BlueprintCallable)
	void ClearAndAddDescriptors(const TArray<TSubclassOf<UFGItemDescriptor>>& InItemDescriptors);

	UFUNCTION(BlueprintCallable)
	void ClearAndAddItemAmounts(const TArray<FItemAmount>& InItemAmounts);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	UUserWidget* ConstructSlotWidget(const FInventoryStack& InInventoryStack);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float HorizontalSlotPadding = 0;
};

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI/FGInteractWidget.h"
#include "ItemsWindowWidgetBase.generated.h"

typedef TTuple<class UCollapsableWidgetBase*, class USHItemInfo*> TInfoPanelEntry;

struct FSearchResult
{
	int32 Score;
	UDescriptorReference* DescriptorReference;

	FSearchResult(int32 score, UDescriptorReference* descriptorReference)
		: Score(score)
	{
		DescriptorReference = descriptorReference;
	}
};

UCLASS(Abstract, Blueprintable)
class UItemsWindowWidgetBase : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void ClearItemSelection();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	bool SelectIndex(int32 listIndex, bool bFromPinnedItems);

	UFUNCTION(BlueprintCallable)
	bool ToggleWindowVisibility();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	bool ShowWindow();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	bool HideWindow();

	void NativeOnInitialized() override;

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void RefreshWidgets();

protected:
	// Tries to find the index of the specified item descriptor in the given list. Returns -1 if it's not found or if the specified list's ItemList is not of type TArray<UDescriptorReference>.
	UFUNCTION(BlueprintCallable, BlueprintPure)
	int32 FindItemIndexInList(TSubclassOf<class UFGItemDescriptor> SearchClass, class UListView* ListView);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UWidgetAnimation* FadeInAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UWidgetAnimation* FadeOutAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float FadeInAnimationLength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float FadeOutAnimationLength;

	UFUNCTION(BlueprintNativeEvent)
	void OnToggleWindowVisibility(bool bIsVisible);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UTexture2D* MissingIconTexture;

	UPROPERTY(BlueprintReadOnly)
	class ASHItemInfoSubsystem* ItemInfoSubsystem;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UCollapsableWidgetBase> CollapsableWidgetClass;

	UFUNCTION(BlueprintImplementableEvent)
	UPanelWidget* GetPanelsContainer() const;

	/**
	 * Filters the input array based on the search text and bShowLockedItems. Returns the max search score achieved.
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure)
	UPARAM(DisplayName = "Max Score") int32 FilterItems(FString SearchText, bool bShowLockedItems, const TArray<class UDescriptorReference*>& InItemsArray, TArray<class UDescriptorReference*>& OutItemsArray) const;

	UFUNCTION(BlueprintCallable)
	void UpdateItemView(TSubclassOf<UFGItemDescriptor> DescriptorClass, UImage * ImageWidget, UTextBlock * NameWidget, UTextBlock * DescriptionWidget);

	UFUNCTION(BlueprintCallable)
	void UpdateInfoPanels(TSubclassOf<UFGItemDescriptor> DescriptorClass);

	UFUNCTION(BlueprintCallable)
	void SetShowAllRecipes(bool bShowAllRecipes);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool GetShowAllRecipes();
	
private:
	UPROPERTY()
	FTimerHandle FadeTimerHandle;

	UFUNCTION()
	void OnFadeOutFinished();

	UFUNCTION()
	void OnFadeFinished();

	UPROPERTY()
	bool bIsFading = false;

	UPROPERTY()
	bool bIsVisible = false;

	TArray<TInfoPanelEntry> InfoPanels;

	UPROPERTY()
	class ASHInit* CachedInit;
};

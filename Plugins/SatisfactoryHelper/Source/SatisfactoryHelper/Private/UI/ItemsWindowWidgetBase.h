#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI/FGInteractWidget.h"
#include "ItemsWindowWidgetBase.generated.h"

class UDescriptorReference;
class UFGItemDescriptor;
class UCollapsableWidgetBase;
class USHItemInfo;
class ASHItemInfoSubsystem;
class ASHInit;
typedef TTuple<UCollapsableWidgetBase*, USHItemInfo*> TInfoPanelEntry;

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
	bool SelectIndex(int32 listIndex, bool bFromPinnedItems, UDescriptorReference*& DescriptorReference);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	bool SelectDescriptorReference(UDescriptorReference* DescriptorReference, bool bFromPinnedItems);

	UFUNCTION(BlueprintCallable)
	bool ToggleWindowVisibility();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	bool ShowWindow();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	bool HideWindow();

	virtual void NativeOnInitialized() override;

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void RefreshWidgets();

protected:
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
	ASHItemInfoSubsystem* ItemInfoSubsystem;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UCollapsableWidgetBase> CollapsableWidgetClass;

	UFUNCTION(BlueprintImplementableEvent)
	UPanelWidget* GetPanelsContainer() const;

	/**
	 * Filters the input array based on the search text and bShowLockedItems. Returns the max search score achieved.
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure)
	UPARAM(DisplayName = "Max Score") int32 FilterItems(FString SearchText, bool bShowLockedItems, const TArray<UDescriptorReference*>& InItemsArray, TArray<UDescriptorReference*>& OutItemsArray) const;

	UFUNCTION(BlueprintCallable)
	void UpdateItemView(UDescriptorReference* DescriptorReference, UImage* ImageWidget, UTextBlock* NameWidget, UTextBlock* DescriptionWidget, UWidgetSwitcher* PinnedItemSwitcher, bool bUpdateInfoPanels = true);

	UFUNCTION(BlueprintCallable)
	void UpdateInfoPanels(TSubclassOf<UFGItemDescriptor> DescriptorClass);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool GetShowAllRecipes();

	UFUNCTION(BlueprintNativeEvent)
	void OnFadeOutFinished();

	UFUNCTION(BlueprintNativeEvent)
	void OnFadeFinished();
	
private:
	UPROPERTY()
	FTimerHandle FadeTimerHandle;

	UPROPERTY()
	bool bIsFading = false;

	UPROPERTY()
	bool bIsVisible = false;

	TArray<TInfoPanelEntry> InfoPanels;

	UPROPERTY()
	ASHInit* CachedInit;
};

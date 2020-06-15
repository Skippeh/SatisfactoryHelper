#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI/FGInteractWidget.h"
#include "ItemsWindowWidgetBase.generated.h"

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
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void ClearItemSelection();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	bool SelectItem(TSubclassOf<class UFGItemDescriptor> searchClass);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	bool SelectIndex(int32 listIndex);

	UFUNCTION(BlueprintCallable)
	bool ToggleWindowVisibility();

	UFUNCTION(BlueprintCallable)
	bool ShowWindow();

	UFUNCTION(BlueprintCallable)
	bool HideWindow();

	void InitializeWindow();

protected:
	// Tries to find the index of the specified item descriptor in the given list. Returns -1 if it's not found or if the specified list's ItemList is not of type TArray<UDescriptorReference>.
	UFUNCTION(BlueprintCallable, BlueprintPure)
	int32 FindItemIndexInList(TSubclassOf<class UFGItemDescriptor> searchClass, class UListView* inListView);

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
	
private:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	void FilterItems(FString searchText, const TArray<class UDescriptorReference*>& inItemsArray, TArray<class UDescriptorReference*>& outItemsArray) const;

	UFUNCTION(BlueprintCallable)
	void UpdateItemView(TSubclassOf<class UFGItemDescriptor> descriptorClass, class UImage* imageWidget, class UTextBlock* nameWidget, class UTextBlock* descriptionWidget);

	FTimerHandle FadeTimerHandle;

	void OnFadeOutFinished();
	void OnFadeFinished();

	bool bIsFading = false;
	bool bIsVisible = false;
};

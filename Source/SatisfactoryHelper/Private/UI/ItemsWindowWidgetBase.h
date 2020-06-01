#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
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
	
private:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	void FilterItems(FString searchText, const TArray<class UDescriptorReference*>& inItemsArray, TArray<class UDescriptorReference*>& outItemsArray);
};

#include "ItemsWindowWidgetBase.h"
#include "UI/DescriptorReference.h"
#include "Resources/FGItemDescriptor.h"
#include "Components/ListView.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "util/Logging.h"

#pragma region Empty blueprint implementations
void UItemsWindowWidgetBase::ClearItemSelection_Implementation() { }
bool UItemsWindowWidgetBase::SelectItem_Implementation(TSubclassOf<UFGItemDescriptor> searchClass) { unimplemented(); return bool(); }
bool UItemsWindowWidgetBase::SelectIndex_Implementation(int32 listIndex) { unimplemented(); return bool(); }
#pragma endregion

void UItemsWindowWidgetBase::FilterItems(FString searchText, const TArray<UDescriptorReference*>& inItemsArray, TArray<UDescriptorReference*>& outItemsArray)
{
	searchText.TrimStartAndEndInline();

	if (searchText.IsEmpty())
	{
		outItemsArray.Append(inItemsArray);
		return;
	}

	TArray<FSearchResult> searchArray;

	for (UDescriptorReference* descriptorReference : inItemsArray)
	{
		FString itemName = UFGItemDescriptor::GetItemName(descriptorReference->ItemDescriptorClass).ToLower().ToString();
		FString itemDescription = UFGItemDescriptor::GetItemDescription(descriptorReference->ItemDescriptorClass).ToLower().ToString();
		int32 score = 0;

		if (itemName.Equals(searchText, ESearchCase::IgnoreCase))
			score += 4;

		if (itemName.StartsWith(searchText, ESearchCase::IgnoreCase))
			score += 2;

		if (itemName.Contains(searchText, ESearchCase::IgnoreCase) || itemDescription.Contains(searchText, ESearchCase::IgnoreCase))
			score += 1;

		if (score > 0)
		{
			searchArray.Add(FSearchResult(score, descriptorReference));
		}
	}

	searchArray.Sort([](const FSearchResult& a, const FSearchResult& b)
	{
		if (a.Score != b.Score)
			return a.Score > b.Score;

		FString itemAName = UFGItemDescriptor::GetItemName(a.DescriptorReference->ItemDescriptorClass).ToString();
		FString itemBName = UFGItemDescriptor::GetItemName(b.DescriptorReference->ItemDescriptorClass).ToString();

		return itemAName < itemBName;
	});

	for (FSearchResult& searchResult : searchArray)
	{
		outItemsArray.Add(searchResult.DescriptorReference);
	}
}

int32 UItemsWindowWidgetBase::FindItemIndexInList(TSubclassOf<class UFGItemDescriptor> searchClass, UListView* inListView)
{
	// todo: implement
	return -1;
}

void UItemsWindowWidgetBase::UpdateItemView(TSubclassOf<UFGItemDescriptor> descriptorClass, UImage* imageWidget, UTextBlock* nameWidget, UTextBlock* descriptionWidget)
{
	nameWidget->SetText(UFGItemDescriptor::GetItemName(descriptorClass));
	descriptionWidget->SetText(UFGItemDescriptor::GetItemDescription(descriptorClass));
	imageWidget->Brush.SetResourceObject(UFGItemDescriptor::GetBigIcon(descriptorClass));
}

bool UItemsWindowWidgetBase::ShowWindow()
{
	if (bIsFading || IsInViewport())
		return false;

	SML::Logging::debug(*FString::Printf(TEXT("FadeIn IsValid: %d"), IsValid(FadeInAnimation)));
	AddToViewport(1000);
	PlayAnimation(FadeInAnimation);
	GetOuter()->GetWorld()->GetTimerManager().SetTimer(FadeTimerHandle, this, &UItemsWindowWidgetBase::OnFadeFinished, FadeInAnimationLength);
	bIsFading = true;
	return true;
}

bool UItemsWindowWidgetBase::HideWindow()
{
	if (bIsFading || !IsInViewport())
		return false;
	
	PlayAnimation(FadeOutAnimation);
	GetOuter()->GetWorld()->GetTimerManager().SetTimer(FadeTimerHandle, this, &UItemsWindowWidgetBase::OnFadeOutFinished, FadeOutAnimationLength);
	bIsFading = true;
	return true;
}

bool UItemsWindowWidgetBase::ToggleWindowVisibility()
{
	if (bIsFading)
		return false;

	if (IsInViewport())
		return HideWindow();
	else
		return ShowWindow();
}

void UItemsWindowWidgetBase::OnFadeFinished()
{
	bIsFading = false;
}

void UItemsWindowWidgetBase::OnFadeOutFinished()
{
	OnFadeFinished();
	RemoveFromViewport();
}
#include "ItemsWindowWidgetBase.h"
#include "UI/DescriptorReference.h"
#include "Resources/FGItemDescriptor.h"

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

		if (itemName.Contains(searchText, ESearchCase::IgnoreCase))
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
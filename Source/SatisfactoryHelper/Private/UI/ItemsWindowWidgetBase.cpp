#include "ItemsWindowWidgetBase.h"
#include "UI/DescriptorReference.h"
#include "Resources/FGItemDescriptor.h"
#include "Components/ListView.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "util/Logging.h"
#include "SHInit.h"
#include "UI/UIManager.h"

#pragma region Empty blueprint implementations
void UItemsWindowWidgetBase::ClearItemSelection_Implementation() { unimplemented(); }
bool UItemsWindowWidgetBase::SelectItem_Implementation(TSubclassOf<UFGItemDescriptor> searchClass) { unimplemented(); return bool(); }
bool UItemsWindowWidgetBase::SelectIndex_Implementation(int32 listIndex) { unimplemented(); return bool(); }
void UItemsWindowWidgetBase::OnToggleWindowVisibility_Implementation(bool bIsVisible) { }
#pragma endregion

void UItemsWindowWidgetBase::FilterItems(FString SearchText, const TArray<UDescriptorReference*>& InItemsArray, TArray<UDescriptorReference*>& OutItemsArray) const
{
	SearchText.TrimStartAndEndInline();

	if (SearchText.IsEmpty())
	{
		OutItemsArray.Append(InItemsArray);
		return;
	}

	TArray<FSearchResult> SearchArray;

	for (UDescriptorReference* DescriptorReference : InItemsArray)
	{
		FString ItemName = UFGItemDescriptor::GetItemName(DescriptorReference->ItemDescriptorClass).ToString();
		FString ItemDescription = UFGItemDescriptor::GetItemDescription(DescriptorReference->ItemDescriptorClass).ToString();
		int32 Score = 0;
		int32 ItemNameIndex = 0;
		int32 ConsecutiveChars = 0;

		for (int32 SearchTextIndex = 0; SearchTextIndex < SearchText.Len(); /* increment i conditionally in loop */ )
		{
			// If search text is longer than item name skip this item
			if (SearchTextIndex >= ItemName.Len())
			{
				Score = 0;
				break;
			}

			// Create FStrings from TCHAR to support unicode comparison
			FString NameChar;
			NameChar.AppendChar(ItemName[ItemNameIndex]);
			FString SearchChar;
			SearchChar.AppendChar(SearchText[SearchTextIndex]);

			if (NameChar.Equals(SearchChar, ESearchCase::IgnoreCase))
			{
				if (ItemNameIndex == SearchTextIndex)
					++Score;

				++SearchTextIndex;
				++Score;
				++ConsecutiveChars;

				if (ConsecutiveChars >= 2)
					++Score;
			}
			else
			{
				ConsecutiveChars = 0;
			}

			++ItemNameIndex;

			// Break out of loop if the current item char index is >= item name length
			if (ItemNameIndex >= ItemName.Len())
				break;
		}

		if (Score > 0)
		{
			SearchArray.Add(FSearchResult(Score, DescriptorReference));
		}
	}

	SearchArray.Sort([](const FSearchResult& a, const FSearchResult& b)
	{
		if (a.Score != b.Score)
			return a.Score > b.Score;

		FString ItemAName = UFGItemDescriptor::GetItemName(a.DescriptorReference->ItemDescriptorClass).ToString();
		FString ItemBName = UFGItemDescriptor::GetItemName(b.DescriptorReference->ItemDescriptorClass).ToString();

		return ItemAName < ItemBName;
	});

	for (FSearchResult& SearchResult : SearchArray)
	{
		OutItemsArray.Add(SearchResult.DescriptorReference);
	}
}

int32 UItemsWindowWidgetBase::FindItemIndexInList(TSubclassOf<class UFGItemDescriptor> searchClass, UListView* inListView)
{
	// todo: implement
	unimplemented();
	return -1;
}

void UItemsWindowWidgetBase::UpdateItemView(TSubclassOf<UFGItemDescriptor> descriptorClass, UImage* imageWidget, UTextBlock* nameWidget, UTextBlock* descriptionWidget)
{
	if (!IsValid(descriptorClass))
		return;

	nameWidget->SetText(UFGItemDescriptor::GetItemName(descriptorClass));
	descriptionWidget->SetText(UFGItemDescriptor::GetItemDescription(descriptorClass));

	UTexture2D* BigIcon = UFGItemDescriptor::GetBigIcon(descriptorClass);

	if (!IsValid(BigIcon))
	{
		BigIcon = MissingIconTexture;
	}

	imageWidget->Brush.SetResourceObject(BigIcon);
	imageWidget->Brush.ImageSize = FVector2D(BigIcon->GetSizeX(), BigIcon->GetSizeY());
}

bool UItemsWindowWidgetBase::ShowWindow()
{
	if (bIsFading || bIsVisible)
		return false;

	if (!IsInViewport())
		AddToViewport(1000);

	SetVisibility(ESlateVisibility::Visible);

	if (IsValid(FadeInAnimation))
		PlayAnimation(FadeInAnimation);

	ASHInit::GetSingleton()->GetUIManager()->ToggleCursor(true);
	GetOuter()->GetWorld()->GetTimerManager().SetTimer(FadeTimerHandle, this, &UItemsWindowWidgetBase::OnFadeFinished, IsValid(FadeInAnimation) ? FadeInAnimationLength : 0);
	bIsFading = true;
	bIsVisible = true;
	OnToggleWindowVisibility(false);
	return true;
}

bool UItemsWindowWidgetBase::HideWindow()
{
	if (bIsFading || !bIsVisible)
		return false;
	
	if (IsValid(FadeOutAnimation))
		PlayAnimation(FadeOutAnimation);

	ASHInit::GetSingleton()->GetUIManager()->ToggleCursor(false);
	GetOuter()->GetWorld()->GetTimerManager().SetTimer(FadeTimerHandle, this, &UItemsWindowWidgetBase::OnFadeOutFinished, IsValid(FadeOutAnimation) ? FadeOutAnimationLength : 0);
	bIsFading = true;
	bIsVisible = false;
	OnToggleWindowVisibility(false);
	return true;
}

bool UItemsWindowWidgetBase::ToggleWindowVisibility()
{
	if (bIsFading)
		return false;

	if (bIsVisible)
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
	SetVisibility(ESlateVisibility::Hidden);
}
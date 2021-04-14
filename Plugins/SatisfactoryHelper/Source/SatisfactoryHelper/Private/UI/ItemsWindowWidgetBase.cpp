#include "ItemsWindowWidgetBase.h"
#include "UI/DescriptorReference.h"
#include "Resources/FGItemDescriptor.h"
#include "Components/ListView.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "SHConfigStruct.h"
#include "ConfigManager.h"
#include "SHInit.h"
#include "UI/UIManager.h"
#include "FGHUD.h"
#include "SHItemInfoSubsystem.h"
#include "UI/ItemInfos/SHItemInfo.h"
#include "UI/Partials/CollapsableWidgetBase.h"
#include "SHBlueprintFunctionLibrary.h"
#include "FGRecipeManager.h"
#include "SHRecipeHelper.h"
#include "DescriptorReference.h"
#include "Tooltip/ItemTooltipSubsystem.h"
#include "SHModule.h"

#pragma region Empty blueprint implementations
void UItemsWindowWidgetBase::OnToggleWindowVisibility_Implementation(bool bIsVisible) { }
#pragma endregion

void UItemsWindowWidgetBase::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	verify(IsValid(CollapsableWidgetClass));

	ItemInfoSubsystem = USHBlueprintFunctionLibrary::GetItemInfoSubsystem(GetWorld());

	verify(IsValid(ItemInfoSubsystem));

	TArray<TSubclassOf<USHItemInfo>> InfoClasses;
	ItemInfoSubsystem->GetItemInfoClasses(InfoClasses, true);

	UE_LOG(LogSatisfactoryHelper, Log, TEXT("Initializing %d panels..."), InfoClasses.Num());
	UPanelWidget* PanelsContainer = GetPanelsContainer();

	for (auto InfoClass : InfoClasses)
	{
		UE_LOG(LogSatisfactoryHelper, Log, TEXT("Initializing: %s"), *InfoClass.Get()->GetName());

		UCollapsableWidgetBase* CollapsableWidget = CreateWidget<UCollapsableWidgetBase, UWidget>(this, CollapsableWidgetClass);
		USHItemInfo* InfoWidget = CreateWidget<USHItemInfo, UWidget>(CollapsableWidget, InfoClass);

		CollapsableWidget->SetContent(InfoWidget);
		CollapsableWidget->SetTitle(InfoWidget->GetTitle());
		CollapsableWidget->SetVisibility(ESlateVisibility::Collapsed);

		if (InfoClass.GetDefaultObject()->GetCollapsedByDefault())
		{
			CollapsableWidget->Collapse();
		}

		PanelsContainer->AddChild(CollapsableWidget);

		TInfoPanelEntry Entry(CollapsableWidget, InfoWidget);
		InfoPanels.Add(Entry);
	}
}

int32 UItemsWindowWidgetBase::FilterItems(FString SearchText, bool bShowLockedItems, const TArray<UDescriptorReference*>& InItemsArray, TArray<UDescriptorReference*>& OutItemsArray) const
{
	SearchText.TrimStartAndEndInline();
	TArray<FSearchResult> SearchArray;
	int32 MaxScore = 0;

	if (SearchText.IsEmpty())
	{
		for (UDescriptorReference* DescriptorReference : InItemsArray)
		{
			SearchArray.Add(FSearchResult(1, DescriptorReference));
		}
	}
	else
	{
		for (UDescriptorReference* DescriptorReference : InItemsArray)
		{
			FString ItemName = UFGItemDescriptor::GetItemName(DescriptorReference->ItemDescriptorClass).ToString();
			FString ItemDescription = UFGItemDescriptor::GetItemDescription(DescriptorReference->ItemDescriptorClass).ToString();
			int32 Score = 0;
			int32 ItemNameIndex = 0;
			int32 ConsecutiveChars = 0;

			for (int32 SearchTextIndex = 0; SearchTextIndex < SearchText.Len(); /* increment i conditionally in loop */)
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

				if (Score > MaxScore)
					MaxScore = Score;
			}
		}
	}

	TArray<FSearchResult> AvailableItems;

	if (!bShowLockedItems)
	{
		for (const FSearchResult& SearchResult : SearchArray)
		{
			if (USHRecipeHelper::IsItemUnlocked(GetOuter(), SearchResult.DescriptorReference->ItemDescriptorClass))
			{
				AvailableItems.Add(SearchResult);
			}
		}
	}
	else
	{
		AvailableItems = SearchArray;
	}

	AvailableItems.Sort([](const FSearchResult& a, const FSearchResult& b)
	{
		if (a.Score != b.Score)
			return a.Score > b.Score;

		FString ItemAName = UFGItemDescriptor::GetItemName(a.DescriptorReference->ItemDescriptorClass).ToString();
		FString ItemBName = UFGItemDescriptor::GetItemName(b.DescriptorReference->ItemDescriptorClass).ToString();

		return ItemAName < ItemBName;
	});

	for (FSearchResult& SearchResult : AvailableItems)
	{
		OutItemsArray.Add(SearchResult.DescriptorReference);
	}

	return MaxScore;
}

void UItemsWindowWidgetBase::UpdateItemView(UDescriptorReference* DescriptorReference, UImage* ImageWidget, UTextBlock* NameWidget, UTextBlock* DescriptionWidget, UWidgetSwitcher* PinnedItemSwitcher, bool bUpdateInfoPanels)
{
	if (!IsValid(DescriptorReference))
		return;

	auto DescriptorClass = DescriptorReference->ItemDescriptorClass;

	auto TooltipSubsystem = GetWorld()->GetGameInstance()->GetSubsystem<UItemTooltipSubsystem>();
	FText ItemName = TooltipSubsystem->GetItemName(GetOwningPlayer(), FInventoryStack(1, DescriptorClass));
	FText ItemDescription = TooltipSubsystem->GetItemDescription(GetOwningPlayer(), FInventoryStack(1, DescriptorClass));
	NameWidget->SetText(ItemName);
	DescriptionWidget->SetText(ItemDescription);

	UTexture2D* BigIcon = UFGItemDescriptor::GetBigIcon(DescriptorClass);

	if (!IsValid(BigIcon))
	{
		BigIcon = MissingIconTexture;
	}

	ImageWidget->Brush.SetResourceObject(BigIcon);
	ImageWidget->Brush.ImageSize = FVector2D(BigIcon->GetSizeX(), BigIcon->GetSizeY());

	PinnedItemSwitcher->SetActiveWidgetIndex(DescriptorReference->bIsPinned ? 1 : 0);

	if (bUpdateInfoPanels)
		UpdateInfoPanels(DescriptorClass);
}

void UItemsWindowWidgetBase::UpdateInfoPanels(TSubclassOf<UFGItemDescriptor> DescriptorClass)
{
	if (!IsValid(DescriptorClass))
		return;

	for (const TInfoPanelEntry& PanelEntry : InfoPanels)
	{
		auto CollapsableWidget = PanelEntry.Key;
		auto ItemInfo = PanelEntry.Value;

		if (ItemInfo->SetItemDescriptor(DescriptorClass))
		{
			CollapsableWidget->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
		}
		else
		{
			CollapsableWidget->SetVisibility(ESlateVisibility::Collapsed);
		}
	}
}

bool UItemsWindowWidgetBase::ShowWindow_Implementation()
{
	if (bIsFading || bIsVisible)
		return false;

	SetVisibility(ESlateVisibility::Visible);

	if (IsValid(FadeInAnimation))
		PlayAnimation(FadeInAnimation);

	ASHInit::GetSingleton(GetOuter()->GetWorld())->GetUIManager()->ToggleCursor(true);
	GetOuter()->GetWorld()->GetTimerManager().SetTimer(FadeTimerHandle, this, &UItemsWindowWidgetBase::OnFadeFinished, IsValid(FadeInAnimation) ? FadeInAnimationLength : 0);
	bIsFading = true;
	bIsVisible = true;
	OnToggleWindowVisibility(true);
	return true;
}

bool UItemsWindowWidgetBase::HideWindow_Implementation()
{
	if (bIsFading || !bIsVisible)
		return false;
	
	if (IsValid(FadeOutAnimation))
		PlayAnimation(FadeOutAnimation);

	ASHInit::GetSingleton(GetOuter()->GetWorld())->GetUIManager()->ToggleCursor(false);
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

void UItemsWindowWidgetBase::OnFadeFinished_Implementation()
{
	bIsFading = false;
}

void UItemsWindowWidgetBase::OnFadeOutFinished_Implementation()
{
	OnFadeFinished();
	SetVisibility(ESlateVisibility::Collapsed);
}

bool UItemsWindowWidgetBase::GetShowAllRecipes()
{
	const auto Config = FSHConfigStruct::GetActiveConfig();
	return Config.PersonalSettings.bShowAllRecipes;
}
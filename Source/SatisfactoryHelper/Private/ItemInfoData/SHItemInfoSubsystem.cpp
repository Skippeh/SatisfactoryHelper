#include "SHItemInfoSubsystem.h"
#include "SHItemInfo.h"
#include "SHInit.h"
#include "Content/ContentManager.h"
#include "Resources/FGItemDescriptor.h"
#include "util/Logging.h"
#include "SHBlueprintFunctionLibrary.h"

USHItemData* ASHItemInfoSubsystem::GetItemData(TSubclassOf<UFGItemDescriptor> DescriptorClass, TSubclassOf<USHItemData> ItemDataClass)
{
	verify(IsValid(DescriptorClass));
	verify(IsValid(ItemDataClass));
	verify(!ItemDataClass->HasAnyClassFlags(CLASS_Abstract));

	FCachedItemData& CachedData = CachedItemDataMap.FindOrAdd(DescriptorClass);
	USHItemData* ItemData = nullptr;
	USHItemData** ExistingDataPtr = CachedData.Map.Find(ItemDataClass);

	if (ExistingDataPtr != nullptr)
		ItemData = *ExistingDataPtr;

	if (ItemData == nullptr)
	{
		ItemData = NewObject<USHItemData>(this, ItemDataClass);

		if (!ItemData->SupportsItemDescriptor(DescriptorClass))
		{
			SML::Logging::debug(*FString::Printf(TEXT("%s does not support item descriptor %s"), *ItemDataClass->GetName(), *USHBlueprintFunctionLibrary::GetClassInheritancePathString(DescriptorClass)));
			return nullptr;
		}

		ItemData->SetPropertiesFromItemDescriptor(DescriptorClass);
		CachedData.Map.Add(ItemDataClass, ItemData);
	}

	return ItemData;
}

void ASHItemInfoSubsystem::GetItemInfoClasses(TArray<TSubclassOf<USHItemInfo>>& OutArray, bool bSortByPriorityAndTitle)
{
	OutArray.Append(ItemInfoClasses);

	if (bSortByPriorityAndTitle)
	{
		OutArray.Sort([](const TSubclassOf<USHItemInfo>& A, const TSubclassOf<USHItemInfo>& B)
		{
			auto DefaultObjectA = Cast<USHItemInfo>(A->GetDefaultObject());
			auto DefaultObjectB = Cast<USHItemInfo>(B->GetDefaultObject());
			int32 Delta = DefaultObjectA->GetListPriority() - DefaultObjectB->GetListPriority();

			if (Delta == 0)
			{
				return DefaultObjectA->GetTitle().ToString() < DefaultObjectB->GetTitle().ToString();
			}
			else
			{
				return Delta > 0;
			}
		});
	}
}

bool ASHItemInfoSubsystem::RegisterItemInfoClass(TSubclassOf<class USHItemInfo> ItemInfoClass)
{
	if (ItemInfoClasses.Contains(ItemInfoClass))
		return false;

	if (ItemInfoClass->HasAnyClassFlags(CLASS_Abstract))
		return false;

	if (ItemInfoClass->HasAnyClassFlags(CLASS_Deprecated))
	{
		SML::Logging::debug(*FString::Printf(TEXT("Warning: Registering deprecated ItemInfo class: %s"), *ItemInfoClass->GetName()));
	}

	ItemInfoClasses.Add(ItemInfoClass);
	return true;
}

int32 ASHItemInfoSubsystem::RegisterItemInfoClasses(const TArray<TSubclassOf<USHItemInfo>>& InItemInfoClasses)
{
	int32 NumRegisteredClasses = 0;

	for (auto Class : InItemInfoClasses)
	{
		if (RegisterItemInfoClass(Class))
			++NumRegisteredClasses;
	}

	return NumRegisteredClasses;
}
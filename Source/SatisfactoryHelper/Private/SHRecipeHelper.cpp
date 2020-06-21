#include "SHRecipeHelper.h"
#include "Resources/FGItemDescriptor.h"
#include "FGRecipe.h"
#include "Content/ContentManager.h"
#include "util/Logging.h"
#include "FGBuildable.h"
#include "FGBuildGun.h"
#include "FGWorkBench.h"
#include "SHBlueprintFunctionLibrary.h"

TArray<TSubclassOf<UFGRecipe>> USHRecipeHelper::FindRecipesByProduct(UObject* WorldContextObject, TSubclassOf<UFGItemDescriptor> ItemDescriptor)
{
	TArray<TSubclassOf<UFGRecipe>> ResultArray;
	TArray<TSubclassOf<UFGRecipe>> AllRecipes;
	UContentManager::GetSingleton(WorldContextObject)->GetAllRecipes(AllRecipes);
	
	for (auto Recipe : AllRecipes)
	{
		if (UFGRecipe::GetProducts(Recipe).ContainsByPredicate([ItemDescriptor](const FItemAmount& ItemAmount)
		{
			return ItemAmount.ItemClass == ItemDescriptor;
		}))
		{
			ResultArray.Add(Recipe);
		}
	}

	return ResultArray;
}

TArray<TSubclassOf<UFGRecipe>> USHRecipeHelper::FindRecipesByIngredient(UObject* WorldContextObject, TSubclassOf<UFGItemDescriptor> ItemDescriptor)
{
	TArray<TSubclassOf<UFGRecipe>> ResultArray;
	TArray<TSubclassOf<UFGRecipe>> AllRecipes;
	UContentManager::GetSingleton(WorldContextObject)->GetAllRecipes(ResultArray);

	for (auto Recipe : AllRecipes)
	{
		if (UFGRecipe::GetIngredients(Recipe).ContainsByPredicate([ItemDescriptor](const FItemAmount& ItemAmount)
		{
			return ItemAmount.ItemClass == ItemDescriptor;
		}))
		{
			ResultArray.Add(Recipe);
		}
	}

	return ResultArray;
}

template<class T>
T InvalidClassSpecified(UClass* Class, T ReturnValue)
{
	SML::Logging::error(*FString::Printf(TEXT("Unknown manufacturer class given: %s"), *(USHBlueprintFunctionLibrary::GetClassInheritancePathString(Class))));
	return ReturnValue;
}

FText USHRecipeHelper::GetManufacturerName(TSubclassOf<UObject> ManufacturerClass)
{
	if (ManufacturerClass->IsChildOf(AFGBuildGun::StaticClass()))
	{
		TSubclassOf<AFGBuildGun> AsBuildGun(ManufacturerClass);
		return FText::FromString(FString(TEXT("Build Gun")));
	}

	if (ManufacturerClass->IsChildOf(AFGBuildable::StaticClass()))
	{
		auto CDO = Cast<AFGBuildable>(ManufacturerClass->GetDefaultObject());
		return CDO->mDisplayName;
	}

	if (ManufacturerClass->IsChildOf(UFGWorkBench::StaticClass()))
	{
		TSubclassOf<UFGWorkBench> AsWorkBench(ManufacturerClass);
		return FText::FromString(FString(TEXT("Workbench")));
	}

	return InvalidClassSpecified<FText>(ManufacturerClass, FText::FromString(FString(TEXT("UNKNOWN_MANUFACTURER_CLASS"))));
}

UTexture2D* USHRecipeHelper::GetManufacturerIcon(TSubclassOf<UObject> ManufacturerClass)
{
	if (ManufacturerClass->IsChildOf(AFGBuildGun::StaticClass()))
	{
		return nullptr; // todo: get icon from build gun item descriptor
	}

	if (ManufacturerClass->IsChildOf(AFGBuildable::StaticClass()))
	{
		auto CDO = Cast<AFGBuildable>(ManufacturerClass->GetDefaultObject());
		return nullptr; // todo: get icon somehow...
	}

	if (ManufacturerClass->IsChildOf(UFGWorkBench::StaticClass()))
	{
		return nullptr; // todo: get icon from workbench item descriptor?
	}

	return InvalidClassSpecified<UTexture2D*>(ManufacturerClass, nullptr);
}
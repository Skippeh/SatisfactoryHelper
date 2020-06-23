#include "SHRecipeHelper.h"
#include "Resources/FGItemDescriptor.h"
#include "FGRecipe.h"
#include "Content/ContentManager.h"
#include "util/Logging.h"
#include "FGBuildable.h"
#include "FGBuildGun.h"
#include "FGWorkBench.h"
#include "SHBlueprintFunctionLibrary.h"
#include "FGRecipeManager.h"

TArray<TSubclassOf<UFGRecipe>> USHRecipeHelper::FindRecipesByProduct(UObject* WorldContextObject, TSubclassOf<UFGItemDescriptor> ItemDescriptor, bool bIncludeLockedRecipes)
{
	TArray<TSubclassOf<UFGRecipe>> ResultArray;
	TArray<TSubclassOf<UFGRecipe>> AllRecipes;

	if (bIncludeLockedRecipes)
		UContentManager::GetSingleton(WorldContextObject)->GetAllRecipes(AllRecipes);
	else
		GetRecipeManager(WorldContextObject)->GetAllAvailableRecipes(AllRecipes);
	
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

TArray<TSubclassOf<UFGRecipe>> USHRecipeHelper::FindRecipesByIngredient(UObject* WorldContextObject, TSubclassOf<UFGItemDescriptor> ItemDescriptor, bool bIncludeLockedRecipes)
{
	TArray<TSubclassOf<UFGRecipe>> ResultArray;
	TArray<TSubclassOf<UFGRecipe>> AllRecipes;

	if (bIncludeLockedRecipes)
		UContentManager::GetSingleton(WorldContextObject)->GetAllRecipes(AllRecipes);
	else
		GetRecipeManager(WorldContextObject)->GetAllAvailableRecipes(AllRecipes);

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

AFGRecipeManager* USHRecipeHelper::RecipeManager = nullptr;
AFGRecipeManager* USHRecipeHelper::GetRecipeManager(UObject* WorldContextObject)
{
	if (!IsValid(RecipeManager))
	{
		RecipeManager = AFGRecipeManager::Get(WorldContextObject);
	}

	return RecipeManager;
}

bool USHRecipeHelper::IsItemUnlocked(UObject* WorldContextObject, TSubclassOf<UFGItemDescriptor> ItemDescriptor)
{
	AFGRecipeManager* RecipeManager = GetRecipeManager(WorldContextObject);
	TArray<TSubclassOf<UFGRecipe>> UnlockedRecipes;
	RecipeManager->GetAllAvailableRecipes(UnlockedRecipes);

	auto ContainsCheck = [ItemDescriptor](const FItemAmount& A)
	{
		return A.ItemClass == ItemDescriptor;
	};

	for (TSubclassOf<UFGRecipe> Recipe : UnlockedRecipes)
	{
		if (UFGRecipe::GetIngredients(Recipe).ContainsByPredicate(ContainsCheck) || UFGRecipe::GetProducts(Recipe).ContainsByPredicate(ContainsCheck))
		{
			return true;
		}
	}

	return false;
}

bool USHRecipeHelper::IsRecipeUnlocked(UObject* WorldContextObject, TSubclassOf<UFGRecipe> Recipe)
{
	AFGRecipeManager* RecipeManager = GetRecipeManager(WorldContextObject);
	TArray<TSubclassOf<UFGRecipe>> UnlockedRecipes;
	RecipeManager->GetAllAvailableRecipes(UnlockedRecipes);
	return UnlockedRecipes.Contains(Recipe);
}
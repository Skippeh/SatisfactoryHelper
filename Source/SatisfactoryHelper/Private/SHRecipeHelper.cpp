#include "SHRecipeHelper.h"
#include "Resources/FGItemDescriptor.h"
#include "FGRecipe.h"
#include "Content/ContentManager.h"
#include "util/Logging.h"

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
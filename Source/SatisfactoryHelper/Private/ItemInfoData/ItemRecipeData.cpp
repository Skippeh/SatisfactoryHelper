#include "ItemRecipeData.h"
#include "Resources/FGBuildDescriptor.h"
#include "FGRecipe.h"
#include "util/Logging.h"
#include "SHRecipeHelper.h"
#include "SHInit.h"
#include "FGBuildableAutomatedWorkBench.h"

static FString AlternateString = FString(TEXT("Alternate"));

void UItemRecipeData::SetPropertiesFromItemDescriptor_Implementation(TSubclassOf<UFGItemDescriptor> ItemDescriptor)
{
	TArray<TSubclassOf<UFGRecipe>> ProducedByArray = bShowByIngredients
		? USHRecipeHelper::FindRecipesByIngredient(GetOuter(), ItemDescriptor, true)
		: USHRecipeHelper::FindRecipesByProduct(GetOuter(), ItemDescriptor, true);
	TMap<TSubclassOf<UObject>, FTempRecipes> MapOfManufacturers;

	// Sort by name
	ProducedByArray.Sort([](const TSubclassOf<UFGRecipe>& A, const TSubclassOf<UFGRecipe>& B)
	{
		return UFGRecipe::GetRecipeName(A).ToString() < UFGRecipe::GetRecipeName(B).ToString();
	});

	// Sort by alternate recipes (show non alternate first)
	ProducedByArray.StableSort([](const TSubclassOf<UFGRecipe>& A, const TSubclassOf<UFGRecipe>& B)
	{
		FString AName = UFGRecipe::GetRecipeName(A).ToString();
		FString BName = UFGRecipe::GetRecipeName(B).ToString();

		if (!AName.StartsWith(AlternateString) && BName.StartsWith(AlternateString))
			return true;

		return false;
	});

	for (TSubclassOf<UFGRecipe> Recipe : ProducedByArray)
	{
		TArray<TSubclassOf<UObject>> RecipeManufacturers = UFGRecipe::GetProducedIn(Recipe);

		for (TSubclassOf<UObject> Manufacturer : RecipeManufacturers)
		{
			if (Manufacturer->IsChildOf(AFGBuildableAutomatedWorkBench::StaticClass())) // Same as normal workbench
				continue;

			FTempRecipes& ManufacturerRecipes = MapOfManufacturers.FindOrAdd(Manufacturer);
			ManufacturerRecipes.Recipes.Add(Recipe);

			if (!UFGRecipe::GetRecipeName(Recipe).ToString().StartsWith(AlternateString))
				ManufacturerRecipes.bContainsDefaultRecipe = true;
		}
	}

	MapOfManufacturers.ValueSort([](const FTempRecipes& A, const FTempRecipes& B)
	{
		return A.bContainsDefaultRecipe > B.bContainsDefaultRecipe;
	});
	
	Manufacturers.Empty();

	for (auto KV : MapOfManufacturers)
	{
		FManufacturerRecipes ManufacturerRecipes(KV.Key, KV.Value.Recipes);
		Manufacturers.Add(ManufacturerRecipes);
	}
}
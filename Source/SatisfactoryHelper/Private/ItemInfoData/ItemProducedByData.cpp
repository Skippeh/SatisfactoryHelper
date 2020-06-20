#include "ItemProducedByData.h"
#include "Resources/FGBuildDescriptor.h"
#include "FGRecipe.h"
#include "util/Logging.h"
#include "SHRecipeHelper.h"

void UItemProducedByData::SetPropertiesFromItemDescriptor_Implementation(TSubclassOf<UFGItemDescriptor> ItemDescriptor)
{
	TArray<TSubclassOf<UFGRecipe>> ProducedByArray = SHRecipeHelper::FindRecipesByProduct(GetOuter(), ItemDescriptor);

	SML::Logging::debug(*FString::Printf(TEXT("Found %d recipes producing %s"), ProducedByArray.Num(), *(UFGItemDescriptor::GetItemName(ItemDescriptor).ToString())));

	TMap<TSubclassOf<UObject>, FRecipes> MapOfManufacturers;

	for (TSubclassOf<UFGRecipe> Recipe : ProducedByArray)
	{
		TArray<TSubclassOf<UObject>> RecipeManufacturers = UFGRecipe::GetProducedIn(Recipe);

		for (TSubclassOf<UObject> Manufacturer : RecipeManufacturers)
		{
			FRecipes ManufacturerRecipes = MapOfManufacturers.FindOrAdd(Manufacturer);
			ManufacturerRecipes.Recipes.Add(Recipe);
		}
	}

	Manufacturers.Empty();
	
	for (auto KV : MapOfManufacturers)
	{
		FManufacturerRecipes ManufacturerRecipes(KV.Key, KV.Value.Recipes);
		Manufacturers.Add(ManufacturerRecipes);
	}
}
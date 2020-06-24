#pragma once

#include "CoreMinimal.h"
#include "SHRecipeHelper.generated.h"

class UFGRecipe;
class UFGItemDescriptor;
class AFGRecipeManager;

/**
 * This class exists to be able to find recipes by various filters. We can't use FGRecipeManager because it only searches through unlocked recipes.
 */
UCLASS(Abstract)
class SATISFACTORYHELPER_API USHRecipeHelper : public UObject
{
	GENERATED_BODY()

public:
	/** Returns all recipes that output the given item. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "SatisfactoryHelper | Recipes")
	static TArray<TSubclassOf<UFGRecipe>> FindRecipesByProduct(UObject* WorldContextObject, TSubclassOf<UFGItemDescriptor> ItemDescriptor, bool bIncludeLockedRecipes);

	/** Returns all recipes that uses the given item as an input/ingredient. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "SatisfactoryHelper | Recipes")
	static TArray<TSubclassOf<UFGRecipe>> FindRecipesByIngredient(UObject* WorldContextObject, TSubclassOf<UFGItemDescriptor> ItemDescriptor, bool bIncludeLockedRecipes);

	/** Gets the manufacturer's name. Input types can be of type TSubclassOf<AFGBuildGun or UFGItemDescriptor or UFGWorkBench> */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "SatisfactoryHelper | Recipes")
	static FText GetManufacturerName(TSubclassOf<UObject> ManufacturerClass);

	/**
	* Gets the manufacturer's icon. Input types can be of type TSubclassOf<AFGBuildGun or UFGItemDescriptor or UFGWorkBench>.
	* Return value may be null.
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "SatisfactoryHelper | Recipes")
	static UTexture2D* GetManufacturerIcon(TSubclassOf<UObject> ManufacturerClass);

	/** Returns true if the given item can be crafted. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "SatisfactoryHelper | Recipes")
	static bool IsItemUnlocked(UObject* WorldContextObject, TSubclassOf<UFGItemDescriptor> ItemDescriptor);

	/** Returns true if the given recipe can be crafted. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "SatisfactoryHelper | Recipes")
	static bool IsRecipeUnlocked(UObject* WorldContextObject, TSubclassOf<UFGRecipe> Recipe);

private:
	static AFGRecipeManager* GetRecipeManager(UObject* WorldContextObject);
};

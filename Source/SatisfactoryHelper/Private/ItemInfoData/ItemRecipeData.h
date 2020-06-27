#pragma once

#include "CoreMinimal.h"
#include "ItemInfoData/SHItemData.h"
#include "ItemRecipeData.generated.h"

class UFGBuildDescriptor;
class UFGRecipe;

struct FTempRecipes
{
	TArray<TSubclassOf<UFGRecipe>> Recipes;
	bool bContainsDefaultRecipe;
};

USTRUCT(BlueprintType)
struct FManufacturerRecipes
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite)
	TSubclassOf<UObject> Manufacturer;

	UPROPERTY(BlueprintReadWrite)
	TArray<TSubclassOf<UFGRecipe>> Recipes;

	FManufacturerRecipes(TSubclassOf<UObject> Manufacturer, TArray<TSubclassOf<UFGRecipe>> InRecipes)
		: Manufacturer(Manufacturer),
		  Recipes(InRecipes)
	{
	}

	FManufacturerRecipes() { }
};

UCLASS(Abstract)
class UItemRecipeData : public USHItemData
{
	GENERATED_BODY()
	
public:
	void SetPropertiesFromItemDescriptor_Implementation(TSubclassOf<UFGItemDescriptor> ItemDescriptor) override;

	UPROPERTY(BlueprintReadOnly)
	TArray<FManufacturerRecipes> Manufacturers;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	bool bShowByIngredients;
};

UCLASS()
class UItemProducedByData : public UItemRecipeData
{
	GENERATED_BODY()

	UItemProducedByData()
	{
		bShowByIngredients = false;
	}
};

UCLASS()
class UItemUsedByData : public UItemRecipeData
{
	GENERATED_BODY()

	UItemUsedByData()
	{
		bShowByIngredients = true;
	}
};
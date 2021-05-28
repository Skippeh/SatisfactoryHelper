#pragma once

#include "CoreMinimal.h"
#include "SHItemData.h"
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
	virtual void SetPropertiesFromItemDescriptor_Implementation(TSubclassOf<UFGItemDescriptor> ItemDescriptor) override;

	UPROPERTY(BlueprintReadOnly)
	TArray<FManufacturerRecipes> Manufacturers;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	bool bShowByIngredients;

	/** If true then only build gun products will be shown, otherwise only non-build gun products will be shown. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	bool bShowBuildGunProducts;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	bool bFilterByBuildGun;
};

UCLASS()
class UItemProducedByData : public UItemRecipeData
{
	GENERATED_BODY()

protected:
	UItemProducedByData()
	{
		bShowByIngredients = false;
		bFilterByBuildGun = true;
		bShowBuildGunProducts = false;
	}
};

UCLASS()
class UItemProducedByBuildGunData : public UItemProducedByData
{
	GENERATED_BODY()

	UItemProducedByBuildGunData()
	{
		bShowByIngredients = false;
		bFilterByBuildGun = true;
		bShowBuildGunProducts = true;
	}
};

UCLASS()
class UItemUsedByData : public UItemRecipeData
{
	GENERATED_BODY()

protected:
	UItemUsedByData()
	{
		bShowByIngredients = true;
		bFilterByBuildGun = true;
		bShowBuildGunProducts = false;
	}
};

UCLASS()
class UItemUsedByBuildGun : public UItemUsedByData
{
	GENERATED_BODY()

	UItemUsedByBuildGun()
	{
		bShowByIngredients = true;
		bFilterByBuildGun = true;
		bShowBuildGunProducts = true;
	}
};
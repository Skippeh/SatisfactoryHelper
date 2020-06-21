#pragma once

#include "CoreMinimal.h"
#include "ItemInfoData/SHItemData.h"
#include "ItemProducedByData.generated.h"

class UFGBuildDescriptor;
class UFGRecipe;

USTRUCT(BlueprintType)
struct FRecipes
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite)
	TArray<TSubclassOf<UFGRecipe>> Recipes;
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

UCLASS()
class UItemProducedByData : public USHItemData
{
	GENERATED_BODY()
	
public:
	void SetPropertiesFromItemDescriptor_Implementation(TSubclassOf<UFGItemDescriptor> ItemDescriptor) override;

	UPROPERTY(BlueprintReadOnly)
	TArray<FManufacturerRecipes> Manufacturers;
};

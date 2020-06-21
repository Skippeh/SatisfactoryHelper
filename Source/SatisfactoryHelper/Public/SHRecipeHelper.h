#pragma once

#include "CoreMinimal.h"
#include "SHRecipeHelper.generated.h"

class UFGRecipe;
class UFGItemDescriptor;

/**
 * This class exists to be able to find recipes by various filters. We can't use FGRecipeManager because it only searches through unlocked recipes.
 */
UCLASS(Abstract)
class SATISFACTORYHELPER_API USHRecipeHelper : public UObject
{
	GENERATED_BODY()

public:
	/** Returns all recipes that output the given item. */
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static TArray<TSubclassOf<UFGRecipe>> FindRecipesByProduct(UObject* WorldContextObject, TSubclassOf<UFGItemDescriptor> ItemDescriptor);
};

#pragma once

#include "CoreMinimal.h"

class UFGRecipe;
class UFGItemDescriptor;

/**
 * This class exists to be able to find recipes by various filters. We can't use FGRecipeManager because it only searches through unlocked recipes.
 */
class SATISFACTORYHELPER_API SHRecipeHelper
{
public:
	static TArray<TSubclassOf<UFGRecipe>> FindRecipesByProduct(UObject* WorldContextObject, TSubclassOf<UFGItemDescriptor> ItemDescriptor);
};

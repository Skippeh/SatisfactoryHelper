#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ContentManager.generated.h"

UCLASS()
class UContentManager : public UObject
{
	GENERATED_BODY()

	~UContentManager();

public:
	UFUNCTION(BlueprintCallable)
	void FindAllDescriptors(TArray<TSubclassOf<class UFGItemDescriptor>>& OutArray, bool bSortByDisplayName);

	UFUNCTION(BlueprintCallable)
	void GetAllRecipes(TArray<TSubclassOf<class UFGRecipe>>& OutArray);

	static UContentManager* GetSingleton(UObject* InWorldContext);

private:
	TArray<TSubclassOf<class UFGItemDescriptor>>* CachedDescriptors;
	TArray<TSubclassOf<class UFGRecipe>>* CachedRecipes;

	template<class TParentClass>
	static void SearchAssetsForChildClasses(UClass* InBaseClass, TArray<TSoftClassPtr<TParentClass>>& OutArray);
};
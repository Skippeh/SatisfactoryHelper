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
	template<class TParentClass>
	UFUNCTION(BlueprintCallable)
	void SearchAssetsForChildClasses(UClass* InBaseClass, TArray<TSoftClassPtr<TParentClass>>& OutArray);

	UFUNCTION(BlueprintCallable)
	void FindAllDescriptors(TArray<TSubclassOf<class UFGItemDescriptor>>& OutArray, bool bSortByDisplayName);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "SatisfactoryHelper | Resources")
	static TArray<TSubclassOf<UFGItemDescriptor>> GetInvalidItemDescriptorClasses();

	static UContentManager* GetSingleton(UObject* InWorldContext);

private:
	TArray<TSubclassOf<class UFGItemDescriptor>>* CachedDescriptors;
};
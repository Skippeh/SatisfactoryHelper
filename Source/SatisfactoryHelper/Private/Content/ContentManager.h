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
	void SearchAssetsForChildClasses(UClass* parent, TArray<TSoftClassPtr<TParentClass>>& outArray);

	UFUNCTION(BlueprintCallable)
	void FindAllDescriptors(TArray<TSoftClassPtr<class UFGItemDescriptor>>& outArray, bool sortByDisplayName);

	static UContentManager* GetSingleton();

private:
	static void InitializeSingleton();
	static UContentManager* Instance;

	TArray<TSoftClassPtr<class UFGItemDescriptor>>* cachedDescriptors;
};
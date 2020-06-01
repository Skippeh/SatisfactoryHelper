#pragma once

#include "CoreMinimal.h"
#include "SHBlueprintFunctionLibrary.generated.h"

class UContentManager;

UCLASS()
class USHBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	USHBlueprintFunctionLibrary() { }
	~USHBlueprintFunctionLibrary() { }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "SatisfactoryHelper")
	static UContentManager* GetContentManager();
};

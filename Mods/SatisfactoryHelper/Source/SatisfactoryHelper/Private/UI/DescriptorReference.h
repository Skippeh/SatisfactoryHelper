#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DescriptorReference.generated.h"

UCLASS(BlueprintType)
class UDescriptorReference : public UObject
{
	GENERATED_BODY()

	UDescriptorReference();

public:
	UPROPERTY(BlueprintReadWrite)
	TSubclassOf<class UFGItemDescriptor> ItemDescriptorClass;
	
	UPROPERTY(BlueprintReadWrite)
	bool bIsPinned;
};
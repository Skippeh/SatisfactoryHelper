#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SHItemData.h"
#include "ItemDebugData.generated.h"

UCLASS()
class UItemDebugData : public USHItemData
{
	GENERATED_BODY()
	
public:
	void SetPropertiesFromItemDescriptor_Implementation(TSubclassOf<UFGItemDescriptor> ItemDescriptor) override;

	UPROPERTY(BlueprintReadOnly)
	FString ClassInheritancePath;

private:
	void UpdateClassInheritancePath(TSubclassOf<class UFGItemDescriptor> Descriptor);
};

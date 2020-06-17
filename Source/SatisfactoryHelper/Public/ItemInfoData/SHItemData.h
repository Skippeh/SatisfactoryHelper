#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Resources/FGItemDescriptor.h"
#include "SHItemData.generated.h"

UCLASS(Abstract, BlueprintType)
class USHItemData : public UObject
{
	GENERATED_BODY()
	
public:
	/** Called when the properties of this instance should be read from the specified item descriptor. */
	UFUNCTION(BlueprintNativeEvent)
	void SetPropertiesFromItemDescriptor(TSubclassOf<UFGItemDescriptor> ItemDescriptor);

protected:
	/** Returns the outer object cast to ItemInfoManager. */
	class ASHItemInfoManager* GetItemInfoManager() const;
};

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Resources/FGItemDescriptor.h"
#include "SHItemData.generated.h"

UCLASS(Abstract, BlueprintType)
class SATISFACTORYHELPER_API USHItemData : public UObject
{
	GENERATED_BODY()
	
public:
	/** Called when the properties of this instance should be set from the specified item descriptor. */
	UFUNCTION(BlueprintNativeEvent)
	void SetPropertiesFromItemDescriptor(TSubclassOf<UFGItemDescriptor> ItemDescriptor);

	/** Returns true if this item data can read information from the specified descriptor class. Default value is true. */
	UFUNCTION(BlueprintNativeEvent)
	bool SupportsItemDescriptor(TSubclassOf<UFGItemDescriptor> DescriptorClass) const;

protected:
	/** Returns the outer object cast to ItemInfoManager. */
	class ASHItemInfoSubsystem* GetItemInfoSubsystem() const;
};

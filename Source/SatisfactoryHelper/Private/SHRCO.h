#pragma once

#include "CoreMinimal.h"
#include "FGRemoteCallObject.h"
#include "SHRCO.generated.h"

UCLASS(BlueprintType)
class USHRCO : public UFGRemoteCallObject
{
	GENERATED_BODY()

public:
	UFUNCTION(Server, WithValidation, Reliable, BlueprintCallable)
	void GiveItem(TSubclassOf<class UFGItemDescriptor> ItemClass, int32 NumItems);

	UFUNCTION(Server, WithValidation, Reliable, BlueprintCallable)
	void TogglePinItem(TSubclassOf<class UFGItemDescriptor> ItemClass, bool bPinItem);

private:
	UPROPERTY(Replicated)
	bool bDummy = true;
};

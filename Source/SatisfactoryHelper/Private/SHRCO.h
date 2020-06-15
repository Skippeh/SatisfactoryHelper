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

	/** Initialize members (server only) */
	void Init();

private:
	UPROPERTY(Replicated)
	bool bDummy = true;

	class ASHCheatSubsystem* CheatsSubsystem;
};

#pragma once

#include "CoreMinimal.h"
#include "ModSubsystem.h"

#include "SHCheatSubsystem.generated.h"

USTRUCT(BlueprintType)
struct FEnabledCheats
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, SaveGame)
	bool bSpawnItemsAllowed;

	UPROPERTY(BlueprintReadWrite, SaveGame)
	bool bSpawnVehiclesWithFuel;

	FEnabledCheats(bool bCheatsEnabled)
		: bSpawnItemsAllowed(bCheatsEnabled),
		  bSpawnVehiclesWithFuel(bCheatsEnabled)
	{
	}

	FEnabledCheats()
		: FEnabledCheats(false)
	{
	}
};

UCLASS()
class ASHCheatSubsystem : public AModSubsystem
{
	GENERATED_BODY()
	
public:
	ASHCheatSubsystem();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FEnabledCheats GetEnabledCheats() const { return EnabledCheats; }

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetEnabledCheats(const FEnabledCheats& EnabledCheats);

private:
	UPROPERTY(Replicated)
	FEnabledCheats EnabledCheats;
};

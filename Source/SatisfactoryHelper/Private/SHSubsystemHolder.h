#pragma once

#include "CoreMinimal.h"
#include "mod/ModSubsystems.h"
#include "SHSubsystemHolder.generated.h"

UCLASS()
class USHSubsystemHolder : public UModSubsystemHolder
{
	GENERATED_BODY()
	
public:
	void InitSubsystems() override;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	class ASHCheatSubsystem* GetCheatSubsystem() const { return CheatSubsystem; }

private:
	class ASHCheatSubsystem* CheatSubsystem;
};

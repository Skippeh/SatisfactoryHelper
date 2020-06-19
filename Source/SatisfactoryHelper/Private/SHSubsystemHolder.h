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
	class ASHItemInfoSubsystem* GetItemInfoSubsystem() const { return ItemInfoSubsystem; }

private:
	class ASHCheatSubsystem* CheatSubsystem;
	class ASHItemInfoSubsystem* ItemInfoSubsystem;
};

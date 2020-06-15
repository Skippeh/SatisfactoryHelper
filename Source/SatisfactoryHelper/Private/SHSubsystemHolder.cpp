#include "SHSubsystemHolder.h"
#include "Subsystems/SHCheatSubsystem.h"

void USHSubsystemHolder::InitSubsystems()
{
	Super::InitSubsystems();
	SpawnSubsystem(CheatSubsystem, ASHCheatSubsystem::StaticClass(), TEXT("CheatSubsystem"));
}
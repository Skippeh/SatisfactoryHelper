#include "SHSubsystemHolder.h"
#include "Subsystems/SHCheatSubsystem.h"
#include "SHItemInfoSubsystem.h"

void USHSubsystemHolder::InitSubsystems()
{
	Super::InitSubsystems();
	SpawnSubsystem(CheatSubsystem, ASHCheatSubsystem::StaticClass(), TEXT("CheatSubsystem"));
	SpawnSubsystem(ItemInfoSubsystem, ASHItemInfoSubsystem::StaticClass(), TEXT("ItemInfoSubsystem"));
}
#include "SHCheatSubsystem.h"
#include "Net/UnrealNetwork.h"

ASHCheatSubsystem::ASHCheatSubsystem()
{
	bReplicates = true; // Need to replicate to client so the client knows if cheats are enabled for certain UI elements
}

void ASHCheatSubsystem::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ASHCheatSubsystem, EnabledCheats);
}

void ASHCheatSubsystem::SetEnabledCheats(const FEnabledCheats& EnabledCheats)
{
	check(HasAuthority());
	this->EnabledCheats = EnabledCheats;
}
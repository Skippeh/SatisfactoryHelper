// This file has been automatically generated by the Unreal Header Implementation tool

#include "Replication/FGReplicationDetailActor_GeneratorFuel.h"
#include "Net/UnrealNetwork.h"

AFGReplicationDetailActor_GeneratorFuel::AFGReplicationDetailActor_GeneratorFuel() : Super() {
	this->mFuelInventory = nullptr;
}
void AFGReplicationDetailActor_GeneratorFuel::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFGReplicationDetailActor_GeneratorFuel, mFuelInventory);
}
void AFGReplicationDetailActor_GeneratorFuel::InitReplicationDetailActor( AFGBuildable* owningActor){ }
void AFGReplicationDetailActor_GeneratorFuel::RemoveDetailActorFromOwner(){ }
void AFGReplicationDetailActor_GeneratorFuel::FlushReplicationActorStateToOwner(){ }
bool AFGReplicationDetailActor_GeneratorFuel::HasCompletedInitialReplication() const{ return bool(); }

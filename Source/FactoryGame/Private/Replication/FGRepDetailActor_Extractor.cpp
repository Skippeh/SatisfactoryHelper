// This file has been automatically generated by the Unreal Header Implementation tool

#include "Replication/FGRepDetailActor_Extractor.h"
#include "Net/UnrealNetwork.h"

AFGRepDetailActor_Extractor::AFGRepDetailActor_Extractor() : Super() {
	this->mOutputInventory = nullptr;
}
void AFGRepDetailActor_Extractor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFGRepDetailActor_Extractor, mOutputInventory);
}
void AFGRepDetailActor_Extractor::InitReplicationDetailActor( AFGBuildable* owningActor){ }
void AFGRepDetailActor_Extractor::RemoveDetailActorFromOwner(){ }
void AFGRepDetailActor_Extractor::FlushReplicationActorStateToOwner(){ }
bool AFGRepDetailActor_Extractor::HasCompletedInitialReplication() const{ return bool(); }

// This file has been automatically generated by the Unreal Header Implementation tool

#include "Creature/Actions/FGCreatureActionLeapGrabAttack.h"

UFGCreatureActionLeapGrabAttack::UFGCreatureActionLeapGrabAttack(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
	this->mMaxGrabTargets = 1;
}
void UFGCreatureActionLeapGrabAttack::CleanupAction_Implementation(bool actionSuccess){ }
void UFGCreatureActionLeapGrabAttack::ProcessHit_Implementation( AFGCharacterBase* character, const FHitResult& hitResult){ }
void UFGCreatureActionLeapGrabAttack::OnCreatureLanded_Implementation(const FHitResult& hitResult){ }
void UFGCreatureActionLeapGrabAttack::OnHitCharacterCleared_Implementation( AFGCharacterBase* character){ }
void UFGCreatureActionLeapGrabAttack::OnGrabbedCharacterDied(AActor* characterActor){ }
void UFGCreatureActionLeapGrabAttack::GrabCharacter( AFGCharacterBase* character){ }
void UFGCreatureActionLeapGrabAttack::DetachCharacter( AFGCharacterBase* character){ }

// This file has been automatically generated by the Unreal Header Implementation tool

#include "Creature/Actions/FGCreatureActionAmmoAttack.h"

UFGCreatureActionAmmoAttack::UFGCreatureActionAmmoAttack(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
	this->mAmmoType = nullptr;
	this->mPredictTargetLocation = false;
	this->mPredictionDistanceMultiplier = 1.0;
	this->mFiringDispersionMultiplier = 1.0;
	this->mProjectileFiringSocketName = TEXT("None");
	this->mLocalFiringOffsetLocation = FVector::ZeroVector;
	this->mLaunchAngleOffset = FRotator::ZeroRotator;
	this->mMagazineObject = nullptr;
	this->mTargetRequirements.TargetType = ECreatureActionTargetSelectionType::RandomWeighted;
	this->mTargetRequirements.VisibilityRequirement = ETargetVisibilityRequirement::TVR_Visible;
	this->mTargetRequirements.MinimumAggro = 0.0;
	this->mCancelsOnStateChange = false;
}
bool UFGCreatureActionAmmoAttack::InitializeAction(AController* controller, APawn* pawn){ return bool(); }
void UFGCreatureActionAmmoAttack::PerformAction_Implementation(){ }
void UFGCreatureActionAmmoAttack::OnAnimNotify_Implementation(const UFGAnimNotify* Notify){ }
void UFGCreatureActionAmmoAttack::InternalActionCleanup(bool actionSuccess){ }
void UFGCreatureActionAmmoAttack::FireProjectile(){ }
void UFGCreatureActionAmmoAttack::OnProjectileFired(AActor* spawnedProjectile){ }

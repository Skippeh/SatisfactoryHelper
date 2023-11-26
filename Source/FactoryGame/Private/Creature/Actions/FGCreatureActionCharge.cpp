// This file has been automatically generated by the Unreal Header Implementation tool

#include "Creature/Actions/FGCreatureActionCharge.h"

UFGCreatureActionCharge::UFGCreatureActionCharge(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
	this->mStopOnImpact = true;
	this->mKnockbackAmount = 1500.0;
	this->mVerticalKnockbackAmount = 800.0;
	this->mChargeSphereTriggerRadius = 200.0;
	this->mChargeMovementSpeed = 2000.0;
	this->mTargetHitCooldown = 1.0;
	this->mDistanceTurnrateCurve.EditorCurveData.DefaultValue = 3.40282e+38;
	this->mDistanceTurnrateCurve.EditorCurveData.PreInfinityExtrap = ERichCurveExtrapolation::RCCE_Constant;
	this->mDistanceTurnrateCurve.EditorCurveData.PostInfinityExtrap = ERichCurveExtrapolation::RCCE_Constant;
	this->mDistanceTurnrateCurve.ExternalCurve = nullptr;
	this->mChargeStartMontage = nullptr;
	this->mChargeMontage = nullptr;
	this->mChargeHitMontage = nullptr;
	this->mTargetRequirements.TargetType = ECreatureActionTargetSelectionType::RandomWeighted;
	this->mTargetRequirements.VisibilityRequirement = ETargetVisibilityRequirement::TVR_Visible;
	this->mTargetRequirements.MinimumAggro = 0.0;
	this->mCancelsOnStateChange = false;
}
void UFGCreatureActionCharge::PerformAction_Implementation(){ }
void UFGCreatureActionCharge::ActionTick_Implementation(float DeltaTime){ }
void UFGCreatureActionCharge::CleanupAction_Implementation(bool ActionSuccess){ }
void UFGCreatureActionCharge::OnAnimationBlendingOut_Implementation( UAnimMontage* montage, bool WasInterrupted){ }
void UFGCreatureActionCharge::BeginCharge_Implementation(){ }
void UFGCreatureActionCharge::EndCharge_Implementation(){ }
void UFGCreatureActionCharge::ProcessHit_Implementation( AFGCharacterBase* HitCharacter, const FHitResult& HitResult){ }
void UFGCreatureActionCharge::OnMovementModeChanged(ACharacter* character, EMovementMode previousMode, uint8 prevCustomMode){ }
void UFGCreatureActionCharge::NetMulticast_BeginCharge_Implementation(){ }
void UFGCreatureActionCharge::NetMulticast_EndCharge_Implementation(){ }
void UFGCreatureActionCharge::OnFall(){ }
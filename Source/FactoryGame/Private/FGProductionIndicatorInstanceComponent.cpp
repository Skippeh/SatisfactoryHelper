// This file has been automatically generated by the Unreal Header Implementation tool

#include "FGProductionIndicatorInstanceComponent.h"

UFGProductionIndicatorInstanceComponent::UFGProductionIndicatorInstanceComponent() : Super() {
	this->mStateNoneData.FlashingPattern = 0;
	this->mStateNoneData.mColor = FLinearColor(0.0, 0.0, 0.0, 0.0);
	this->mStateActiveData.FlashingPattern = 0;
	this->mStateActiveData.mColor = FLinearColor(0.0, 0.0, 0.0, 0.0);
	this->mStateActiveWithCrystalData.FlashingPattern = 0;
	this->mStateActiveWithCrystalData.mColor = FLinearColor(0.0, 0.0, 0.0, 0.0);
	this->mStateErrorData.FlashingPattern = 0;
	this->mStateErrorData.mColor = FLinearColor(0.0, 0.0, 0.0, 0.0);
	this->mStateStandbyData.FlashingPattern = 0;
	this->mStateStandbyData.mColor = FLinearColor(0.0, 0.0, 0.0, 0.0);
	this->mBlockColoring = true;
	this->mNumCustomDataFloats = 4;
	this->bAffectDistanceFieldLighting = false;
}
void UFGProductionIndicatorInstanceComponent::OnProductionStatusChanged(EProductionStatus newStatus){ }
void UFGProductionIndicatorInstanceComponent::ResetIndicatorStatus(){ }
void UFGProductionIndicatorInstanceComponent::SetVisuals(EProductionStatus newStatus){ }

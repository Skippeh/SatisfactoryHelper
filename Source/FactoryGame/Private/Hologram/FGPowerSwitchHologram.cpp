// This file has been automatically generated by the Unreal Header Implementation tool

#include "Hologram/FGPowerSwitchHologram.h"

AFGPowerSwitchHologram::AFGPowerSwitchHologram() : Super() {
	this->mUpgradeTarget = nullptr;
	this->mUseGradualFoundationRotations = true;
}
bool AFGPowerSwitchHologram::IsValidHitResult(const FHitResult& hitResult) const{ return bool(); }
AActor* AFGPowerSwitchHologram::GetUpgradedActor() const{ return nullptr; }
bool AFGPowerSwitchHologram::TryUpgrade(const FHitResult& hitResult){ return bool(); }
void AFGPowerSwitchHologram::ConfigureActor(AFGBuildable* inBuildable) const{ }

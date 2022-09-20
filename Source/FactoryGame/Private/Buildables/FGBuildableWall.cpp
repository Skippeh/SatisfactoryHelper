// This file has been automatically generated by the Unreal Header Implementation tool

#include "Buildables/FGBuildableWall.h"
#include "Hologram/FGWallHologram.h"

AFGBuildableWall::AFGBuildableWall() : Super() {
	this->mWidth = 0.0;
	this->mHeight = 0.0;
	this->mElevation = 0.0;
	this->mAngularDepth = 0.0;
	this->mWallType = EBuildableWallType::BWT_Normal;
	this->mHologramClass = AFGWallHologram::StaticClass();
	this->mAffectsOcclusion = true;
}
void AFGBuildableWall::CalculateLocalSnapOffset(FVector& out_upVector, float& out_length) const{ }

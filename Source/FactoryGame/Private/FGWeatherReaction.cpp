// This file has been automatically generated by the Unreal Header Implementation tool

#include "FGWeatherReaction.h"

AFGWeatherReaction::AFGWeatherReaction() : Super() {
	this->TransitionTime = 30.0;
	this->mSkySphere = nullptr;
	this->PrimaryActorTick.TickGroup = ETickingGroup::TG_PrePhysics;
	this->PrimaryActorTick.EndTickGroup = ETickingGroup::TG_PrePhysics;
	this->PrimaryActorTick.bTickEvenWhenPaused = false;
	this->PrimaryActorTick.bCanEverTick = true;
	this->PrimaryActorTick.bStartWithTickEnabled = false;
	this->PrimaryActorTick.bAllowTickOnDedicatedServer = true;
	this->PrimaryActorTick.TickInterval = 0.0;
}
void AFGWeatherReaction::Tick(float DeltaSeconds){ }
void AFGWeatherReaction::EndPlay(const EEndPlayReason::Type EndPlayReason){ }
void AFGWeatherReaction::StartWeatherState_Implementation(AFGSkySphere* SkySphere){ }
void AFGWeatherReaction::EndWeatherState_Implementation(AFGSkySphere* SkySphere){ }

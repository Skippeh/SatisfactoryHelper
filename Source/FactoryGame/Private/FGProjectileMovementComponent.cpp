// This file has been automatically generated by the Unreal Header Implementation tool

#include "FGProjectileMovementComponent.h"

UFGProjectileMovementComponent::UFGProjectileMovementComponent() : Super() {
	this->mHomingTargetLocation = FVector::ZeroVector;
	this->mHomingTargetDirection = FVector::ZeroVector;
	this->mHasHomingTargetLocation = false;
}
void UFGProjectileMovementComponent::SetHomingTargetLocation(const FVector& targetLocation){ }
void UFGProjectileMovementComponent::ClearHomingTargetLocation(){ }
void UFGProjectileMovementComponent::SetHomingTargetDirection(const FVector& targetDirection){ }
void UFGProjectileMovementComponent::ClearHomingTargetDirection(){ }
FVector UFGProjectileMovementComponent::ComputeAcceleration(const FVector& InVelocity, float DeltaTime) const{ return FVector(); }

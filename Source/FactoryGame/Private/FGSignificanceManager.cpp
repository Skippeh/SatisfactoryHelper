// This file has been automatically generated by the Unreal Header Implementation tool

#include "FGSignificanceManager.h"

UFGSignificanceManager::UFGSignificanceManager() : Super() {
	this->mIsEnabled = true;
}
void UFGSignificanceManager::RegisterSignificanceObject(UObject* Object, EFGSignificanceType SignificanceType){ }
void UFGSignificanceManager::RegisterObject(UObject* Object, FName Tag, FManagedObjectSignificanceFunction SignificanceFunction, EPostSignificanceType InPostSignificanceType , FManagedObjectPostSignificanceFunction InPostSignificanceFunction){ }
void UFGSignificanceManager::UnregisterObject(UObject* Object){ }
void UFGSignificanceManager::Update(TArrayView<const FTransform> Viewpoints){ }
void UFGSignificanceManager::OnSignificanceLoss(UObject* Object, EPostSignificanceType InPostSignificanceType){ }
void UFGSignificanceManager::OnSignificanceGain(UObject* Object, EPostSignificanceType InPostSignificanceType){ }
void UFGSignificanceManager::OnSignificanceTickRateUpdate(UObject* Object, int32 TickLevel, int32 NumTickLevels){ }
float UFGSignificanceManager::GetSignificanceRange(UObject* Object) const{ return float(); }
FVector UFGSignificanceManager::GetObjectLocation(UObject* Object) const{ return FVector(); }
bool UFGSignificanceManager::GetIsTickManaged(UObject* Object) const{ return bool(); }
int32 UFGSignificanceManager::GetNumTickLevels(UObject* Object) const{ return int32(); }
float UFGSignificanceManager::GetTickExponent(UObject* Object) const{ return float(); }
void UFGSignificanceManager::SetIsSignificance(UObject* Object, bool bState){ }
FGainSignificanceData UFGSignificanceManager::GetClosestGainSignificanceData(UObject* inObject, float desiredDistance){ return FGainSignificanceData(); }
void UFGSignificanceManager::DumpSignificanceManagedObjects(){ }
void UFGSignificanceManager::UpdateConveyorBelts(){ }
void UFGSignificanceManager::UpdateFactories(){ }
void UFGSignificanceManager::UpdatePipelines(){ }
void UFGSignificanceManager::UpdateSignificanceStatus(float oldSignificance, float newSignificance, UObject* inObject){ }
FName UFGSignificanceManager::GetTagFromTagEnum(EFGSignificanceType InType){ return FName(); }
void UFGSignificanceManager::OnComponentActivationChange(UParticleSystemComponent* PSC, bool bActivated){ }
float UFGSignificanceManager::GenericTickSignificance(FManagedObjectInfo* Object, const FTransform& Viewpoint){ return float(); }
void UFGSignificanceManager::GenericTickPostSignificance(FManagedObjectInfo* ObjectInfo, float OldSignificance, float NewSignificance, bool bFinal){ }
float UFGSignificanceManager::ParticleTickSignificance(FManagedObjectInfo* Object, const FTransform& Viewpoint){ return float(); }
void UFGSignificanceManager::ParticleTickPostSignificance(FManagedObjectInfo* ObjectInfo, float OldSignificance, float NewSignificance, bool bFinal){ }
float UFGSignificanceManager::FactorySignificance(FManagedObjectInfo* Object, const FTransform& Viewpoint){ return float(); }
void UFGSignificanceManager::FactoryPostSignificance(FManagedObjectInfo* ObjectInfo, float OldSignificance, float NewSignificance, bool bFinal){ }
float UFGSignificanceManager::ConveyorBeltSignificance(FManagedObjectInfo* Object, const FTransform& Viewpoint){ return float(); }
void UFGSignificanceManager::ConveyorBeltPostSignificance(FManagedObjectInfo* ObjectInfo, float OldSignificance, float NewSignificance, bool bFinal){ }
float UFGSignificanceManager::PipelineSignificance(FManagedObjectInfo* Object, const FTransform& Viewpoint){ return float(); }
void UFGSignificanceManager::PipelinePostSignificance(FManagedObjectInfo* ObjectInfo, float OldSignificance, float NewSignificance, bool bFinal){ }
float UFGSignificanceManager::LowDistanceSignificance(FManagedObjectInfo* Object, const FTransform& Viewpoint){ return float(); }
float UFGSignificanceManager::MidDistanceSignificance(FManagedObjectInfo* Object, const FTransform& Viewpoint){ return float(); }
float UFGSignificanceManager::HighDistanceSignificance(FManagedObjectInfo* Object, const FTransform& Viewpoint){ return float(); }
float UFGSignificanceManager::CustomDistanceSignificance(FManagedObjectInfo* Object, const FTransform& Viewpoint){ return float(); }
void UFGSignificanceManager::GainSignificanceOnDistancePostSignificance(FManagedObjectInfo* ObjectInfo, float OldSignificance, float NewSignificance, bool bFinal){ }
float UFGSignificanceManager::AudioVolumeSignificance(FManagedObjectInfo* Object, const FTransform& Viewpoint){ return float(); }
void UFGSignificanceManager::AudioVolumePostSignificance(FManagedObjectInfo* ObjectInfo, float OldSignificance, float NewSignificance, bool bFinal){ }
float UFGSignificanceManager::AmbientSoundSplineSignificance(FManagedObjectInfo* Object, const FTransform& Viewpoint){ return float(); }
void UFGSignificanceManager::AmbientSoundSplinePostSignificance(FManagedObjectInfo* ObjectInfo, float OldSignificance, float NewSignificance, bool bFinal){ }
float UFGSignificanceManager::TrainSignificance(FManagedObjectInfo* Object, const FTransform& Viewpoint){ return float(); }
void UFGSignificanceManager::TrainPostSignificance(FManagedObjectInfo* ObjectInfo, float OldSignificance, float NewSignificance, bool bFinal){ }
FVector UFGSignificanceManager::GetObjectLocation_Old(UObject* obj){ return FVector(); }
void UFGSignificanceManager::SetObjectTickRate(UObject* obj, float newTickRate){ }
void UFGSignificanceManager::SetObjectTicks(UObject* obj, bool newTicks){ }
void UFGSignificanceManager::SetObjectLOD(FManagedObjectInfo* objInfo, int32 newLod){ }

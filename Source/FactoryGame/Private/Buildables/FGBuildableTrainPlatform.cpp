// This file has been automatically generated by the Unreal Header Implementation tool

#include "FGBuildableTrainPlatform.h"

AFGBuildableTrainPlatform::AFGBuildableTrainPlatform(){ }
void AFGBuildableTrainPlatform::GetLifetimeReplicatedProps( TArray<FLifetimeProperty>& OutLifetimeProps) const{ }
void AFGBuildableTrainPlatform::PreSaveGame_Implementation( int32 saveVersion, int32 gameVersion){ }
void AFGBuildableTrainPlatform::PostLoadGame_Implementation( int32 saveVersion, int32 gameVersion){ }
bool AFGBuildableTrainPlatform::CanDismantle_Implementation() const{ return bool(); }
void AFGBuildableTrainPlatform::Dismantle_Implementation(){ }
void AFGBuildableTrainPlatform::GetDismantleRefund_Implementation( TArray< FInventoryStack >& out_refund) const{ }
bool AFGBuildableTrainPlatform::IsUseable_Implementation() const{ return bool(); }
FRailroadTrackPosition AFGBuildableTrainPlatform::GetTrackPosition() const{ return FRailroadTrackPosition(); }
int32 AFGBuildableTrainPlatform::GetTrackGraphID() const{ return int32(); }
AFGBuildableTrainPlatform* AFGBuildableTrainPlatform::GetConnectedPlatformInDirectionOf( uint8 direction){ return nullptr; }
void AFGBuildableTrainPlatform::NotifyTrainDocked(  AFGRailroadVehicle* railroadVehicle,  AFGBuildableRailroadStation* initiatedByStation){ }
void AFGBuildableTrainPlatform::UpdateDockingSequence(){ }
void AFGBuildableTrainPlatform::SetupRailroadTrack(){ }
void AFGBuildableTrainPlatform::FinishDockingSequence(){ }
void AFGBuildableTrainPlatform::OnRep_UpdateDockingStatus(){ }
void AFGBuildableTrainPlatform::ReverseConnectionDirections(){ }
void AFGBuildableTrainPlatform::AssignRailroadTrack(  AFGBuildableRailroadTrack* track){ }
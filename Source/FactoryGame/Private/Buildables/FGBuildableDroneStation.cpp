// This file has been automatically generated by the Unreal Header Implementation tool

#include "Buildables/FGBuildableDroneStation.h"
#include "Replication/FGReplicationDetailInventoryComponent.h"

AFGBuildableDroneStation::AFGBuildableDroneStation() : Super() {
	this->mDroneDockingStartLocationLocal = FVector::ZeroVector;
	this->mDroneDockingLocationLocal = FVector::ZeroVector;
	this->mDroneClass = nullptr;
	this->mUIBatteryCostItemClass = nullptr;
	this->mStationHasDronesInQueue = false;
	this->mRecentlyDockedDrone = nullptr;
	this->mItemTransferringStage = EItemTransferringStage::ITS_NONE;
	this->mTransferProgress = 0.0;
	this->mTransferSpeed = 0.5;
	this->mStackTransferSize = 1.0;
	this->mDroneQueueRadius = 2000.0;
	this->mDroneQueueSeparationRadius = 0.0;
	this->mDroneQueueVerticalSeparation = 1000.0;
	this->mTripPowerCost = 0.0;
	this->mTripPowerPerMeterCost = 0.0;
	this->mTripInformationSampleCount = 3;
	this->mStationDrone = nullptr;
	this->mDockedDrone = nullptr;
	this->mStorageSizeX = 1;
	this->mStorageSizeY = 1;
	this->mBatteryStorageSizeX = 1;
	this->mBatteryStorageSizeY = 1;
	this->mInputInventoryHandler = CreateDefaultSubobject<UFGReplicationDetailInventoryComponent>(TEXT("InputInventoryHandler"));
	this->mOutputInventoryHandler = CreateDefaultSubobject<UFGReplicationDetailInventoryComponent>(TEXT("OutputInventoryHandler"));
	this->mBatteryInventoryHandler = CreateDefaultSubobject<UFGReplicationDetailInventoryComponent>(TEXT("BatteryInventoryHandler"));
	this->mInputInventory = nullptr;
	this->mOutputInventory = nullptr;
	this->mBatteryInventory = nullptr;
	this->mInfo = nullptr;
	this->mTempInfo = nullptr;
	this->mActorRepresentationTexture = nullptr;
	this->mMapText = INVTEXT("");
}
bool AFGBuildableDroneStation::AddAsRepresentation(){ return bool(); }
bool AFGBuildableDroneStation::UpdateRepresentation(){ return bool(); }
bool AFGBuildableDroneStation::RemoveAsRepresentation(){ return bool(); }
bool AFGBuildableDroneStation::IsActorStatic(){ return bool(); }
FVector AFGBuildableDroneStation::GetRealActorLocation(){ return FVector(); }
FRotator AFGBuildableDroneStation::GetRealActorRotation(){ return FRotator(); }
UTexture2D* AFGBuildableDroneStation::GetActorRepresentationTexture(){ return nullptr; }
FText AFGBuildableDroneStation::GetActorRepresentationText(){ return FText(); }
void AFGBuildableDroneStation::SetActorRepresentationText(const FText& newText){ }
FLinearColor AFGBuildableDroneStation::GetActorRepresentationColor(){ return FLinearColor(); }
void AFGBuildableDroneStation::SetActorRepresentationColor(FLinearColor newColor){ }
ERepresentationType AFGBuildableDroneStation::GetActorRepresentationType(){ return ERepresentationType(); }
bool AFGBuildableDroneStation::GetActorShouldShowInCompass(){ return bool(); }
bool AFGBuildableDroneStation::GetActorShouldShowOnMap(){ return bool(); }
EFogOfWarRevealType AFGBuildableDroneStation::GetActorFogOfWarRevealType(){ return EFogOfWarRevealType(); }
float AFGBuildableDroneStation::GetActorFogOfWarRevealRadius(){ return float(); }
ECompassViewDistance AFGBuildableDroneStation::GetActorCompassViewDistance(){ return ECompassViewDistance(); }
void AFGBuildableDroneStation::SetActorCompassViewDistance(ECompassViewDistance compassViewDistance){ }
void AFGBuildableDroneStation::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFGBuildableDroneStation, mStationHasDronesInQueue);
	DOREPLIFETIME(AFGBuildableDroneStation, mItemTransferringStage);
	DOREPLIFETIME(AFGBuildableDroneStation, mStationDrone);
	DOREPLIFETIME(AFGBuildableDroneStation, mDockedDrone);
	DOREPLIFETIME(AFGBuildableDroneStation, mInfo);
	DOREPLIFETIME(AFGBuildableDroneStation, mMapText);
}
void AFGBuildableDroneStation::BeginPlay(){ }
void AFGBuildableDroneStation::EndPlay(const EEndPlayReason::Type EndPlayReason){ }
void AFGBuildableDroneStation::Factory_Tick(float dt){ }
void AFGBuildableDroneStation::Factory_TickProducing(float dt){ }
void AFGBuildableDroneStation::Factory_CollectInput_Implementation(){ }
void AFGBuildableDroneStation::Dismantle_Implementation(){ }
void AFGBuildableDroneStation::GetChildDismantleActors_Implementation(TArray< AActor* >& out_ChildDismantleActors) const{ }
void AFGBuildableDroneStation::OnReplicationDetailActorRemoved(){ }
void AFGBuildableDroneStation::PostLoadGame_Implementation(int32 saveVersion, int32 gameVersion){ }
void AFGBuildableDroneStation::StartIsLookedAtForSnapping( AFGCharacterPlayer* byCharacter, bool IsValidSnap){ }
void AFGBuildableDroneStation::StopIsLookedAtForSnapping( AFGCharacterPlayer* byCharacter){ }
void AFGBuildableDroneStation::Undock(bool Immediate){ }
int32 AFGBuildableDroneStation::RequestDocking( AFGDroneVehicle* DroneToDock){ return int32(); }
void AFGBuildableDroneStation::SetStationDrone( AFGDroneVehicle* Drone){ }
FVector AFGBuildableDroneStation::GetDroneDockingStartLocation() const{ return FVector(); }
FVector AFGBuildableDroneStation::GetDroneDockingLocation() const{ return FVector(); }
void AFGBuildableDroneStation::EnsureInfoCreated(){ }
void AFGBuildableDroneStation::StartDockingSequence_Implementation( AFGDroneVehicle* Drone){ }
void AFGBuildableDroneStation::EndDockingSequence_Implementation( AFGDroneVehicle* Drone, bool ShouldTransferItems){ }
void AFGBuildableDroneStation::StartTakeoffSequence_Implementation( AFGDroneVehicle* Drone){ }
void AFGBuildableDroneStation::EndTakeoffSequence_Implementation( AFGDroneVehicle* Drone){ }
void AFGBuildableDroneStation::PreSerializedToBlueprint(){ }
void AFGBuildableDroneStation::PostSerializedToBlueprint(){ }
void AFGBuildableDroneStation::PostSerializedFromBlueprint(){ }
void AFGBuildableDroneStation::OnRep_ReplicationDetailActor(){ }
AFGReplicationDetailActor_DroneStation* AFGBuildableDroneStation::GetCastRepDetailsActor() const{ return nullptr; }
bool AFGBuildableDroneStation::FilterBatteryClasses(TSubclassOf< UObject > object, int32 idx) const{ return bool(); }
bool AFGBuildableDroneStation::IsValidFuel(TSubclassOf<  UFGItemDescriptor > resource) const{ return bool(); }
void AFGBuildableDroneStation::OnRep_ItemTransferringStage(){ }
void AFGBuildableDroneStation::OnRep_StationHasDronesInQueue(){ }
void AFGBuildableDroneStation::OnRep_DroneStationInfo(){ }
void AFGBuildableDroneStation::SetItemTransferringStage(EItemTransferringStage NewStage){ }
void AFGBuildableDroneStation::BeginItemTransfer(){ }
void AFGBuildableDroneStation::EndItemTransfer(){ }
EItemTransferTickResult AFGBuildableDroneStation::ItemTransferTick( UFGInventoryComponent* FromInventory,  UFGInventoryComponent* ToInventory, bool MustTransferEverything){ return EItemTransferTickResult(); }
FName AFGBuildableDroneStation::sBatteriesTag = FName();

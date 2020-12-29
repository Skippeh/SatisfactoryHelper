// This file has been automatically generated by the Unreal Header Implementation tool

#include "FGBuildableConveyorBase.h"
#include "FGFactoryConnectionComponent.h"

void UFGConveyorRemoteCallObject::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const{ }
void UFGConveyorRemoteCallObject::Server_OnUse_Implementation( AFGBuildableConveyorBelt* target,  AFGCharacterPlayer* byCharacter, uint32 itemRepID, float itemOffset){ }
bool UFGConveyorRemoteCallObject::Server_OnUse_Validate( AFGBuildableConveyorBelt* target,  AFGCharacterPlayer* byCharacter, uint32 itemRepID, float itemOffset){ return bool(); }
void UFGConveyorRemoteCallObject::Server_ReportInvalidStateAndRequestConveyorRepReset_Implementation( AFGBuildableConveyorBase* target){ }
bool UFGConveyorRemoteCallObject::Server_ReportInvalidStateAndRequestConveyorRepReset_Validate( AFGBuildableConveyorBase* target){ return bool(); }
FConveyorBeltItems::FConveyorBeltItems(){ }
int32 FConveyorBeltItems::GetIndexForItemByRepKey(FG_ConveyorItemRepKeyType itemID) const{ return int32(); }
int32 FConveyorBeltItems::GetIndexForItemByRepKeyNetBitLimit(uint32 itemID) const{ return int32(); }
bool FConveyorBeltItems::NetDeltaSerialize(FNetDeltaSerializeInfo& parms){ return bool(); }
void FConveyorBeltItems::ApplySpacingToItem(int32 targetIndex, int32 nbReadsDone, EConveyorSpawnStyle spacingStyle, int16 spacingParamA, int16 spacingParamB, uint32 individualSpacingParam){ }
void FConveyorBeltItems::SignalReadErrorAndRequestReset(FBitReader& reader){ }
void FConveyorBeltItems::CleanupAndSignalVersionChange(){ }
void FConveyorBeltItems::MarkArrayDirty(){ }
void FConveyorBeltItems::UpdateLastestIDFromState(){ }
float FConveyorBeltItems::ConsumeAndUpdateConveyorOffsetDebt(float dt){ return float(); }
void FConveyorBeltItems::MarkItemDirty(FConveyorBeltItem& item){ }
AFGBuildableConveyorBase::AFGBuildableConveyorBase() : Super() {
	this->mConnection0 = CreateDefaultSubobject<UFGFactoryConnectionComponent>(TEXT("ConveyorAny0")); this->mConnection0->SetupAttachment(this->RootComponent);
	this->mConnection1 = CreateDefaultSubobject<UFGFactoryConnectionComponent>(TEXT("ConveyorAny1")); this->mConnection1->SetupAttachment(this->RootComponent);
	this->MaxRenderDistance = -1;
	this->mFactoryTickFunction.TickGroup = TG_PrePhysics; this->mFactoryTickFunction.EndTickGroup = TG_PrePhysics; this->mFactoryTickFunction.bTickEvenWhenPaused = false; this->mFactoryTickFunction.bCanEverTick = true; this->mFactoryTickFunction.bStartWithTickEnabled = true; this->mFactoryTickFunction.bAllowTickOnDedicatedServer = true; this->mFactoryTickFunction.TickInterval = 0;
	this->mPrimaryColor.R = -1; this->mPrimaryColor.G = -1; this->mPrimaryColor.B = -1; this->mPrimaryColor.A = 1;
	this->mSecondaryColor.R = -1; this->mSecondaryColor.G = -1; this->mSecondaryColor.B = -1; this->mSecondaryColor.A = 1;
	this->mDismantleEffectClassName = FSoftClassPath("/Game/FactoryGame/Buildable/Factory/-Shared/BP_MaterialEffect_Dismantle.BP_MaterialEffect_Dismantle_C");
	this->mBuildEffectClassName = FSoftClassPath("/Game/FactoryGame/Buildable/Factory/-Shared/BP_MaterialEffect_Build.BP_MaterialEffect_Build_C");
	this->mHighlightParticleClassName = FSoftClassPath("/Game/FactoryGame/Buildable/-Shared/Particle/NewBuildingPing.NewBuildingPing_C");
	this->PrimaryActorTick.TickGroup = TG_PrePhysics; this->PrimaryActorTick.EndTickGroup = TG_PrePhysics; this->PrimaryActorTick.bTickEvenWhenPaused = false; this->PrimaryActorTick.bCanEverTick = true; this->PrimaryActorTick.bStartWithTickEnabled = false; this->PrimaryActorTick.bAllowTickOnDedicatedServer = true; this->PrimaryActorTick.TickInterval = 0;
	this->bReplicates = true;
	this->NetCullDistanceSquared = 5624999936;
}
void AFGBuildableConveyorBase::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const{ }
void AFGBuildableConveyorBase::BeginPlay(){ }
void AFGBuildableConveyorBase::EndPlay(const EEndPlayReason::Type endPlayReason){ }
void AFGBuildableConveyorBase::Serialize(FArchive& ar){ Super::Serialize(ar); }
void AFGBuildableConveyorBase::Tick(float dt){ }
void AFGBuildableConveyorBase::PostLoadGame_Implementation(int32 saveVersion, int32 gameVersion){ }
void AFGBuildableConveyorBase::Factory_Tick(float deltaTime){ }
uint8 AFGBuildableConveyorBase::MaxNumGrab(float dt) const{ return uint8(); }
uint8 AFGBuildableConveyorBase::EstimatedMaxNumGrab_Threadsafe(float estimatedDeltaTime) const{ return uint8(); }
void AFGBuildableConveyorBase::GainedSignificance_Implementation(){ }
void AFGBuildableConveyorBase::LostSignificance_Implementation(){ }
void AFGBuildableConveyorBase::GainedSignificance_Native(){ }
void AFGBuildableConveyorBase::LostSignificance_Native(){ }
void AFGBuildableConveyorBase::SetupForSignificance(){ }
void AFGBuildableConveyorBase::PreReplication(IRepChangedPropertyTracker& ChangedPropertyTracker){ }
void AFGBuildableConveyorBase::SetConveyorBucketID(int32 ID){ }
float AFGBuildableConveyorBase::GetAvailableSpace() const{ return float(); }
float AFGBuildableConveyorBase::GetCachedAvailableSpace_Threadsafe() const{ return float(); }
void AFGBuildableConveyorBase::ReportInvalidStateAndRequestConveyorRepReset(){ }
bool AFGBuildableConveyorBase::Factory_PeekOutput_Implementation(const  UFGFactoryConnectionComponent* connection, TArray< FInventoryItem >& out_items, TSubclassOf< UFGItemDescriptor > type) const{ return bool(); }
bool AFGBuildableConveyorBase::Factory_GrabOutput_Implementation( UFGFactoryConnectionComponent* connection, FInventoryItem& out_item, float& out_OffsetBeyond, TSubclassOf< UFGItemDescriptor > type){ return bool(); }
void AFGBuildableConveyorBase::GetDismantleInventoryReturns(TArray< FInventoryStack >& out_returns) const{ }
int32 AFGBuildableConveyorBase::FindItemClosestToLocation(const FVector& location) const{ return int32(); }
bool AFGBuildableConveyorBase::Factory_HasItemAt(int32 index) const{ return bool(); }
const FConveyorBeltItem& AFGBuildableConveyorBase::Factory_PeekItemAt(int32 index) const{ return *(new FConveyorBeltItem); }
void AFGBuildableConveyorBase::Factory_RemoveItemAt(int32 index){ }
void AFGBuildableConveyorBase::Factory_DequeueItem(){ }
void AFGBuildableConveyorBase::Factory_EnqueueItem(const FInventoryItem& item, float initialOffset){ }
bool AFGBuildableConveyorBase::HasRoomOnBelt(float& out_availableSpace) const{ return bool(); }
bool AFGBuildableConveyorBase::HasRoomOnBelt_ThreadSafe(float& out_availableSpace) const{ return bool(); }

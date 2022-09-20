// This file has been automatically generated by the Unreal Header Implementation tool

#include "WheeledVehicles/FGWheeledVehicleInfo.h"

#ifdef DEBUG_SELF_DRIVING
void AFGWheeledVehicleInfo::DrawDebug(int debugLevel){ }
#endif 
AFGWheeledVehicleInfo::AFGWheeledVehicleInfo() : Super() {
	this->mVehicle = nullptr;
	this->mReplicatedVehicle = nullptr;
	this->mStatus = EVehicleStatus::VS_Operational;
	this->mIsFollowingPath = false;
	this->mIsPossessed = false;
	this->mTarget = nullptr;
	this->mSimulationMovement = nullptr;
	this->mCurrentStation = nullptr;
	this->mIsSimulated = false;
	this->mAuthoritativeLocation = FVector::ZeroVector;
	this->mAuthoritativeRotation.X = 0.0;
	this->mAuthoritativeRotation.Y = 0.0;
	this->mAuthoritativeRotation.Z = 0.0;
	this->mAuthoritativeRotation.W = 0.0;
	this->mAuthoritativeLinearVel = FVector::ZeroVector;
	this->mIsGhosting = false;
	this->mCurrentFuelClass = nullptr;
	this->mActorRepresentationTexture = nullptr;
	this->mMapText = INVTEXT("");
	this->mDefaultRepresentationColor = FLinearColor(0.0, 0.0, 0.0, 0.0);
	this->mPlayerNametagColor = FLinearColor(0.0, 0.0, 0.0, 0.0);
	this->mBoundingBoxExtent = FVector::ZeroVector;
	this->mBoundingBoxOffset = FVector::ZeroVector;
	this->mWheelRadius = 0.0;
	this->mStaticMeshComponent = nullptr;
	this->bAlwaysRelevant = true;
	this->bReplicates = true;
}
void AFGWheeledVehicleInfo::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFGWheeledVehicleInfo, mReplicatedVehicle);
	DOREPLIFETIME(AFGWheeledVehicleInfo, mStatus);
	DOREPLIFETIME(AFGWheeledVehicleInfo, mIsFollowingPath);
	DOREPLIFETIME(AFGWheeledVehicleInfo, mIsPossessed);
	DOREPLIFETIME(AFGWheeledVehicleInfo, mTarget);
	DOREPLIFETIME(AFGWheeledVehicleInfo, mSimulationMovement);
	DOREPLIFETIME(AFGWheeledVehicleInfo, mCurrentStation);
	DOREPLIFETIME(AFGWheeledVehicleInfo, mIsSimulated);
	DOREPLIFETIME(AFGWheeledVehicleInfo, mAuthoritativeLocation);
	DOREPLIFETIME(AFGWheeledVehicleInfo, mAuthoritativeRotation);
	DOREPLIFETIME(AFGWheeledVehicleInfo, mAuthoritativeLinearVel);
	DOREPLIFETIME(AFGWheeledVehicleInfo, mIsGhosting);
	DOREPLIFETIME(AFGWheeledVehicleInfo, mCurrentFuelClass);
	DOREPLIFETIME(AFGWheeledVehicleInfo, mActorRepresentationTexture);
	DOREPLIFETIME(AFGWheeledVehicleInfo, mMapText);
	DOREPLIFETIME(AFGWheeledVehicleInfo, mDefaultRepresentationColor);
	DOREPLIFETIME(AFGWheeledVehicleInfo, mPlayerNametagColor);
	DOREPLIFETIME(AFGWheeledVehicleInfo, mBoundingBoxExtent);
	DOREPLIFETIME(AFGWheeledVehicleInfo, mBoundingBoxOffset);
	DOREPLIFETIME(AFGWheeledVehicleInfo, mWheelRadius);
	DOREPLIFETIME(AFGWheeledVehicleInfo, mStaticMeshComponent);
}
void AFGWheeledVehicleInfo::PostLoadGame_Implementation(int32 saveVersion, int32 gameVersion){ }
bool AFGWheeledVehicleInfo::AddAsRepresentation(){ return bool(); }
bool AFGWheeledVehicleInfo::UpdateRepresentation(){ return bool(); }
bool AFGWheeledVehicleInfo::RemoveAsRepresentation(){ return bool(); }
bool AFGWheeledVehicleInfo::IsActorStatic(){ return bool(); }
FVector AFGWheeledVehicleInfo::GetRealActorLocation(){ return FVector(); }
FRotator AFGWheeledVehicleInfo::GetRealActorRotation(){ return FRotator(); }
UTexture2D* AFGWheeledVehicleInfo::GetActorRepresentationTexture(){ return nullptr; }
FText AFGWheeledVehicleInfo::GetActorRepresentationText(){ return FText(); }
void AFGWheeledVehicleInfo::SetActorRepresentationText(const FText& newText){ }
FLinearColor AFGWheeledVehicleInfo::GetActorRepresentationColor(){ return FLinearColor(); }
void AFGWheeledVehicleInfo::SetActorRepresentationColor(FLinearColor newColor){ }
ERepresentationType AFGWheeledVehicleInfo::GetActorRepresentationType(){ return ERepresentationType(); }
bool AFGWheeledVehicleInfo::GetActorShouldShowInCompass(){ return bool(); }
bool AFGWheeledVehicleInfo::GetActorShouldShowOnMap(){ return bool(); }
EFogOfWarRevealType AFGWheeledVehicleInfo::GetActorFogOfWarRevealType(){ return EFogOfWarRevealType(); }
float AFGWheeledVehicleInfo::GetActorFogOfWarRevealRadius(){ return float(); }
ECompassViewDistance AFGWheeledVehicleInfo::GetActorCompassViewDistance(){ return ECompassViewDistance(); }
void AFGWheeledVehicleInfo::SetActorCompassViewDistance(ECompassViewDistance compassViewDistance){ }
void AFGWheeledVehicleInfo::BeginPlay(){ }
void AFGWheeledVehicleInfo::EndPlay(const EEndPlayReason::Type EndPlayReason){ }
void AFGWheeledVehicleInfo::Tick(float dt){ }
void AFGWheeledVehicleInfo::Init(AFGWheeledVehicle* vehicle){ }
void AFGWheeledVehicleInfo::InitCollisionData( UFGVehicleCollisionBoxComponent* collisionBox){ }
AFGWheeledVehicle* AFGWheeledVehicleInfo::GetVehicle() const{ return nullptr; }
void AFGWheeledVehicleInfo::SetVehicleStatus(EVehicleStatus status){ }
void AFGWheeledVehicleInfo::SetIsFollowingPath(bool isFollowingPath){ }
void AFGWheeledVehicleInfo::SetIsPossessed(bool isPossessed){ }
void AFGWheeledVehicleInfo::SetTarget( AFGTargetPoint* target){ }
void AFGWheeledVehicleInfo::SetIsSimulated(bool isSimulated){ }
FVector AFGWheeledVehicleInfo::GetVehicleLocation() const{ return FVector(); }
FRotator AFGWheeledVehicleInfo::GetVehicleRotation() const{ return FRotator(); }
void AFGWheeledVehicleInfo::UpdateTarget(){ }
bool AFGWheeledVehicleInfo::ShouldStayAtDock(){ return bool(); }
void AFGWheeledVehicleInfo::OnTargetDestroyed( AFGTargetPoint* target){ }
AFGDrivingTargetList* AFGWheeledVehicleInfo::GetTargetList() const{ return nullptr; }
void AFGWheeledVehicleInfo::TryActivatePathSimulation(){ }
void AFGWheeledVehicleInfo::SetSimulationVisible(bool isVisible){ }
void AFGWheeledVehicleInfo::UpdateCustomizationData( AFGWheeledVehicle* vehicle){ }
void AFGWheeledVehicleInfo::ApplyMeshPrimitiveData(const FFactoryCustomizationData& customizationData){ }
void AFGWheeledVehicleInfo::ShowGhostingEffect(bool enabled){ }
void AFGWheeledVehicleInfo::OnRep_Status(){ }
void AFGWheeledVehicleInfo::OnRep_IsFollowingPath(){ }
void AFGWheeledVehicleInfo::OnRep_IsGhosting(){ }
void AFGWheeledVehicleInfo::OnSimulationTargetReached(AFGTargetPoint* newTarget){ }

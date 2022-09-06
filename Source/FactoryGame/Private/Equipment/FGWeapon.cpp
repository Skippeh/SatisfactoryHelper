// This file has been automatically generated by the Unreal Header Implementation tool

#include "Equipment/FGWeapon.h"
#include "Equipment/FGEquipment.h"

TAutoConsoleVariable<int32> CVarWeaponDebug(TEXT("CVarWeaponDebug"), 0, TEXT(""));
void AFGWeapon::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFGWeapon, mWeaponState);
	DOREPLIFETIME(AFGWeapon, mCurrentAmmoCount);
	DOREPLIFETIME(AFGWeapon, mDesiredAmmoClass);
	DOREPLIFETIME(AFGWeapon, mCurrentAmmunitionClass);
	DOREPLIFETIME(AFGWeapon, mCurrentMagazineObject);
}
bool AFGWeapon::ReplicateSubobjects( UActorChannel* channel,  FOutBunch* bunch, FReplicationFlags* repFlags){ return bool(); }
AFGWeapon::AFGWeapon() : Super() {
	this->mAssociatedHud = nullptr;
	this->mWeaponState = EWeaponState::EWS_Unequipped;
	this->mAutomaticallyReload = false;
	this->mAutoReloadDelay = 0.5;
	this->mCurrentAmmoCount = 0;
	this->mDesiredAmmoClass = nullptr;
	this->mCurrentAmmunitionClass = nullptr;
	this->mAttachMagazineToPlayer = false;
	this->mMuzzleSocketName = TEXT("None");
	this->mCurrentMagazineBoneName = TEXT("None");
	this->mWeaponMesh = nullptr;
	this->mCurrentMagazineMesh = nullptr;
	this->mEjectMagazineBoneName = TEXT("None");
	this->mEjectMagazineMesh = nullptr;
	this->mDispersionOnNoMagazine = 5.0;
	this->mWeaponDamageMultiplier = 1.0;
	this->mFiringBlocksDispersionReduction = false;
	this->mCurrentDispersion = 0.0;
	this->mReloadTime = 1.5;
	this->mReloadSound = nullptr;
	this->mCurrentMagazineObject = nullptr;
	this->mAmmoSwitchUsedRadialMenu = false;
	this->mBlockSprintWhenFiring = true;
	this->mEquipmentSlot = EEquipmentSlot::ES_ARMS;
	this->mOnlyVisibleToOwner = false;
}
void AFGWeapon::Tick(float DeltaSeconds){ }
bool AFGWeapon::ShouldSaveState() const{ return bool(); }
bool AFGWeapon::InitializeMagazineObject(){ return bool(); }
void AFGWeapon::UnEquip(){ }
void AFGWeapon::Equip( AFGCharacterPlayer* character){ }
void AFGWeapon::AssignHud(AFGHUD* associatedHud){ }
void AFGWeapon::OnPrimaryFirePressed(){ }
void AFGWeapon::Server_StartPrimaryFire_Implementation(){ }
void AFGWeapon::Multicast_BeginPrimaryFire_Implementation(){ }
void AFGWeapon::OnPrimaryFireReleased(){ }
void AFGWeapon::Server_EndPrimaryFire_Implementation(){ }
void AFGWeapon::Multicast_EndPrimaryFire_Implementation(){ }
void AFGWeapon::EndPrimaryFire(){ }
void AFGWeapon::OnReloadPressed(){ }
void AFGWeapon::Multicast_Reload_Implementation(){ }
bool AFGWeapon::CanReload() const{ return bool(); }
float AFGWeapon::GetReloadTimeLeft() const{ return float(); }
FVector AFGWeapon::GetWeaponMeshSocketLocation_Implementation(FName socketName) const{ return FVector(); }
void AFGWeapon::OnCycleAmmunitionTypePressed(){ }
void AFGWeapon::OnCycleAmmunitionTypeReleased(){ }
void AFGWeapon::Server_CycleDesiredAmmunitionType_Implementation(){ }
void AFGWeapon::CycleDesiredAmmunitionType(){ }
void AFGWeapon::Server_SetDesiredAmmoClass_Implementation(TSubclassOf< UFGAmmoType > newDesiredAmmoClass){ }
void AFGWeapon::SetDesiredAmmoClass(TSubclassOf< UFGAmmoType > newDesiredAmmoClass){ }
bool AFGWeapon::HasAmmunition() const{ return bool(); }
int32 AFGWeapon::GetSpareAmmunition(TSubclassOf< UFGAmmoType > AmmunitionType) const{ return int32(); }
void AFGWeapon::ApplyDispersion(){ }
void AFGWeapon::FireAmmunition(){ }
float AFGWeapon::GetNormalizedDispersionValue() const{ return float(); }
void AFGWeapon::Multicast_PlayFireEffect_Implementation(UFGAmmoType* AmmoTypeObject){ }
void AFGWeapon::PlayFireEffect_Implementation(UFGAmmoType* AmmoTypeObject){ }
void AFGWeapon::AddEquipmentActionBindings(){ }
void AFGWeapon::SetWeaponState(EWeaponState newState){ }
void AFGWeapon::UpdateDispersion(float DeltaSeconds){ }
void AFGWeapon::SetMagazineMeshMaterials(USkeletalMeshComponent* skelMeshComp, UFGAmmoType* ammoTypeObject){ }
void AFGWeapon::RefireCheckTimer(){ }
void AFGWeapon::ConsumeAmmunition(){ }
bool AFGWeapon::CanFire() const{ return bool(); }
void AFGWeapon::ActualReload(){ }
void AFGWeapon::PlayReloadEffects_Implementation(bool hadAmmoLeft){ }
void AFGWeapon::Server_Reload_Implementation(){ }
void AFGWeapon::TryAutoReload(){ }
bool AFGWeapon::GetFireRate(float& fireRate){ return bool(); }
void AFGWeapon::TriggerRefireTimer(){ }
UFGInventoryComponent* AFGWeapon::GetOwnersInventoryComponent() const{ return nullptr; }
void AFGWeapon::OnAmmoFired(AActor* SpawnedActor){ }
void AFGWeapon::OnRep_CurrentMagazineObject( UFGAmmoType* oldMagazineObject){ }
void AFGWeapon::OnRep_WeaponState(EWeaponState oldState){ }
void AFGWeapon::OnRep_CurrentAmmoCount(){ }
void AFGWeapon::OnRep_Instigator(){ }

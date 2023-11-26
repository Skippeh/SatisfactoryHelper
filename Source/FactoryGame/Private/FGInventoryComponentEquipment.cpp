// This file has been automatically generated by the Unreal Header Implementation tool

#include "FGInventoryComponentEquipment.h"
#include "Equipment/FGEquipment.h"
#include "Net/UnrealNetwork.h"

UFGInventoryComponentEquipment::UFGInventoryComponentEquipment() : Super() {
	this->mOverrideEquipmentInSlot = nullptr;
	this->mEquipmentInSlot = nullptr;
	this->mEquipmentInventorySlot = EEquipmentSlot::ES_NONE;
	this->mActiveEquipmentIndex = -1;
	this->SetIsReplicatedByDefault(true);
}
AFGEquipment* UFGInventoryComponentEquipment::GetEquipmentInInventory() const{ return nullptr; }
EEquipmentSlot UFGInventoryComponentEquipment::GetEquipmentSlotEnum() const{ return EEquipmentSlot(); }
void UFGInventoryComponentEquipment::SetEquipmentSlotEnum(EEquipmentSlot inSlot){ }
void UFGInventoryComponentEquipment::SetOverrideEquipment(AFGEquipment* equipment){ }
void UFGInventoryComponentEquipment::CycleEquipment(int32 dir){ }
bool UFGInventoryComponentEquipment::ContainsItemTypeAndHasEnoughSpaceForItem(FInventoryItem item){ return bool(); }
FDelegateHandle UFGInventoryComponentEquipment::BindOnActiveEquipmentChanged(const FOnActiveEquipmentChanged::FDelegate &Delegate){ return FDelegateHandle(); }
void UFGInventoryComponentEquipment::SetActiveEquipment(AFGEquipment* equipment){ }
void UFGInventoryComponentEquipment::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFGInventoryComponentEquipment, mEquipmentInSlot);
	DOREPLIFETIME(UFGInventoryComponentEquipment, mEquipmentInventorySlot);
	DOREPLIFETIME(UFGInventoryComponentEquipment, mActiveEquipmentIndex);
}
void UFGInventoryComponentEquipment::OnItemsAdded(int32 idx, int32 num){ }
void UFGInventoryComponentEquipment::OnItemsRemoved(int32 index, int32 num, FInventoryItem item){ }
void UFGInventoryComponentEquipment::ActivateEquipment(){ }
void UFGInventoryComponentEquipment::RemoveEquipment(FInventoryItem item){ }
bool UFGInventoryComponentEquipment::FilterEquipmentClasses(TSubclassOf< UObject > object, int32 idx) const{ return bool(); }
AFGCharacterPlayer* UFGInventoryComponentEquipment::GetOwningCharacter(){ return nullptr; }
void UFGInventoryComponentEquipment::OnRep_ActiveEquipmentIndex(){ }
void UFGInventoryComponentEquipment::OnRep_ActiveEquipment(){ }

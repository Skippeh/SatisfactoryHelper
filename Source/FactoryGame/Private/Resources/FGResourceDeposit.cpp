// This file has been automatically generated by the Unreal Header Implementation tool

#include "Resources/FGResourceDeposit.h"
#include "Components/StaticMeshComponent.h"
#include "Net/UnrealNetwork.h"

AFGResourceDeposit::AFGResourceDeposit() : Super() {
	this->mResourceDepositPackage.DropChance = 0.0;
	this->mResourceDepositPackage.ResourceClass = nullptr;
	this->mResourceDepositTableIndex = -1;
	this->mIsEmptied = false;
	this->mHasInitializedVisuals = false;
	this->mDepositMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DepositMesh"));
	this->mOverrideResourceClass = nullptr;
	this->mCanBeRadioactive = true;
	this->mCanPlaceResourceExtractor = false;
	this->mExtractMultiplier = 2;
	this->RootComponent = mDepositMeshComponent;
}
void AFGResourceDeposit::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFGResourceDeposit, mResourceDepositTableIndex);
	DOREPLIFETIME(AFGResourceDeposit, mIsEmptied);
	DOREPLIFETIME(AFGResourceDeposit, mMineAmount);
}
void AFGResourceDeposit::PostLoad(){ Super::PostLoad(); }
void AFGResourceDeposit::BeginPlay(){ }
void AFGResourceDeposit::RollResourceType(){ }
void AFGResourceDeposit::TrySetDesiredResourceType(){ }
void AFGResourceDeposit::SetupResourceInfo(){ }
void AFGResourceDeposit::ExtractResourceAndGiveToPlayer(AFGCharacterPlayer* toPlayer, int32 amount){ }
void AFGResourceDeposit::OnRep_ResourceDepositTableIndex(){ }
void AFGResourceDeposit::OnRep_ResourceDepositEmptied(){ }
void AFGResourceDeposit::InitRadioactivity(){ }
void AFGResourceDeposit::UpdateRadioactivity(){ }

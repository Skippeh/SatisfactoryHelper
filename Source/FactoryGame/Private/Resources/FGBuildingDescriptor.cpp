// This file has been automatically generated by the Unreal Header Implementation tool

#include "Resources/FGBuildingDescriptor.h"

#if WITH_EDITOR
void UFGBuildingDescriptor::SetBuildableClass(TSubclassOf< UFGBuildingDescriptor > inClass, TSubclassOf<  AFGBuildable > buildableClass){ }
#endif 
UFGBuildingDescriptor::UFGBuildingDescriptor() : Super() {
	this->mBuildableClass = nullptr;
	this->mUseDisplayNameAndDescription = false;
	this->mDisplayName = INVTEXT("");
	this->mDescription = INVTEXT("");
}
void UFGBuildingDescriptor::PostLoad(){ Super::PostLoad(); }
TSubclassOf< class AFGBuildable > UFGBuildingDescriptor::GetBuildableClass(TSubclassOf< UFGBuildingDescriptor > inClass){ return TSubclassOf<class AFGBuildable>(); }
float UFGBuildingDescriptor::GetPowerConsumption(TSubclassOf< UFGBuildingDescriptor > inClass){ return float(); }
bool UFGBuildingDescriptor::HasVariablePowerConsumption(TSubclassOf< UFGBuildingDescriptor > inClass){ return bool(); }
float UFGBuildingDescriptor::GetMinimumPowerConsumption(TSubclassOf< UFGBuildingDescriptor > inClass){ return float(); }
float UFGBuildingDescriptor::GetMaximumPowerConsumption(TSubclassOf< UFGBuildingDescriptor > inClass){ return float(); }
float UFGBuildingDescriptor::GetPowerProduction(TSubclassOf< UFGBuildingDescriptor > inClass){ return float(); }
FText UFGBuildingDescriptor::GetItemNameInternal() const{ return FText(); }
FText UFGBuildingDescriptor::GetItemDescriptionInternal() const{ return FText(); }
TSubclassOf< class AFGHologram > UFGBuildingDescriptor::GetHologramClassInternal() const{ return TSubclassOf<class AFGHologram>(); }
TSubclassOf< AActor > UFGBuildingDescriptor::GetBuildClassInternal() const{ return TSubclassOf<AActor>(); }
FText UFGBuildingDescriptor::mOverrideDisplayNameAndDescription = FText();

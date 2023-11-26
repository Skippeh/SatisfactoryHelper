// This file has been automatically generated by the Unreal Header Implementation tool

#include "FGBlueprintShortcut.h"
#include "Net/UnrealNetwork.h"

void UFGBlueprintShortcut::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFGBlueprintShortcut, mBlueprintName);
}
void UFGBlueprintShortcut::SetBlueprintName(const FString& inBlueprintName, bool silent){ }
void UFGBlueprintShortcut::Execute_Implementation( AFGPlayerController* owner){ }
bool UFGBlueprintShortcut::IsValidShortcut_Implementation( AFGPlayerController* owner) const{ return bool(); }
UTexture2D* UFGBlueprintShortcut::GetDisplayImage_Implementation() const{ return nullptr; }
bool UFGBlueprintShortcut::IsActive_Implementation( AFGPlayerController* owner) const{ return bool(); }
bool UFGBlueprintShortcut::IsSame_Implementation(UFGHotbarShortcut* shortcut) const{ return bool(); }
FString UFGBlueprintShortcut::DescribeShortcut_Implementation() const{ return FString(); }
void UFGBlueprintShortcut::OnRep_BlueprintName(){ }
void UFGBlueprintShortcut::OnClientSubsystemsValid(){ }
void UFGBlueprintShortcut::DestroyShortcut_Implementation(){ }
void UFGBlueprintShortcut::OnBlueprintDescriptorUpdated(UFGBlueprintDescriptor* blueprintDescriptor){ }
void UFGBlueprintShortcut::UpdateBlueprintDescriptor(){ }

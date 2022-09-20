// This file has been automatically generated by the Unreal Header Implementation tool

#include "WheeledVehicles/FGWheeledVehicleMovementComponent6W.h"
#include "VehicleWheel.h"

float FVehicleEngineData6W::FindPeakTorque() const{ return float(); }
#if WITH_EDITOR
void UFGWheeledVehicleMovementComponent6W::PostEditChangeProperty( FPropertyChangedEvent& PropertyChangedEvent){ Super::PostEditChangeProperty(PropertyChangedEvent); }
#endif 
void UFGWheeledVehicleMovementComponent6W::Serialize(FArchive & Ar){ Super::Serialize(Ar); }
void UFGWheeledVehicleMovementComponent6W::ComputeConstants(){ }
void UFGWheeledVehicleMovementComponent6W::GenerateTireForces( UVehicleWheel* Wheel, const FTireShaderInput& Input, FTireShaderOutput& Output){ }
void UFGWheeledVehicleMovementComponent6W::SetupWheelMassProperties_AssumesLocked(const uint32 NumWheels, physx::PxVehicleWheelsSimData* PWheelsSimData, physx::PxRigidBody* PVehicleActor){ }
void UFGWheeledVehicleMovementComponent6W::SetupWheels(physx::PxVehicleWheelsSimData* PWheelsSimData){ }
void UFGWheeledVehicleMovementComponent6W::PreTick(float DeltaTime){ }
void UFGWheeledVehicleMovementComponent6W::SetupVehicleShapes(){ }
void UFGWheeledVehicleMovementComponent6W::SetupVehicleDrive(physx::PxVehicleWheelsSimData* PWheelsSimData){ }
void UFGWheeledVehicleMovementComponent6W::UpdateSimulation(float DeltaTime){ }
void UFGWheeledVehicleMovementComponent6W::UpdateEngineSetup(const FVehicleEngineData6W& NewEngineSetup){ }
void UFGWheeledVehicleMovementComponent6W::UpdateDifferentialSetup(const FVehicleDifferential6WData& NewDifferentialSetup){ }
void UFGWheeledVehicleMovementComponent6W::UpdateTransmissionSetup(const FVehicleTransmissionData6W& NewGearSetup){ }
float UFGWheeledVehicleMovementComponent6W::GetLargestTireLoadValue(){ return float(); }
float UFGWheeledVehicleMovementComponent6W::GetLargestLateralSlip(){ return float(); }
float UFGWheeledVehicleMovementComponent6W::GetLargestLongitudinalSlip(){ return float(); }
bool UFGWheeledVehicleMovementComponent6W::GetHandbreakInput() const{ return bool(); }
void UFGWheeledVehicleMovementComponent6W::GetVehicleDifferential6WSetup(const FVehicleDifferential6WData& Setup, PxVehicleDifferentialNWData& PxSetup){ }
void UFGWheeledVehicleMovementComponent6W::SetupDriveHelper(UFGWheeledVehicleMovementComponent6W* VehicleData, const PxVehicleWheelsSimData* PWheelsSimData, PxVehicleDriveSimDataNW& DriveData){ }
void UFGWheeledVehicleMovementComponent6W::GetVehicleEngineSetup(const FVehicleEngineData6W& Setup, PxVehicleEngineData& PxSetup){ }
void UFGWheeledVehicleMovementComponent6W::GetVehicleAutoBoxSetup(const FVehicleTransmissionData6W& Setup, PxVehicleAutoBoxData& PxSetup){ }
void UFGWheeledVehicleMovementComponent6W::GetVehicleGearSetup(const FVehicleTransmissionData6W& Setup, PxVehicleGearsData& PxSetup){ }
void UFGWheeledVehicleMovementComponent6W::ComputeAckermannSteerAngles(const float steer, const float steerGain, const float ackermannAccuracy, const float width, const float axleSeparation, float* leftAckermannSteerAngle, float* rightAckermannSteerAngle){ }
void UFGWheeledVehicleMovementComponent6W::ComputeAckermannCorrectedSteerAngles(PxVehicleDriveSimDataNW& driveSimData, PxVehicleWheelsSimData& wheelsSimData, const float steer){ }
UFGWheeledVehicleMovementComponent6W::UFGWheeledVehicleMovementComponent6W(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
	this->EngineSetup.TorqueCurve.EditorCurveData.DefaultValue = 3.40282e+38;
	this->EngineSetup.TorqueCurve.EditorCurveData.PreInfinityExtrap = ERichCurveExtrapolation::RCCE_Constant;
	this->EngineSetup.TorqueCurve.EditorCurveData.PostInfinityExtrap = ERichCurveExtrapolation::RCCE_Constant;
	this->EngineSetup.TorqueCurve.ExternalCurve = nullptr;
	this->EngineSetup.MaxRPM = 5729.58;
	this->EngineSetup.MOI = 1.0;
	this->EngineSetup.DampingRateFullThrottle = 0.15;
	this->EngineSetup.DampingRateZeroThrottleClutchEngaged = 2.0;
	this->EngineSetup.DampingRateZeroThrottleClutchDisengaged = 0.35;
	this->DifferentialSetup.DifferentialConfig.Front = true;
	this->DifferentialSetup.DifferentialConfig.Mid = true;
	this->DifferentialSetup.DifferentialConfig.Rear = true;
	this->mUseDSOLGearbox = true;
	this->mDSOLMaxSlopeAngleLimit = 33.0;
	this->mSlopeShiftRatio = 0.3;
	this->TransmissionSetup.bUseGearAutoBox = true;
	this->TransmissionSetup.GearSwitchTime = 0.5;
	this->TransmissionSetup.GearAutoBoxLatency = 2.0;
	this->TransmissionSetup.FinalRatio = 4.0;
	this->TransmissionSetup.ReverseGearRatio = -4.0;
	this->TransmissionSetup.NeutralGearUpRatio = 0.15;
	this->TransmissionSetup.ClutchStrength = 10.0;
	this->mDownShiftLatency = 2.0;
	this->SteeringCurve.EditorCurveData.DefaultValue = 3.40282e+38;
	this->SteeringCurve.EditorCurveData.PreInfinityExtrap = ERichCurveExtrapolation::RCCE_Constant;
	this->SteeringCurve.EditorCurveData.PostInfinityExtrap = ERichCurveExtrapolation::RCCE_Constant;
	this->SteeringCurve.ExternalCurve = nullptr;
	this->AckermannAccuracy = 1.0;
	this->WheelSetups.Emplace();
	this->WheelSetups[0].WheelClass = UVehicleWheel::StaticClass();
	this->WheelSetups[0].BoneName = TEXT("None");
	this->WheelSetups[0].AdditionalOffset = FVector::ZeroVector;
	this->WheelSetups[0].bDisableSteering = false;
	this->WheelSetups.Emplace();
	this->WheelSetups[1].WheelClass = UVehicleWheel::StaticClass();
	this->WheelSetups[1].BoneName = TEXT("None");
	this->WheelSetups[1].AdditionalOffset = FVector::ZeroVector;
	this->WheelSetups[1].bDisableSteering = false;
	this->WheelSetups.Emplace();
	this->WheelSetups[2].WheelClass = UVehicleWheel::StaticClass();
	this->WheelSetups[2].BoneName = TEXT("None");
	this->WheelSetups[2].AdditionalOffset = FVector::ZeroVector;
	this->WheelSetups[2].bDisableSteering = false;
	this->WheelSetups.Emplace();
	this->WheelSetups[3].WheelClass = UVehicleWheel::StaticClass();
	this->WheelSetups[3].BoneName = TEXT("None");
	this->WheelSetups[3].AdditionalOffset = FVector::ZeroVector;
	this->WheelSetups[3].bDisableSteering = false;
	this->WheelSetups.Emplace();
	this->WheelSetups[4].WheelClass = UVehicleWheel::StaticClass();
	this->WheelSetups[4].BoneName = TEXT("None");
	this->WheelSetups[4].AdditionalOffset = FVector::ZeroVector;
	this->WheelSetups[4].bDisableSteering = false;
	this->WheelSetups.Emplace();
	this->WheelSetups[5].WheelClass = UVehicleWheel::StaticClass();
	this->WheelSetups[5].BoneName = TEXT("None");
	this->WheelSetups[5].AdditionalOffset = FVector::ZeroVector;
	this->WheelSetups[5].bDisableSteering = false;
}

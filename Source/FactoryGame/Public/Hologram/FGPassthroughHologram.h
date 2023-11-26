// Copyright Coffee Stain Studios. All Rights Reserved.

#pragma once

#include "FactoryGame.h"
#include "CoreMinimal.h"
#include "FGFactoryHologram.h"
#include "FGPassthroughHologram.generated.h"


/**
 * 
 */
UCLASS()
class FACTORYGAME_API AFGPassthroughHologram : public AFGFactoryHologram
{
	GENERATED_BODY()
public:
	AFGPassthroughHologram();

	// Begin Actory Interface
	virtual void BeginPlay() override;
	// End AActor Interface
	
	// Begin AFGHologram interface
	virtual void SetHologramLocationAndRotation( const FHitResult& hitResult ) override;
	virtual bool TrySnapToActor( const FHitResult& hitResult ) override;
	virtual void ConfigureActor( class AFGBuildable* inBuildable ) const override;
	virtual void GetIgnoredClearanceActors(TArray<AActor*>& ignoredActors) const override;
	virtual int32 GetBaseCostMultiplier() const override;
	// End AFGHologram interface
	
protected:
	virtual void RebuildMeshesAndUpdateClearance();
	void TryExtendInWorldDirection( const FVector& worldLocation, const FQuat& worldRotation, const FVector& worldDirection, AFGBuildableFoundation* snappedFoundation, float& out_extension, TArray<AFGBuildableFoundation*>& overlappingFoundations ) const;
	void OverlapCheckFoundations( const FVector& worldLocation, const FQuat& worldRotation, const FVector& offsetDirection, TArray<AFGBuildableFoundation*>& out_foundations ) const;

	/** Maximum total length of the passthrough */
	UPROPERTY( EditDefaultsOnly, Category = "Passthrough" )
	float mMaxPassthroughLength;

	/** Whenever we allow the pass through to span across multiple foundations */
	UPROPERTY( EditDefaultsOnly, Category = "Passthrough" )
	bool mAllowMultiFoundationPassThrough;
	
	/** Thickness of the building we are attaching to */
	UPROPERTY( VisibleInstanceOnly, Category = "Passthrough" )
	float mSnappedBuildingThickness;
	
	/** Generated mesh components */
	UPROPERTY( VisibleInstanceOnly, Category = "Passthrough" )
	TArray< class UStaticMeshComponent* > mMeshComponents;

	/** Snapped foundations that will be ignored for the clearance check */
	UPROPERTY( VisibleInstanceOnly, Category = "Passthrough" )
	TArray<AFGBuildableFoundation*> mSnappedFoundations;
};

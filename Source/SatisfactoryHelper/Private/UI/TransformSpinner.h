#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TransformSpinner.generated.h"

class UWidget;

UCLASS(BlueprintType, Blueprintable)
class UTransformSpinner : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void SetTargetWidget(UWidget* TargetWidget);

	UFUNCTION(BlueprintCallable)
	void StartSpinning() { bIsSpinning = true; }

	UFUNCTION(BlueprintCallable)
	void StopSpinning() { bIsSpinning = false; }

	/** Ticks the object. This needs to be called manually by the outer object! */
	UFUNCTION(BlueprintCallable)
	void Tick(float DeltaTime);

	/** Adds additional velocity to the current angular velocity. Note that it will transition back to the current SpinningVelocity over time. */
	UFUNCTION(BlueprintCallable)
	void AddAngularVelocity(float AngularVelocity) { AddedAngularVelocity += AngularVelocity; }

	/** How fast to spin at max speed (in degrees per second). 45 degrees by default. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SpinningVelocity = 45;

	/** How fast to spin up to max speed/spin down. 10 by default. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SpinUpStrength = 10;

	/** How fast to spin down to 0 speed. 10 by default. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SpinDownStrength = 10;

protected:
	/** The widget to set the transform angle of. */
	UPROPERTY(BlueprintReadOnly, Meta = (ExposeOnSpawn = true))
	UWidget* Widget;

private:
	UPROPERTY()
	bool bIsSpinning;

	UPROPERTY()
	float AngularVelocity;

	UPROPERTY()
	float TargetAngularVelocity;

	UPROPERTY()
	float AddedAngularVelocity;
};
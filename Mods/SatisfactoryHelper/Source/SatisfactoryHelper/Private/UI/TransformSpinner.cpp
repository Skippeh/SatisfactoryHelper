#include "TransformSpinner.h"
#include "Components/Widget.h"

void UTransformSpinner::SetTargetWidget(UWidget* TargetWidget)
{
	verify(IsValid(TargetWidget));
	Widget = TargetWidget;
}

void UTransformSpinner::Tick(float DeltaTime)
{
	if (!IsValid(Widget))
		return;

	if (bIsSpinning)
	{
		AddedAngularVelocity = FMath::Lerp(AddedAngularVelocity, 0.f, (SpinDownStrength / 10.f) * DeltaTime);
		TargetAngularVelocity = SpinningVelocity;
	}
	else
	{
		AddedAngularVelocity = FMath::Lerp(AddedAngularVelocity, 0.f, (SpinDownStrength / 2.f) * DeltaTime);
		TargetAngularVelocity = 0;
	}

	AngularVelocity = FMath::Lerp(AngularVelocity, TargetAngularVelocity, (bIsSpinning ? SpinUpStrength : SpinDownStrength) * DeltaTime);
	
	auto WidgetAngle = Widget->GetRenderTransformAngle();
	WidgetAngle += (AngularVelocity + AddedAngularVelocity) * DeltaTime;
	
	if (WidgetAngle >= 360)
		WidgetAngle -= 360;
	else if (WidgetAngle <= -360)
		WidgetAngle += 360;
	
	Widget->SetRenderTransformAngle(WidgetAngle);
}
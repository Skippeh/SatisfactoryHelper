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
	Widget->RenderTransform.Angle += (AngularVelocity + AddedAngularVelocity) * DeltaTime;

	FWidgetTransform RenderTransform = Widget->RenderTransform;

	if (RenderTransform.Angle >= 360)
		RenderTransform.Angle -= 360;
	else if (RenderTransform.Angle <= -360)
		RenderTransform.Angle += 360;

	Widget->SetRenderTransform(RenderTransform);
}
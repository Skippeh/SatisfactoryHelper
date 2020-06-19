#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CollapsableWidgetBase.generated.h"

UCLASS(Abstract, Blueprintable)
class UCollapsableWidgetBase : public UUserWidget
{
	GENERATED_BODY()
	
public:
	// Collapses the widget. Native function is not used so you don't need to call it.
	// Return false if the widget is already collapsed or it can't be collapsed in its current state.
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	bool Collapse();

	// Expands the widget. Native function is not used so you don't need to call it.
	// Return false if the widget was already expanded or it can't be expanded in its current state.
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	bool Expand();

	// Toggles the expanded state of the widget.
	UFUNCTION(BlueprintCallable)
	void ToggleExpanded();

	// Gets whether the widget is currently expanded.
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	bool IsExpanded();

	// Sets the content of this widget.
	UFUNCTION(BlueprintCallable)
	void SetContent(UWidget* ContentWidget);

	// Sets the title shown in the header.
	UFUNCTION(BlueprintImplementableEvent)
	void SetTitle(const FText& Title);

protected:
	/** Returns the container that displays the content of this widget. */
	UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
	UPanelWidget* GetContentContainer() const;
};

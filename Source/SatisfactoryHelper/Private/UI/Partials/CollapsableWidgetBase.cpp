#include "CollapsableWidgetBase.h"

#pragma region Empty blueprint implementations
bool UCollapsableWidgetBase::Collapse_Implementation() { return bool(); }
bool UCollapsableWidgetBase::Expand_Implementation() { return bool(); }
bool UCollapsableWidgetBase::IsExpanded_Implementation() { return bool(); }
#pragma endregion

void UCollapsableWidgetBase::ToggleExpanded()
{
	if (IsExpanded())
		Collapse();
	else
		Expand();
}
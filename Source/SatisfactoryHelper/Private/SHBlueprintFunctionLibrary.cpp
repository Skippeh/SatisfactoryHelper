#include "SHBlueprintFunctionLibrary.h"
#include "Content/ContentManager.h"
#include "Resources/FGItemDescriptor.h"
#include "SHInit.h"

UContentManager* USHBlueprintFunctionLibrary::GetContentManager()
{
	return UContentManager::GetSingleton();
}

ASHInit* USHBlueprintFunctionLibrary::GetInit()
{
	return ASHInit::GetSingleton();
}
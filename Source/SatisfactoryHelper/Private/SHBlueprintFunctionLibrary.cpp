#include "SHBlueprintFunctionLibrary.h"
#include "Content/ContentManager.h"

UContentManager* USHBlueprintFunctionLibrary::GetContentManager()
{
	return UContentManager::GetSingleton();
}
#include "SHGameWorldModule.h"
#include "SHBlueprintFunctionLibrary.h"
#include "SHSaveManager.h"

void USHGameWorldModule::DispatchLifecycleEvent(ELifecyclePhase Phase)
{
	Super::DispatchLifecycleEvent(Phase);
	
	if (Phase == ELifecyclePhase::INITIALIZATION)
	{
		if (GetWorld()->GetNetMode() != NM_Client)
		{
			const auto SaveManager = USHBlueprintFunctionLibrary::GetSaveManager(GetWorld());

			if (SaveManager == nullptr)
			{
				GetWorld()->SpawnActor<ASHSaveManager>(); // todo: should probably convert this to a subsystem
			}
		}
	}
}

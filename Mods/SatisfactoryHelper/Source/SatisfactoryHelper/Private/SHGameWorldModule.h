#pragma once

#include "CoreMinimal.h"
#include "Module/GameWorldModule.h"
#include "SHGameWorldModule.generated.h"

UCLASS()
class USHGameWorldModule : public UGameWorldModule
{
	GENERATED_BODY()

	virtual void DispatchLifecycleEvent(ELifecyclePhase Phase) override;
};
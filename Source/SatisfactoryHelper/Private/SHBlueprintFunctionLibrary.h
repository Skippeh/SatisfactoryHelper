#pragma once

#include "CoreMinimal.h"
#include "SHBlueprintFunctionLibrary.generated.h"

class UContentManager;
class ASHInit;
class USHRCO;

UCLASS()
class USHBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	USHBlueprintFunctionLibrary() { }
	~USHBlueprintFunctionLibrary() { }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "SatisfactoryHelper |")
	static UContentManager* GetContentManager(UObject* InWorldContext);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "SatisfactoryHelper |")
	static USHRCO* GetRCO(UObject* InWorldContext);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "SatisfactoryHelper |")
	static USHRCO* GetRCOFromPlayer(AFGPlayerController* PlayerController);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "SatisfactoryHelper |")
	static ASHInit* GetInit(UObject* InWorldContext);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "SatisfactoryHelper | Resources")
	static bool IsItemDescriptorAnInvalidClass(TSubclassOf<class UFGItemDescriptor> InDescriptorClass);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "SatisfactoryHelper | Subsystem")
	static class USHSubsystemHolder* GetSHSubsystemHolder(UObject* WorldContext);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "SatisfactoryHelper | Subsystem")
	static class ASHCheatSubsystem* GetCheatSubsystem(UObject* WorldContext);
};

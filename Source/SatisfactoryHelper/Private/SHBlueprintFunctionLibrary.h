#pragma once

#include "CoreMinimal.h"
#include "SHBlueprintFunctionLibrary.generated.h"

class UContentManager;
class ASHInit;
class USHRCO;
class ASHSaveManager;

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

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "SatisfactoryHelper | Subsystem")
	static class USHSubsystemHolder* GetSHSubsystemHolder(UObject* WorldContext);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "SatisfactoryHelper | Subsystem")
	static class ASHCheatSubsystem* GetCheatSubsystem(UObject* WorldContext);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "SatisfactoryHelper | Subsystem")
	static class ASHItemInfoSubsystem* GetItemInfoSubsystem(UObject* WorldContext);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "SatisfactoryHelper | Recipe")
	static class AFGRecipeManager* GetRecipeManager(UObject* WorldContext);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "SatisfactoryHelper | Schematics")
	static AFGSchematicManager* GetSchematicManager(UObject* WorldContext);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "SatisfactoryHelper | Save")
	static ASHSaveManager* GetSaveManager(UObject* WorldContext);

	/** Returns true if SML debug mode is enabled. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "SatisfactoryHelper | SML")
	static bool IsDebugModeEnabled();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "SatisfactoryHelper | Debugging")
	static FString GetClassInheritancePathString(UClass* Class);
};

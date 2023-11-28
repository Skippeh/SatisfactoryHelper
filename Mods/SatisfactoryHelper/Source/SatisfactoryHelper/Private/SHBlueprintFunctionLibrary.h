#pragma once

#include "CoreMinimal.h"
#include "FGInventoryComponent.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SHBlueprintFunctionLibrary.generated.h"

class AFGSchematicManager;
class AFGPlayerController;
class UContentManager;
class ASHInit;
class USHRCO;
class ASHSaveManager;

UCLASS()
class USHBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "SatisfactoryHelper |")
	static UContentManager* GetContentManager(UObject* InWorldContext);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "SatisfactoryHelper |")
	static USHRCO* GetRCO(UObject* InWorldContext);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "SatisfactoryHelper |")
	static USHRCO* GetRCOFromPlayer(AFGPlayerController* PlayerController);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "SatisfactoryHelper |")
	static ASHInit* GetInit(UObject* InWorldContext);

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

	/** Returns true if the development mode option is checked. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "SatisfactoryHelper | Debugging")
	static bool IsDevelopmentModeEnabled(UObject* WorldContext);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "SatisfactoryHelper | Debugging")
	static FString GetClassInheritancePathString(UClass* Class);

	/** Gets the number of classes this class inherits. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "SatisfactoryHelper | Debugging")
	static int32 GetClassInheritanceLength(UClass* Class);

	/** Creates an inventory stack with the given values. This method exists to be able to create FInventoryStack in BP. FInventoryStack members do not have BlueprintReadWrite. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "SatisfactoryHelper |")
	static FInventoryStack MakeInventoryStack(TSubclassOf<UFGItemDescriptor> ItemDescriptor, int32 NumItems)
	{
		return FInventoryStack(NumItems, ItemDescriptor);
	}
};

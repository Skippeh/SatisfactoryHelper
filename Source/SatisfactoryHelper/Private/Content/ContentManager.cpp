#include "ContentManager.h"
#include "AssetRegistryModule.h"
#include "IAssetRegistry.h"
#include "FactoryGame/Public/Resources/FGItemDescriptor.h"
#include "SML/util/Logging.h"
#include "SHInit.h"
#include "ItemInfos/SHItemInfo.h"
#include "Resources/FGAnyUndefinedDescriptor.h"
#include "Resources/FGNoneDescriptor.h"
#include "Resources/FGWildCardDescriptor.h"
#include "Resources/FGResourceDescriptor.h"
#include "Resources/FGOverflowDescriptor.h"
#include "FGSchematicManager.h"
#include "FGUnlockRecipe.h"

using namespace SML;

template<class TParentClass>
void UContentManager::SearchAssetsForChildClasses(UClass* InBaseClass, TArray<TSoftClassPtr<TParentClass>>& OutArray)
{
	// Search blueprint classes using the asset registry
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>(TEXT("AssetRegistry"));
	IAssetRegistry& AssetRegistry = AssetRegistryModule.Get();

	FName BaseClassName = InBaseClass->GetFName();

	// Get derived class names
	TSet<FName> DerivedNames;
	{
		TArray<FName> BaseNames;
		BaseNames.Add(BaseClassName);

		TSet<FName> ExcludedNames;
		// Add excluded names here if needed

		AssetRegistry.GetDerivedClassNames(BaseNames, ExcludedNames, DerivedNames);
	}

	// Fetch all assets from registry deriving from UBlueprint (aka blueprint classes)
	FARFilter Filter;
	Filter.ClassNames.Add(UBlueprint::StaticClass()->GetFName());
	Filter.bRecursiveClasses = true;
	TArray<FAssetData> AssetList;
	AssetRegistry.GetAssets(Filter, AssetList);

	// Iterate through blueprint assets
	for (FAssetData const& Asset : AssetList)
	{
		// Get the text path of the generated class and get the class object path and name from it
		const FString* GeneratedClassPathPtr = Asset.TagsAndValues.Find(TEXT("GeneratedClass"));
		if (!GeneratedClassPathPtr)
			continue;

		const FString ClassObjectPath = FPackageName::ExportTextPathToObjectPath(*GeneratedClassPathPtr);
		const FString ClassName = FPackageName::ObjectPathToObjectName(ClassObjectPath);
		
		// Make sure the derived class names contains the current class
		if (!DerivedNames.Contains(FName(*ClassName)))
			continue;

		// Create soft class pointer reference and add to out array
		TSoftClassPtr<TParentClass> Result = TSoftClassPtr<TParentClass>(FStringAssetReference(ClassObjectPath));
		UClass* ItemClass = Result.Get();

		if (!IsValid(ItemClass))
			continue;

		if (ItemClass->HasAnyClassFlags(EClassFlags::CLASS_Deprecated | EClassFlags::CLASS_Abstract))
			continue;

		OutArray.Add(Result);
	}
}

void UContentManager::FindAllDescriptors(TArray<TSubclassOf<UFGItemDescriptor>>& OutArray, bool bSortByDisplayName)
{
	if (!CachedDescriptors)
	{
		CachedDescriptors = new TArray<TSubclassOf<UFGItemDescriptor>>();
		TSet<TSubclassOf<UFGItemDescriptor>> ItemDescriptorSet;
		TArray<TSubclassOf<UFGRecipe>> AllRecipes;
		GetAllRecipes(AllRecipes);

		for (TSubclassOf<UFGRecipe> Recipe : AllRecipes)
		{
			for (FItemAmount Ingredient : UFGRecipe::GetIngredients(Recipe))
			{
				ItemDescriptorSet.Add(Ingredient.ItemClass);
			}

			for (FItemAmount Product : UFGRecipe::GetProducts(Recipe))
			{
				ItemDescriptorSet.Add(Product.ItemClass);
			}
		}

		CachedDescriptors->Append(ItemDescriptorSet.Array());
	}

	OutArray.Append(*CachedDescriptors);

	if (bSortByDisplayName)
	{
		OutArray.Sort([](const TSubclassOf<UFGItemDescriptor>& ClassA, const TSubclassOf<UFGItemDescriptor>& ClassB)
		{
			FString NameA = UFGItemDescriptor::GetItemName(ClassA).ToString();
			FString NameB = UFGItemDescriptor::GetItemName(ClassB).ToString();

			return NameA < NameB;
		});
	}
}

void UContentManager::GetAllRecipes(TArray<TSubclassOf<UFGRecipe>>& OutArray)
{
	if (!CachedRecipes)
	{
		CachedRecipes = new TArray<TSubclassOf<UFGRecipe>>();
		AFGSchematicManager* SchematicManager = AFGSchematicManager::Get(GetOuter());
		TArray<TSubclassOf<UFGSchematic>> AllSchematics;
		SchematicManager->GetAllSchematics(AllSchematics);

		// Modded schematics are only added to available schematics.
		TArray<TSubclassOf<UFGSchematic>> AvailableSchematics;
		SchematicManager->GetAvailableSchematics(AvailableSchematics);
		
		for (auto Schematic : AvailableSchematics)
		{
			// Add unique because it also contains vanilla items which are already in the array.
			AllSchematics.AddUnique(Schematic);
		}

		for (TSubclassOf<UFGSchematic> Schematic : AllSchematics)
		{
			TArray<UFGUnlock*> Unlocks = UFGSchematic::GetUnlocks(Schematic);

			for (UFGUnlock* Unlock : Unlocks)
			{
				auto RecipeUnlock = Cast<UFGUnlockRecipe>(Unlock);

				if (!IsValid(RecipeUnlock))
					continue;

				CachedRecipes->Append(RecipeUnlock->GetRecipesToUnlock());
			}
		}
	}

	OutArray.Append(*CachedRecipes);
}

UContentManager::~UContentManager()
{
	if (CachedDescriptors)
		delete CachedDescriptors;

	if (CachedRecipes)
		delete CachedRecipes;
}

#pragma region Singleton implementation

UContentManager* UContentManager::GetSingleton(UObject* InWorldContext)
{
	return ASHInit::GetSingleton(InWorldContext)->GetContentManager();
}

#pragma endregion
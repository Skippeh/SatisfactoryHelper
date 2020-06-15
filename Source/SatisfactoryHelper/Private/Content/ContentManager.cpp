#include "ContentManager.h"
#include "AssetRegistryModule.h"
#include "IAssetRegistry.h"
#include "FactoryGame/Public/Resources/FGItemDescriptor.h"
#include "SML/util/Logging.h"
#include "SHInit.h"
#include "Resources/FGAnyUndefinedDescriptor.h"
#include "Resources/FGNoneDescriptor.h"
#include "Resources/FGWildCardDescriptor.h"
#include "Resources/FGResourceDescriptor.h"

using namespace SML;

TArray<TAssetSubclassOf<class UFGItemDescriptor>>* CachedDescriptors = nullptr;

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
		if (!DerivedNames.Contains(*ClassName))
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
		auto AllDescriptors = TArray<TSoftClassPtr<class UFGItemDescriptor>>();
		SearchAssetsForChildClasses<UFGItemDescriptor>(UFGItemDescriptor::StaticClass(), AllDescriptors);
		CachedDescriptors = new TArray<TSubclassOf<UFGItemDescriptor>>();
		auto InvalidItemClasses = GetInvalidItemDescriptorClasses();

		// Exclude invalid descriptor types
		for (auto DescriptorClassRef : AllDescriptors)
		{
			auto DescriptorClass = DescriptorClassRef.Get();
			bool bShouldSkipDescriptor = false;

			// Check if class inherits from a non valid item type
			for (TSubclassOf<UFGItemDescriptor> InvalidClass : InvalidItemClasses)
			{
				if (DescriptorClass->IsChildOf(InvalidClass))
				{
					bShouldSkipDescriptor = true;
					break;
				}
			}

			if (bShouldSkipDescriptor)
				continue;

			CachedDescriptors->Add(DescriptorClass);
		}
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

TArray<TSubclassOf<UFGItemDescriptor>> UContentManager::GetInvalidItemDescriptorClasses()
{
	TArray<TSubclassOf<UFGItemDescriptor>> Classes;

	Classes.Add(UFGAnyUndefinedDescriptor::StaticClass());
	Classes.Add(UFGNoneDescriptor::StaticClass());
	Classes.Add(UFGWildCardDescriptor::StaticClass());

	return Classes;
}

UContentManager::~UContentManager()
{
	if (CachedDescriptors)
		delete CachedDescriptors;
}

#pragma region Singleton implementation

UContentManager* UContentManager::GetSingleton(UObject* InWorldContext)
{
	return ASHInit::GetSingleton(InWorldContext)->GetContentManager();
}

#pragma endregion
#include "ContentManager.h"
#include "AssetRegistryModule.h"
#include "IAssetRegistry.h"
#include "FactoryGame/Public/Resources/FGItemDescriptor.h"
#include "SML/util/Logging.h"

using namespace SML;

UContentManager* UContentManager::Instance = nullptr;
TArray<TAssetSubclassOf<class UFGItemDescriptor>>* cachedDescriptors = nullptr;

template<class TParentClass>
void UContentManager::SearchAssetsForChildClasses(UClass* parent, TArray<TAssetSubclassOf<TParentClass>>& outArray)
{
	// Search blueprint classes using the asset registry
	FAssetRegistryModule& assetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>(TEXT("AssetRegistry"));
	IAssetRegistry& assetRegistry = assetRegistryModule.Get();
	FName baseClassName = parent->GetFName();

	// Get derived class names
	TSet<FName> derivedNames;
	{
		TArray<FName> baseNames;
		baseNames.Add(baseClassName);

		TSet<FName> excludedNames;
		// Add excluded names here if needed

		assetRegistry.GetDerivedClassNames(baseNames, excludedNames, derivedNames);
	}

	// Fetch all assets from registry deriving from UBlueprint (aka blueprint classes)
	FARFilter filter;
	filter.ClassNames.Add(UBlueprint::StaticClass()->GetFName());
	filter.bRecursiveClasses = true;
	TArray<FAssetData> assetList;
	assetRegistry.GetAssets(filter, assetList);

	// Iterate through blueprint assets
	for (FAssetData const& asset : assetList)
	{
		// Get the text path of the generated class and get the class object path and name from it
		const FString* generatedClassPathPtr = asset.TagsAndValues.Find(TEXT("GeneratedClass"));
		if (!generatedClassPathPtr)
			continue;

		const FString classObjectPath = FPackageName::ExportTextPathToObjectPath(*generatedClassPathPtr);
		const FString className = FPackageName::ObjectPathToObjectName(classObjectPath);

		// Make sure the derived class names contains the current class
		if (!derivedNames.Contains(*className))
			continue;

		// Create soft class pointer reference and add to out array
		TSoftClassPtr<TParentClass> result = TSoftClassPtr<TParentClass>(FStringAssetReference(classObjectPath));

		UFGItemDescriptor* itemDescriptor = Cast<UFGItemDescriptor>(result.Get());

		// todo: Check if item is in use in game if possible

		outArray.Add(result);
	}
}

void UContentManager::FindAllDescriptors(TArray<TSoftClassPtr<UFGItemDescriptor>>& outArray, bool sortByDisplayName)
{
	if (!cachedDescriptors)
	{
		cachedDescriptors = new TArray<TSoftClassPtr<class UFGItemDescriptor>>();
		SearchAssetsForChildClasses<UFGItemDescriptor>(UFGItemDescriptor::StaticClass(), *cachedDescriptors);
	}

	outArray.Append(*cachedDescriptors);

	if (sortByDisplayName)
	{
		outArray.Sort([](const TSoftClassPtr<UFGItemDescriptor>& a, const TSoftClassPtr<UFGItemDescriptor>& b)
		{
			const auto classA = TSubclassOf<UFGItemDescriptor>(a.Get());
			const auto classB = TSubclassOf<UFGItemDescriptor>(b.Get());
			UFGItemDescriptor* itemA = classA->GetDefaultObject<UFGItemDescriptor>();
			UFGItemDescriptor* itemB = classB->GetDefaultObject<UFGItemDescriptor>();

			FString nameA = UFGItemDescriptor::GetItemName(classA).ToString();
			FString nameB = UFGItemDescriptor::GetItemName(classB).ToString();

			return nameA < nameB;
		});
	}
}

UContentManager::~UContentManager()
{
	if (cachedDescriptors != nullptr)
		delete cachedDescriptors;
}

#pragma region Singleton implementation
void UContentManager::InitializeSingleton()
{
	auto* world = GEngine->GetWorld();
	auto* contentManager = NewObject<UContentManager>();
	Instance = contentManager;
}

UContentManager* UContentManager::GetSingleton()
{
	if (Instance == nullptr)
	{
		InitializeSingleton();
	}

	return Instance;
}
#pragma endregion
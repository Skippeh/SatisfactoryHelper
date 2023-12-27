#include "SHInit.h"
#include "UI/UIManager.h"
#include "Input/SHInputManager.h"
#include "Content/ContentManager.h"
#include "FGGameMode.h"
#include "FGSchematicManager.h"
#include "SHRCO.h"
#include "SHBlueprintFunctionLibrary.h"
#include "SHModule.h"
#include "ItemInfoData/SHItemInfoSubsystem.h"
#include "SHSaveManager.h"
#include "Kismet/GameplayStatics.h"

AUIManager* ASHInit::GetUIManager() const { return UIManager; }
UContentManager* ASHInit::GetContentManager() const { return ContentManager; }

void ASHInit::BeginPlay()
{
	verify(IsValid(UIManagerClass));
	ContentManager = NewObject<UContentManager>(this);

	ASHItemInfoSubsystem* ItemInfoSubsystem = USHBlueprintFunctionLibrary::GetItemInfoSubsystem(GetWorld());
	UE_LOG(LogSatisfactoryHelper, Log, TEXT("ItemInfoSubsystem is valid: %d"), IsValid(ItemInfoSubsystem));
	ItemInfoSubsystem->RegisterItemInfoClasses(ItemInfoClasses);

	SaveManager = USHBlueprintFunctionLibrary::GetSaveManager(GetWorld());	
	UIManager = GetWorld()->SpawnActor<AUIManager>(UIManagerClass);
	
	if (GetNetMode() != ENetMode::NM_Client)
	{
		AFGGameMode* GameMode = CastChecked<AFGGameMode>(GetWorld()->GetAuthGameMode());
		GameMode->RegisterRemoteCallObjectClass(USHRCO::StaticClass());
	}

	// Cache all item descriptors (subsequent calls returns from cache instead of searching assets again)
	TArray<TSubclassOf<UFGItemDescriptor>> Descriptors;
	ContentManager->FindAllDescriptors(Descriptors, false);
}

void ASHInit::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	if (!RegisteredPurchasedSchematicEvent)
	{
		auto SchematicManager = USHBlueprintFunctionLibrary::GetSchematicManager(GetWorld());

		if (SchematicManager)
		{
			SchematicManager->PurchasedSchematicDelegate.AddDynamic(this, &ASHInit::OnPurchasedSchematic);

			// No point in ticking anymore
			SetActorTickEnabled(false);
			
			RegisteredPurchasedSchematicEvent = true;
		}
	}
}

ASHInit* ASHInit::GetSingleton(const UObject* InWorldContext)
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(InWorldContext, ASHInit::StaticClass(), FoundActors);

	if (FoundActors.Num() <= 0)
		return nullptr;

	return Cast<ASHInit>(FoundActors[0]);
}

void ASHInit::OnPurchasedSchematic_Implementation(TSubclassOf<UFGSchematic> SchematicClass)
{
}
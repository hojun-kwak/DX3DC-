#include "C10_Override.h"
#include "Global.h"
#include "CPlayer.h"
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"

// Sets default values
AC10_Override::AC10_Override()
{
	CHelpers::CreateComponent<USceneComponent>(this, &Scene, "Scene");
	CHelpers::CreateComponent<UBoxComponent>(this, &Box, "Box", Scene);
	CHelpers::CreateComponent<UTextRenderComponent>(this, &Text, "Text", Scene);


	Box->SetRelativeScale3D(FVector(3));
	Box->bHiddenInGame = false;

	Text->SetRelativeLocation(FVector(0, 0, 100));
	Text->SetRelativeRotation(FRotator(0, 180, 0));
	Text->SetRelativeScale3D(FVector(2));
	Text->TextRenderColor = FColor::Red;
	Text->HorizontalAlignment = EHorizTextAligment::EHTA_Center;
	Text->Text = FText::FromString(GetName());
}

// Called when the game starts or when spawned
void AC10_Override::BeginPlay()
{
	Super::BeginPlay();
	
	OnActorBeginOverlap.AddDynamic(this, &AC10_Override::ActorBeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &AC10_Override::ActorEndOverlap);
}

void AC10_Override::ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	ChangeColorRed();
}

void AC10_Override::ActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	ChangeColorWhite();
}

void AC10_Override::ChangeColorWhite_Implementation()
{
	ACPlayer* player = Cast<ACPlayer>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	player->ChangeColor(FLinearColor(0, 0, 1));
	// 블프에서 색깔을 재정의하면 자식인 블프가 우선순위로 된다.
}


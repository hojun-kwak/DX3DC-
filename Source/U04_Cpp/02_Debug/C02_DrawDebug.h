#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C02_DrawDebug.generated.h"

UCLASS()
class U04_CPP_API AC02_DrawDebug : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category = "DrawDebug") // ��𼭳� ��������
		FVector InitLocation[5];

	UPROPERTY(EditAnywhere, Category = "DrawDebug")
		FBox Box; // ����� �ڽ� �߰�?

	UPROPERTY(EditAnywhere, Category = "DrawDebug")
		FTransform Transform;

public:	
	// Sets default values for this actor's properties
	AC02_DrawDebug();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	FVector Location[5];



};

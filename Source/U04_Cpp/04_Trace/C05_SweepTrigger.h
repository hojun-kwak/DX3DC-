#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C05_SweepTrigger.generated.h"

UCLASS()
class U04_CPP_API AC05_SweepTrigger : public AActor
{
	GENERATED_BODY()
	
private:
	UPROPERTY(VisibleDefaultsOnly)
		class USceneComponent* Scene;

	UPROPERTY(VisibleDefaultsOnly)
		class UBoxComponent* Box;

	UPROPERTY(VisibleDefaultsOnly)
		class UTextRenderComponent* Text;

public:	
	// Sets default values for this actor's properties
	AC05_SweepTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};

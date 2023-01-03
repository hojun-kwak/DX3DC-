#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C08_EventTrigger.generated.h"

UCLASS()
class U04_CPP_API AC08_EventTrigger : public AActor
{
	GENERATED_BODY()

public:
	DECLARE_EVENT_OneParam(AC08_EventTrigger, FEventTigger, int32)

private:
	UPROPERTY(VisibleDefaultsOnly)
		class USceneComponent* Scene;

	UPROPERTY(VisibleDefaultsOnly)
		class UBoxComponent* Box;

	UPROPERTY(VisibleDefaultsOnly)
		class UTextRenderComponent* Text;
	
public:	
	// Sets default values for this actor's properties
	AC08_EventTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UFUNCTION()
		void ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

public:
	FEventTigger OnEventTrigger;
};

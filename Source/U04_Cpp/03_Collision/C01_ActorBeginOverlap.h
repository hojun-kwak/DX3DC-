#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C01_ActorBeginOverlap.generated.h"

UCLASS()
class U04_CPP_API AC01_ActorBeginOverlap : public AActor
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
	AC01_ActorBeginOverlap();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	// ���������� == �Լ� ������
	// ���������� ���� UFUNCTION�� �̿��ؾ� ���ᰡ��
	UFUNCTION()
		void ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
		void ActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor);

};

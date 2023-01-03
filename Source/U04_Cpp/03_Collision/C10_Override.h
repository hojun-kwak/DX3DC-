#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C10_Override.generated.h"

UCLASS()
class U04_CPP_API AC10_Override : public AActor
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
	AC10_Override();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UFUNCTION()
		void ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
		void ActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor);

protected:
	// 선언하면 에러가 뜬다
	UFUNCTION(BlueprintImplementableEvent)
		void ChangeColorRed();

	UFUNCTION(BlueprintNativeEvent)
		void ChangeColorWhite(); // 블프 호출용

	void ChangeColorWhite_Implementation(); // 재정의(C 호출용)

};

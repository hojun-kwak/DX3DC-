#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C03_Trigger.generated.h"

// 델리케이트생성하기(객체를 생성하지않아도 생성이된다)
// 내용이 달라도 리턴값과 파라미터값만 같으면 사용가능

// 리턴값 void, 파라미터도 없는것
//					델리케이트명
DECLARE_DELEGATE(FBoxLightBeginOverlap); // void__(void)
DECLARE_DELEGATE(FBoxLightEndOverlap);   // void__(void)

// 리턴값 하나, 파라미터도 하나
//								 반환값		델리게이트명					파라미터값
DECLARE_DELEGATE_RetVal_OneParam(FString, FBoxLightRandomBeginOverlap, FLinearColor);

// Trigger 볼륨 == beginoverlap



UCLASS()
class U04_CPP_API AC03_Trigger : public AActor
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
	AC03_Trigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UFUNCTION()
		void ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
		void ActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor);

// 변수는 private지만 델리게이트는 public도 가능하다
public:
	FBoxLightBeginOverlap OnBoxLightBeginOverlap;
	FBoxLightEndOverlap OnBoxLightEndOverlap;
	FBoxLightRandomBeginOverlap OnBoxLightRandomBeginOverlap;

};

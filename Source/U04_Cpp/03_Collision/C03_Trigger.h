#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C03_Trigger.generated.h"

// ��������Ʈ�����ϱ�(��ü�� ���������ʾƵ� �����̵ȴ�)
// ������ �޶� ���ϰ��� �Ķ���Ͱ��� ������ ��밡��

// ���ϰ� void, �Ķ���͵� ���°�
//					��������Ʈ��
DECLARE_DELEGATE(FBoxLightBeginOverlap); // void__(void)
DECLARE_DELEGATE(FBoxLightEndOverlap);   // void__(void)

// ���ϰ� �ϳ�, �Ķ���͵� �ϳ�
//								 ��ȯ��		��������Ʈ��					�Ķ���Ͱ�
DECLARE_DELEGATE_RetVal_OneParam(FString, FBoxLightRandomBeginOverlap, FLinearColor);

// Trigger ���� == beginoverlap



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

// ������ private���� ��������Ʈ�� public�� �����ϴ�
public:
	FBoxLightBeginOverlap OnBoxLightBeginOverlap;
	FBoxLightEndOverlap OnBoxLightEndOverlap;
	FBoxLightRandomBeginOverlap OnBoxLightRandomBeginOverlap;

};

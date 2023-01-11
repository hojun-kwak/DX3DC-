#pragma once

#include "CoreMinimal.h"
#include "IRifle.h"
#include "GameFramework/Character.h"
#include "CPlayer.generated.h"

UCLASS()
class U04_CPP_API ACPlayer : public ACharacter, public IIRifle
{
	GENERATED_BODY()

//private:
	// �ܺο��� ���� ������ CrossHairClass
	/*UPROPERTY(EditDefaultsOnly, Category = "Widgets")
		TSubclassOf<class UC_MyUserWidget_CrossHair> CrossHairClass;*/

private:
	UPROPERTY(VisibleDefaultsOnly)
		class USpringArmComponent* SpringArm;

protected:
	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly)
		class UCameraComponent* Camera;



	// ������
public:
	FORCEINLINE class ACRifle* GetRifle() override { return Rifle; }

public:
	ACPlayer();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void GetLocationAndDirection(FVector& OutStart, FVector& OutEnd, FVector& OutDirection) override;

private:
	void OnMoveForward(float Axis);
	void OnMoveRight(float Axis);
	void OnHorizontalLook(float Axis);
	void OnVerticalLook(float Axis);

private:
	void OnRunning();
	void OffRunning();

	void OnRifle();

	// �������� ��
	void OnAim();
	void OffAim();

// C10_Override
public:
	UFUNCTION(BlueprintCallable)
		void ChangeColor(FLinearColor InColor);

	// 01/11
protected:
	UFUNCTION(BlueprintImplementableEvent)
		void OnZoomIn();

	UFUNCTION(BlueprintImplementableEvent)
		void OnZoomOut();

private:
	class UMaterialInstanceDynamic* BodyMaterial;
	class UMaterialInstanceDynamic* LogoMaterial;

private:
	// ��� ���������� �ذ��Ͻ� ���ؼ�, CPP����� �νĽ�Ű��
	class ACRifle* Rifle;
	//class UC_MyUserWidget_CrossHair* CrossHair;
};

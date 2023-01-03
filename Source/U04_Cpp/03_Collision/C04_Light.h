#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C04_Light.generated.h"

UCLASS()
class U04_CPP_API AC04_Light : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleDefaultsOnly)
		class USceneComponent* Scene;

	UPROPERTY(VisibleDefaultsOnly)
		class UTextRenderComponent* Text;

	UPROPERTY(VisibleDefaultsOnly)
		class UPointLightComponent* Light;

	UPROPERTY(VisibleDefaultsOnly)
		class UPointLightComponent* Light2;

	
public:	
	// Sets default values for this actor's properties
	AC04_Light();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UFUNCTION()
		void OnLight();

	UFUNCTION()
		void OffLight();

	UFUNCTION()
		FString OnRandomLight(FLinearColor InColor);

};

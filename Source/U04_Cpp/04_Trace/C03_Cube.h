#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C03_Cube.generated.h"

UCLASS()
class U04_CPP_API AC03_Cube : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleDefaultsOnly)
		class UStaticMeshComponent* Mesh;
	
public:	
	// Sets default values for this actor's properties
	AC03_Cube();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


};

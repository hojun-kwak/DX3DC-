#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C01_Property.generated.h"

UCLASS()
class U04_CPP_API AC01_Property : public AActor
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere) // 어디서든 볼수있음
		int A = 10;

	UPROPERTY(EditInstanceOnly) // 객체화한대서만 볼수있음 ex)Level
		int B = 20;

	UPROPERTY(EditDefaultsOnly) // 본체에서만 볼수있음 ex)bp_sword
		int C;

protected:
	UPROPERTY(VisibleAnywhere) // 보이지만 수정 불가능
		int Text = 20;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere) // 이벤트 그래프에서 값 접근가능
		int Text1 = 20;


public:	
	AC01_Property();

protected:
	virtual void BeginPlay() override;


};

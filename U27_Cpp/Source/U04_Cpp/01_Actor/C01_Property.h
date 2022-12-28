#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C01_Property.generated.h"

UCLASS()
class U04_CPP_API AC01_Property : public AActor
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere) // ��𼭵� ��������
		int A = 10;

	UPROPERTY(EditInstanceOnly) // ��üȭ�Ѵ뼭�� �������� ex)Level
		int B = 20;

	UPROPERTY(EditDefaultsOnly) // ��ü������ �������� ex)bp_sword
		int C;

protected:
	UPROPERTY(VisibleAnywhere) // �������� ���� �Ұ���
		int Text = 20;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere) // �̺�Ʈ �׷������� �� ���ٰ���
		int Text1 = 20;


public:	
	AC01_Property();

protected:
	virtual void BeginPlay() override;


};

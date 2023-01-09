#pragma once

#include "CoreMinimal.h"
#include "UObject/ConstructorHelpers.h"


class U04_CPP_API CHelpers
{
public:
	template<typename T>
	static void GetAsset(T** OutObject, FString InPath)
		// ���� ������ �ּҿ� �����ϱ� ����, �⺻ ��ȯ�� �������̱� ������ �ּ��� �ּҸ� �����ϱ� ���ؼ�
	{
		ConstructorHelpers::FObjectFinder<T> asset(*InPath);
		verifyf(asset.Succeeded(), L"asset.Succeeded()");

		*OutObject = asset.Object;
	}
	// Material ��
	template<typename T>
	static void GetAssetDynamic(T** OutObject, FString InPath)
	{
		T* obj = Cast<T>(StaticLoadObject(T::StaticClass(), NULL, *InPath));
		verifyf(!!obj, L"!!asset");

		*OutObject = obj;
	}
	// player ã�� ��
	template<typename T>
	static void GetClass(TSubclassOf<T>* OutClass, FString InPath)
	{
		ConstructorHelpers::FClassFinder<T> asset(*InPath);
		verifyf(asset.Succeeded(), L"asset.Succeeded()");

		*OutClass = asset.Class;
	}
	// player component��
	template<typename T>
	static void CreateComponent(AActor* InActor, T** InComponent, FName InName, USceneComponent* InParent = NULL)
	{
		*InComponent = InActor->CreateDefaultSubobject<T>(InName);

		if (!!InParent)
		{
			(*InComponent)->SetupAttachment(InParent);

			return;
		}

		InActor->SetRootComponent((*InComponent));
	}

	// actor ã��
	template<typename T>
	static void FindActors(class UWorld* InWorld, TArray<T *>& OutActors)
	{
		OutActors.Empty();

		TArray<AActor*> actors;
		UGameplayStatics::GetAllActorsOfClass(InWorld, T::StaticClass(), actors);

		for (AActor* actor : actors)
			OutActors.Add(Cast<T>(actor));
	}


};
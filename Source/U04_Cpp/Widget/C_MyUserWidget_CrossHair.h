#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "C_MyUserWidget_CrossHair.generated.h"

UCLASS()
class U04_CPP_API UC_MyUserWidget_CrossHair : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
		void OnFocus();

	UFUNCTION(BlueprintImplementableEvent)
		void OffFocus();
	
};

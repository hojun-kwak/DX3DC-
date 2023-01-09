#include "Notifies/CAnimNotifyState.h"
#include "Global.h"
#include "IRifle.h"
#include "CRifle.h"

//FString UCAnimNotifyState_Equip::GetNotifyName_Implementation() const
//{
//	return "Equip";
//}

FString UCAnimNotifyState::GetNotifyName_Implementation() const
{
	return "Equip";
}

void UCAnimNotifyState::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration);
	CheckNull(MeshComp);

	IIRifle* rifle = Cast<IIRifle>(MeshComp->GetOwner());
	CheckNull(rifle);

	rifle->GetRifle()->Begin_Equip();
}

void UCAnimNotifyState::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::NotifyEnd(MeshComp, Animation);
	CheckNull(MeshComp);

	IIRifle* rifle = Cast<IIRifle>(MeshComp->GetOwner());
	CheckNull(rifle);

	rifle->GetRifle()->End_Equip();
}

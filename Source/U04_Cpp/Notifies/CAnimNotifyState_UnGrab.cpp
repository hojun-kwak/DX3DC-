#include "Notifies/CAnimNotifyState_UnGrab.h"
#include "Global.h"
#include "IRifle.h"
#include "CRifle.h"

FString UCAnimNotifyState_UnGrab::GetNotifyName_Implementation() const
{
	return "UnEquip";
}

void UCAnimNotifyState_UnGrab::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration);
	CheckNull(MeshComp);

	IIRifle* rifle = Cast<IIRifle>(MeshComp->GetOwner());
	CheckNull(rifle);

	rifle->GetRifle()->Begin_UnEquip();
}

void UCAnimNotifyState_UnGrab::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::NotifyEnd(MeshComp, Animation);
	CheckNull(MeshComp);

	IIRifle* rifle = Cast<IIRifle>(MeshComp->GetOwner());
	CheckNull(rifle);

	rifle->GetRifle()->End_UnEquip();
}

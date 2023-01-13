#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CRifle.generated.h"

UCLASS()
class U04_CPP_API ACRifle : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleDefaultsOnly, Category = "Rifle")
		class USkeletalMeshComponent* Mesh;

	UPROPERTY(VisibleDefaultsOnly, Category = "Rifle")
		FName HandSocket = "Hand_Rifle";

	UPROPERTY(VisibleDefaultsOnly, Category = "Rifle")
		FName HolsterSocket = "Holster_Rifle";

	UPROPERTY(VisibleDefaultsOnly, Category = "Rifle")
		class UAnimMontage* GrabMontage;

	UPROPERTY(VisibleDefaultsOnly, Category = "Rifle")
		class UAnimMontage* UngrabMontage;

	UPROPERTY(VisibleDefaultsOnly, Category = "Rifle")
		class UAnimMontage* FireMontage;

	// ÅºÇÇ, ÃÑÈ­¿°
	UPROPERTY(VisibleDefaultsOnly, Category = "Rifle")
		class UParticleSystem* FlashParticle;

	UPROPERTY(VisibleDefaultsOnly, Category = "Rifle")
		class UParticleSystem* EjectParticle;

	UPROPERTY(VisibleDefaultsOnly, Category = "Rifle")
		class UParticleSystem* ImpactParticle;

	// »ç¿îµå
	UPROPERTY(VisibleDefaultsOnly, Category = "Rifle")
		class USoundCue* FireSoundCue;

	UPROPERTY(VisibleDefaultsOnly, Category = "Rifle")
		TSubclassOf<class ACBullet> BulletClass;

	// ÅºÈçÀÚ±¹
	UPROPERTY(VisibleDefaultsOnly, Category = "Rifle")
		class UMaterialInstanceConstant* DecalMaterial;

public:	
	// Sets default values for this actor's properties
	ACRifle();

	void Equip();
	void Begin_Equip();
	void End_Equip();

	void UnEquip();
	void Begin_UnEquip();
	void End_UnEquip();

	void Begin_Aiming();
	void End_Aiming();

	void Begin_Fire();
	void Firing();
	void End_Fire();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	

public:
	static ACRifle* Spawn(class UWorld* InWorld, class ACharacter* InOwner);

public:
	// ÃÖÀûÈ­
	FORCEINLINE bool GetEquipped() { return bEquipped; }
	FORCEINLINE bool GetEquipping() { return bEquipping; }
	FORCEINLINE bool GetAiming() { return bAiming; }

private:
	class ACharacter* OwnerCharacter;

// ÀåÂøµÇ¾ú´ÂÁö È®ÀÎÇÏ´Â º¯¼ö
	bool bEquipped;
	bool bEquipping;
	bool bAiming;
	bool bFiring;

};

#include "CBullet.h"
#include "Global.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Materials/MaterialInstanceConstant.h"

// Sets default values
ACBullet::ACBullet()
{
	CHelpers::CreateComponent(this, &Mesh, "Mesh");
	CHelpers::CreateActorComponent(this, &Projectile, "Projectile");


	UStaticMesh* mesh;
	CHelpers::GetAsset<UStaticMesh>(&mesh, "StaticMesh'/Game/Meshes/M_Sphere.M_Sphere'");
	Mesh->SetStaticMesh(mesh);

	UMaterialInstanceConstant* material;
	CHelpers::GetAsset<UMaterialInstanceConstant>(&material, "MaterialInstanceConstant'/Game/Materials/M_Bullet_Inst.M_Bullet_Inst'");
	Mesh->SetMaterial(0, material); // 메테리얼이 기본은0 여러개일경우도있음
	Mesh->SetRelativeScale3D(FVector(1.0f, 0.025f, 0.025f));

	Projectile->InitialSpeed = 2e+4f;
	Projectile->MaxSpeed = 2e+4f;
	Projectile->ProjectileGravityScale = 0.0f;
	Projectile->SetUpdatedComponent(Mesh);

	InitialLifeSpan = 3.0f;

}

// Called when the game starts or when spawned
void ACBullet::BeginPlay()
{
	Super::BeginPlay();

	Mesh->OnComponentHit.AddDynamic(this, &ACBullet::OnHit);
}

void ACBullet::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	Destroy();
}


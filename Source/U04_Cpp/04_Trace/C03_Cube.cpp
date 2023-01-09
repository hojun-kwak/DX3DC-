#include "C03_Cube.h"
#include "Global.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AC03_Cube::AC03_Cube()
{
	CHelpers::CreateComponent<UStaticMeshComponent>(this, &Mesh, "Mesh");

	UStaticMesh* mesh;
	// StaticMesh'/Game/Meshes/M_Cube.M_Cube'
	CHelpers::GetAsset<UStaticMesh>(&mesh, "StaticMesh'/Game/Meshes/M_Cube.M_Cube'");
	Mesh->SetStaticMesh(mesh);
	Mesh->SetSimulatePhysics(true); // 물리엔진 설정
	Mesh->SetCollisionObjectType(ECollisionChannel::ECC_PhysicsBody);

}

// Called when the game starts or when spawned
void AC03_Cube::BeginPlay()
{
	Super::BeginPlay();
	
}


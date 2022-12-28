#include "C02_SpawnActor_Cone.h"
#include "Global.h"

AC02_SpawnActor_Cone::AC02_SpawnActor_Cone()
{
	// StaticMesh'/Game/Meshes/M_Cone.M_Cone'

	UStaticMesh* mesh;
	CHelpers::GetAsset<UStaticMesh>(&mesh, "StaticMesh'/Game/Meshes/M_Cone.M_Cone'");
	Mesh->SetStaticMesh(mesh);
}
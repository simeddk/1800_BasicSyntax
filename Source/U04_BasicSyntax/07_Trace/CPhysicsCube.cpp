#include "CPhysicsCube.h"
#include "Global.h"

ACPhysicsCube::ACPhysicsCube()
{
	CHelpers::CreateSceneComponent(this, &Mesh, "Mesh");

	UStaticMesh* meshAsset;
	CHelpers::GetAsset(&meshAsset, "/Game/StaticMeshes/SM_Cube");
	Mesh->SetStaticMesh(meshAsset);
	Mesh->SetSimulatePhysics(true);
	Mesh->SetCollisionObjectType(ECollisionChannel::ECC_PhysicsBody);

	UMaterial* materailAsset;
	CHelpers::GetAsset(&materailAsset, "Material'/Game/StaticMeshes/Textures/MAT_Box.MAT_Box'");
	Mesh->SetMaterial(0, materailAsset);
}


#include "CRifle.h"
#include "Global.h"
#include "GameFramework/Character.h"

ACRifle::ACRifle()
{
	PrimaryActorTick.bCanEverTick = true;

	CHelpers::CreateSceneComponent(this, &Mesh, "Mesh");

	USkeletalMesh* meshAsset;
	CHelpers::GetAsset(&meshAsset, "SkeletalMesh'/Game/Weapons/Meshes/AR4/SK_AR4.SK_AR4'");
	Mesh->SetSkeletalMesh(meshAsset);

	CHelpers::GetAsset(&GrabMontage, "AnimMontage'/Game/Character/Animations/Rifle/Rifle_Grab_Montage.Rifle_Grab_Montage'");
	CHelpers::GetAsset(&UngrabMontage, "AnimMontage'/Game/Character/Animations/Rifle/Rifle_Ungrab_Montage.Rifle_Ungrab_Montage'");
}

ACRifle* ACRifle::Spawn(UWorld* InWorld, ACharacter* InOwner)
{
	FActorSpawnParameters param;
	param.Owner = InOwner;

	return InWorld->SpawnActor<ACRifle>(param);
}

void ACRifle::Equip()
{
	CheckTrue(bEquipping);

	bEquipping = true;
	OwnerCharacter->PlayAnimMontage(GrabMontage);
}

void ACRifle::Unequip()
{
}

void ACRifle::BeginPlay()
{
	Super::BeginPlay();

	OwnerCharacter = Cast<ACharacter>(GetOwner());

	AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules(EAttachmentRule::KeepRelative, true), HolsterSocket);
}

void ACRifle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


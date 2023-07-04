#include "CRifle.h"
#include "Global.h"
#include "GameFramework/Character.h"
#include "Engine/StaticMeshActor.h"
#include "Chracters/IRifle.h"

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

void ACRifle::BeginPlay()
{
	Super::BeginPlay();

	OwnerCharacter = Cast<ACharacter>(GetOwner());

	AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules(EAttachmentRule::KeepRelative, true), HolsterSocket);
}

void ACRifle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	CheckFalse(bAiming);

	//Get Aim Info
	IIRifle* rifleCharacter = Cast<IIRifle>(OwnerCharacter);
	CheckNull(rifleCharacter);

	FVector start, end, direction;
	rifleCharacter->GetAimInfo(start, end, direction);
	//DrawDebugLine(GetWorld(), start, end, FColor::Red, false, -1.f, 0, 3.f);

	//LineTrace(AimWidget)
	FCollisionQueryParams param;
	param.AddIgnoredActor(this);
	param.AddIgnoredActor(OwnerCharacter);

	FHitResult hitResult;
	if (GetWorld()->LineTraceSingleByChannel
	(
		hitResult,
		start,
		end,
		ECollisionChannel::ECC_PhysicsBody,
		param
	))
	{
		AStaticMeshActor* smActor = Cast<AStaticMeshActor>(hitResult.GetActor());
		if (!!smActor)
		{
			UStaticMeshComponent* smComp = Cast<UStaticMeshComponent>(smActor->GetRootComponent());
			if (!!smComp)
			{
				if (smComp->BodyInstance.bSimulatePhysics == true)
				{
					OtherComp = smComp;

					rifleCharacter->OnTarget();
					return;
				}
			}
		}
	}

	OtherComp = nullptr;
	rifleCharacter->OffTarget();
}

void ACRifle::Begin_Aiming()
{
	bAiming = true; 
}

void ACRifle::End_Aiming()
{ 
	bAiming = false; 
}

void ACRifle::Equip()
{
	CheckTrue(bEquipping);

	bEquipping = true;
	OwnerCharacter->PlayAnimMontage(GrabMontage);
}

void ACRifle::Begin_Equip()
{
	bEquipped = true;
	
	AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules(EAttachmentRule::KeepRelative, true), HandSocket);
}

void ACRifle::End_Equip()
{
	bEquipping = false;
}

void ACRifle::Unequip()
{
	CheckTrue(bEquipping);

	bEquipping = true;
	OwnerCharacter->PlayAnimMontage(UngrabMontage);
}

void ACRifle::Begin_Unequip()
{
	bEquipped = false;

	AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules(EAttachmentRule::KeepRelative, true), HolsterSocket);
}

void ACRifle::End_Unequip()
{
	bEquipping = false;
}

void ACRifle::Begin_Fire()
{
	CheckFalse(bEquipped);
	CheckTrue(bEquipping);
	CheckFalse(bAiming);
	CheckTrue(bFiring);

	bFiring = true;

	Firing();
}

void ACRifle::End_Fire()
{
	bFiring = false;
}

void ACRifle::Firing()
{
	FVector direction;

	//Add Impulse
	if (!!OtherComp)
	{
		FVector start = OwnerCharacter->GetActorLocation();
		FVector target = OtherComp->GetComponentToWorld().GetLocation();

		direction = target - start;
		direction.Normalize();

		OtherComp->AddImpulseAtLocation(direction * 3000.f, start);
	}
}



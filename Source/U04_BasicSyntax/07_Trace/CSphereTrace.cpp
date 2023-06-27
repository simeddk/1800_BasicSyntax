#include "CSphereTrace.h"
#include "Global.h"
#include "Components/TextRenderComponent.h"
#include "Particles/ParticleSystemComponent.h"

ACSphereTrace::ACSphereTrace()
{
	CHelpers::CreateSceneComponent(this, &Particle, "Particle");
	CHelpers::CreateSceneComponent(this, &Text, "Text", Particle);

	UParticleSystem* particleAsset;
	CHelpers::GetAsset(&particleAsset, "ParticleSystem'/Game/Particles/P_Destruction1.P_Destruction1'");
	Particle->SetTemplate(particleAsset);
	Particle->bAutoActivate = false;

	Text->SetRelativeRotation(FRotator(0, 180, 0));
	Text->SetTextRenderColor(FColor::Red);
	Text->SetHorizontalAlignment(EHorizTextAligment::EHTA_Center);
	Text->SetWorldSize(60);
	Text->SetText(FText::FromString("Boom Here!!!!"));
}

void ACSphereTrace::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACSphereTrace::Explosion(AActor* OverlappedActor, AActor* OtherActor)
{
	FVector start = GetActorLocation();
	FVector end = start + 10;

	TArray<TEnumAsByte<EObjectTypeQuery>> objectTypes;
	objectTypes.Add(EObjectTypeQuery::ObjectTypeQuery4);

	TArray<AActor*> ignores;

	//Todo. HitResult, IgnoreSelf
	//if (UKismetSystemLibrary::SphereTraceMultiForObjects
	//(
	//	GetWorld(),
	//	start,
	//	end,
	//	1000,
	//	objectTypes,
	//	false,
	//	ignores,
	//	EDrawDebugTrace::ForDuration,
	//	
	//	
	//))
	//{
	//	
	//}
}


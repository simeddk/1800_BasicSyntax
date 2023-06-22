#include "CMulticast.h"
#include "Global.h"

void ACMulticast::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &ACMulticast::BeginOverlap);
}

void ACMulticast::BeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OnMulticast.IsBound())
	{
		int32 index = UKismetMathLibrary::RandomIntegerInRange(0, 2);

		FLinearColor color = FLinearColor::MakeRandomColor();
		color.A = 1.f;

		OnMulticast.Broadcast(index, color);
	}
}
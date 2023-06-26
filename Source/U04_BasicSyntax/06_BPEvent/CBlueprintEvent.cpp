#include "CBlueprintEvent.h"
#include "Global.h"
#include "Chracters/CPlayer.h"

void ACBlueprintEvent::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &ACBlueprintEvent::BeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &ACBlueprintEvent::EndOverlap);
}

void ACBlueprintEvent::BeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	ACPlayer* player = Cast<ACPlayer>(OtherActor);
	CheckNull(player);

	ChangePlayerColor();
}

void ACBlueprintEvent::EndOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	ACPlayer* player = Cast<ACPlayer>(OtherActor);
	CheckNull(player);

	ResetPlayerColor();
}

void ACBlueprintEvent::ResetPlayerColor_Implementation()
{
	ACPlayer* player = Cast<ACPlayer>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	CheckNull(player);

	player->SetColor_Reset();
}
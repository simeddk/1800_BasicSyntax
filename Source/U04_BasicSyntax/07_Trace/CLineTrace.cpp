#include "CLineTrace.h"
#include "Global.h"
#include "CVertex.h"

ACLineTrace::ACLineTrace()
{
	PrimaryActorTick.bCanEverTick = true;

	CHelpers::CreateSceneComponent(this, &Root, "Root");
}

void ACLineTrace::BeginPlay()
{
	Super::BeginPlay();
	
	TArray<AActor*> actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACVertex::StaticClass(), actors);
	CheckFalse(actors.Num() > 0);

	//Todo. ���࿡ ���忡 1���� ���ؽ��� �ִٸ�..?
	Vertices[0] = Cast<ACVertex>(actors[0]);
	Vertices[1] = Cast<ACVertex>(actors[1]);
}

void ACLineTrace::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


#pragma once

#include "CoreMinimal.h"
#include "04_Collision/CBox.h"
#include "CActorOverlap.generated.h"

UCLASS()
class U04_BASICSYNTAX_API ACActorOverlap : public ACBox
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
		void BeginOverlap(AActor* OverlappedActor, AActor* OtherActor);
};

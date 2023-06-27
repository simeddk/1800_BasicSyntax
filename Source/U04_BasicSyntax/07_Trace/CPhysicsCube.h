#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPhysicsCube.generated.h"

UCLASS()
class U04_BASICSYNTAX_API ACPhysicsCube : public AActor
{
	GENERATED_BODY()
	
public:	
	ACPhysicsCube();

private:
	UPROPERTY(VisibleDefaultsOnly)
		class UStaticMeshComponent* Mesh;

};

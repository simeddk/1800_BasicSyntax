#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CSpheres.generated.h"

UCLASS()
class U04_BASICSYNTAX_API ACSpheres : public AActor
{
	GENERATED_BODY()
	
public:	
	ACSpheres();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleDefaultsOnly)
		class USceneComponent* Root;

	UPROPERTY(VisibleDefaultsOnly)
		class UStaticMeshComponent* Spheres[3];

};

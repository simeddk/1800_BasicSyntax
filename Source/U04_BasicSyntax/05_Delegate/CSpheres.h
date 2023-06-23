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
	UFUNCTION()
		void Fall(int32 InIndex, FLinearColor InColor);

private:
	UPROPERTY(VisibleDefaultsOnly)
		class USceneComponent* Root;

	UPROPERTY(VisibleDefaultsOnly)
		class UStaticMeshComponent* Spheres[3];

private:
	class UMaterialInstanceDynamic* DynamicMaterials[3];
	FVector OrginLocation[3];

	int32 Number = 100;
};

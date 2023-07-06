#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CRifle.generated.h"

UCLASS()
class U04_BASICSYNTAX_API ACRifle : public AActor
{
	GENERATED_BODY()
	
public:	
	ACRifle();

	static ACRifle* Spawn(class UWorld* InWorld, class ACharacter* InOwner);

	FORCEINLINE bool IsEquipped() { return bEquipped; }
	FORCEINLINE bool IsEquipping() { return bEquipping; }
	FORCEINLINE bool IsAiming() { return bAiming; }
	FORCEINLINE bool IsFiring() { return bFiring; }
	FORCEINLINE bool IsRapid() { return bRapid; }
	FORCEINLINE void ToggleRapid() { bRapid = !bRapid; }

	void Begin_Aiming();
	void End_Aiming();

public:
	void Equip(); //Play Grab Montage
	void Begin_Equip();
	void End_Equip();

	void Unequip(); //Play Ungrab Montage
	void Begin_Unequip();
	void End_Unequip();

	void Begin_Fire();
	void End_Fire();

	UFUNCTION()
		void Firing();
	

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Socket")
		FName HolsterSocket = "Holster_Rifle";

	UPROPERTY(EditDefaultsOnly, Category = "Socket")
		FName HandSocket = "Hand_Rifle";

	UPROPERTY(EditDefaultsOnly, Category = "Montages")
		class UAnimMontage* GrabMontage;

	UPROPERTY(EditDefaultsOnly, Category = "Montages")
		class UAnimMontage* UngrabMontage;

	UPROPERTY(EditDefaultsOnly, Category = "Camera")
		TSubclassOf<class UCameraShake> FireShakeClass;
	
	UPROPERTY(EditDefaultsOnly, Category = "Bullet")
		TSubclassOf<class ACBullet> BulletClass;

	UPROPERTY(EditDefaultsOnly, Category = "Effect")
		class UParticleSystem* MuzzleParticle;

	UPROPERTY(EditDefaultsOnly, Category = "Effect")
		class UParticleSystem* EjectParticle;

	UPROPERTY(EditDefaultsOnly, Category = "Effect")
		class UParticleSystem* ImpactParticle;

	UPROPERTY(EditDefaultsOnly, Category = "Effect")
		class USoundCue* FireSound;

	UPROPERTY(EditDefaultsOnly, Category = "Effect")
		class UMaterial* Decal;

	UPROPERTY(EditDefaultsOnly, Category = "Effect")
		float PitchSpeed = 0.25f;

private:
	UPROPERTY(VisibleDefaultsOnly)
		class USkeletalMeshComponent* Mesh;

private:
	class ACharacter* OwnerCharacter;

	class UStaticMeshComponent* OtherComp;

	bool bEquipped;		//Is On Hand Socket
	bool bEquipping;	//Is Montage Playing
	bool bAiming;		//Is R-Button Pressed
	bool bFiring;		//Is L-Button Pressed
	bool bRapid;		//Is Auto Firing

	FTimerHandle RapidTimer;

	float CurrentPitch;
};

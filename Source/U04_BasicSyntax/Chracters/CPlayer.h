#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "IRifle.h"
#include "CPlayer.generated.h"

UCLASS()
class U04_BASICSYNTAX_API ACPlayer : public ACharacter, public IIRifle
{
	GENERATED_BODY()

public:
	ACPlayer();

	FORCEINLINE class ACRifle* GetRifle() override { return Rifle; }
	void GetAimInfo(FVector& OutAimStart, FVector& OutAimEnd, FVector& OutDirection) override;

	void OnTarget() override;
	void OffTarget() override;

	UFUNCTION(BlueprintCallable)
		void SetColor(FLinearColor InBodyColor, FLinearColor InLogoColor);

	UFUNCTION(BlueprintCallable)
		void SetColor_Reset();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private: //Axis Event
	void OnMoveForward(float Axis);
	void OnMoveRight(float Axis);

	void OnHorizontalLook(float Axis);
	void OnVerticalLook(float Axis);

private: //Action Event
	void OnSprint();
	void OffSprint();

	void OnRifle();

	void OnAim();
	void OffAim();

	void OnFire();
	void OffFire();

protected:
	UFUNCTION(BlueprintImplementableEvent)
		void ZoomIn();

	UFUNCTION(BlueprintImplementableEvent)
		void ZoomOut();

private:
	UPROPERTY(VisibleDefaultsOnly)
		class USpringArmComponent* SpringArm;

protected:
	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly)
		class UCameraComponent* Camera;

private:
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class UCUserWidget_Aim> AimWidgetClass;

private:
	class UMaterialInstanceDynamic* BodyMaterial;
	class UMaterialInstanceDynamic* LogoMaterial;

	class ACRifle* Rifle;

	class UCUserWidget_Aim* AimWidget;
	
};

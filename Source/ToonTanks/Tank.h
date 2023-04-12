// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Method to Destroy Actor
	void HandleDestruction();

public:
	ATank();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// Create Spring Arm Component
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "POV", meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* ArmComp;

	// Create Camera Component
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "POV", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CameraCom;

	// Varibale Speed to Tank
	UPROPERTY(EditAnyWhere, Category = "Movement")
	float speed = 200.f;

	UPROPERTY(EditAnyWhere, Category = "Movement")
	float TurnRate = 45.f;

	// Method to Move the tank
	void Move(float value);	

	// Method to Turn the tank
	void Turn(float value);	

	APlayerController* PlayerControllerRef;
};
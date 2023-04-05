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

public:
	ATank();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// Create Spring Arm Component
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "POV", meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* ArmComp;

	// Create Camera Component
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "POV", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CameraCom;

	// Method to Move the tank
	void Move(float value);
};



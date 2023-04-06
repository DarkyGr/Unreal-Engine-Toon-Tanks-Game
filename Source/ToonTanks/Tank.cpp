// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"

ATank::ATank()
{
    ArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
    ArmComp->SetupAttachment(RootComponent);

    CameraCom = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    CameraCom->SetupAttachment(ArmComp);
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    // Setup The move for the AXIS
    PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATank::Move);
}

void ATank::Move(float value)
{
    // UE_LOG(LogTemp, Warning, TEXT("Value: %f"), value);

    // Create FVector and set all axis equal to 0
	FVector DeltaLocation = FVector::ZeroVector;    

    // X = value * DeltaTime * Speed
	DeltaLocation.X = value * speed * UGameplayStatics::GetWorldDeltaSeconds(this);
	
    // Enabled Collision with true
    AddActorLocalOffset(DeltaLocation, true);

}
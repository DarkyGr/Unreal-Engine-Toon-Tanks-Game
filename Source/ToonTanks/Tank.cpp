// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

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

    // Setup the turn for the AXIS
    PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ATank::Turn);
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    // Check if PlayerControllerRef doesn't null
    if (PlayerControllerRef)
    {
        FHitResult HitResult;

        PlayerControllerRef->GetHitResultUnderCursor(
            ECollisionChannel::ECC_Visibility, 
            false,
            HitResult);            
    }
    
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();

    // Cast AController to PLayerController
    PlayerControllerRef = Cast<APlayerController>(GetController());
    
    // Draw sphere in front of our tank
    DrawDebugSphere(
        GetWorld(), 
        GetActorLocation() + FVector(0.f, 0.f, 200.f),
        100.f,
        12,
        FColor::Red,
        true,
        30.f);
}

void ATank::Move(float value)
{
    // UE_LOG(LogTemp, Warning, TEXT("Value: %f"), value);

    // Create FVector and set all axis equal to 0
	FVector DeltaLocation = FVector::ZeroVector;    

    // X = value * Speed * DeltaTime
	DeltaLocation.X = value * speed * UGameplayStatics::GetWorldDeltaSeconds(this);
	
    // Enabled Collision with true
    AddActorLocalOffset(DeltaLocation, true);

}

void ATank::Turn(float value)
{
    // UE_LOG(LogTemp, Warning, TEXT("Value: %f"), value);

    // Create FRotator and set all axis equal to 0   
    FRotator DeltaRotation = FRotator::ZeroRotator;

    // Yaw = value * DeltaTime * TurnRate
    DeltaRotation.Yaw = value * TurnRate * UGameplayStatics::GetWorldDeltaSeconds(this);

    // Enabled Collision with true
    AddActorLocalRotation(DeltaRotation, true);
}
// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

ATank::ATank()
{
    ArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
    ArmComp->SetupAttachment(RootComponent);

    CameraCom = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    CameraCom->SetupAttachment(ArmComp);
}
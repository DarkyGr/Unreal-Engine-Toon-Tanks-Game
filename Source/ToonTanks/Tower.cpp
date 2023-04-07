// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"

// Called every frame
void ATower::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Find the distance to the Tank
    if (Tank)
    {
        float distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());

        // Check to see if the Tank is in range

        // If in range, rotate turrent
    }
}

// Called when the game starts or when spawned
void ATower::BeginPlay()
{
	Super::BeginPlay();   

    // Set Player 0 to the Tank
    Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
}
// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

// Called every frame
void ATower::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    
    if (InFireRange())
    {        
        RotateTurrent(Tank->GetActorLocation());
    }
}

void ATower::HandleDestruction()
{
    Super::HandleDestruction();
    Destroy();
}

// Called when the game starts or when spawned
void ATower::BeginPlay()
{
	Super::BeginPlay();   

    // Set Player 0 to the Tank
    Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));

    // Set Time of the World
    GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &ATower::CheckFireCondition, FireRate, true);
}

void ATower::CheckFireCondition()
{
    if(Tank == nullptr)
    {
        return;
    }
    if (InFireRange() && Tank->bAlive)
    {
        Fire();
    }    
}

bool ATower::InFireRange()
{
    // Find the distance to the Tank
    if (Tank)
    {
        float distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());

        // Check to see if the Tank is in range
        if (distance <= FireRange)
        {
            // If in range, rotate turrent
            return true;
        }        
    }

    return false;    
}
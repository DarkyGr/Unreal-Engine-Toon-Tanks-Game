// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Tank.h"
#include "Tower.h"

void AToonTanksGameMode::ActorDied(AActor* DeadActor)
{   
    // Check if than the Tank is dead
    if (DeadActor == Tank)
    {
        // Destroy Tank
        Tank->HandleDestruction();
        
        if (Tank->GetTankPlayerController())
        {
            // No Move Tank WASD
            Tank->DisableInput(Tank->GetTankPlayerController());

            // No Move mouse
            Tank->GetTankPlayerController()->bShowMouseCursor = false;
        }
    }
    else if (ATower* DestroyedTower = Cast<ATower>(DeadActor))
    {
        // Destroy Tower
        DestroyedTower->HandleDestruction();
    }
    
    
}

void AToonTanksGameMode::BeginPlay()
{
    Super::BeginPlay();

    // Set Player of Tank
    Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
}
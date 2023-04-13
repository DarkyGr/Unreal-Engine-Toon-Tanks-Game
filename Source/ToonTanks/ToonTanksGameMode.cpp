// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Tank.h"
#include "Tower.h"
#include "ToonTanksPlayerController.h"

void AToonTanksGameMode::ActorDied(AActor* DeadActor)
{   
    // Check if than the Tank is dead
    if (DeadActor == Tank)
    {
        // Destroy Tank
        Tank->HandleDestruction();
        
        if (ToonTanksPlayerController)
        {
            // No Move Tank WASD
            // Tank->DisableInput(Tank->GetTankPlayerController());

            // No Move mouse
            // Tank->GetTankPlayerController()->bShowMouseCursor = false;

            ToonTanksPlayerController->SetPlayerEnabledState(false);
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

    // Set Player Controller of Toon Tanks Player Controller
    ToonTanksPlayerController = Cast<AToonTanksPlayerController>(UGameplayStatics::GetPlayerController(this, 0));

}
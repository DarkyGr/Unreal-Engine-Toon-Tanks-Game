// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ToonTanksGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API AToonTanksGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	// Method to save the Dead Actor
	void ActorDied(AActor* DeadActor);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Method to Start Game (Widget)
	UFUNCTION(BlueprintImplementableEvent)
	void StartGame();

private:
	// Class Tank
	class ATank* Tank;

	// Class ToonTanksPlayerController
	class AToonTanksPlayerController* ToonTanksPlayerController;

	// Delay of start game
	float StartDelay = 3.f;

	// Method when Start Game
	void HandleGameStart();
};

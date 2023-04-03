// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

	UPROPERTY(VisibleAnyWhere)
	int32 VisibleAnyWhereInt = 12;

	UPROPERTY(EditAnyWhere)
	int32 EditAnyWhereInt = 12;

	UPROPERTY(VisibleInstanceOnly)
	int32 VisibleInstanceOnlyInt = 12;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	// Create Capsule Component to Pawn
	UPROPERTY()
	class UCapsuleComponent* CapsuleComp;

	// Create Static Mesh Component to Base of Actor
	UPROPERTY()
	UStaticMeshComponent* BaseMesh;

	// Create Static Mesh Component to Turrent of Actor
	UPROPERTY()
	UStaticMeshComponent* TurrentMesh;

	// Create Scene Component to Projectile of Actor
	UPROPERTY()
	USceneComponent* ProjectileSpawnPoint;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

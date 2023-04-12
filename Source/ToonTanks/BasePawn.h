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

	// Read & Write only in the Instance
	// UPROPERTY(VisibleInstanceOnly)
	// int32 VisibleInstanceOnlyInt = 12;

	// UPROPERTY(EditInstanceOnly)
	// int32 EditInstanceOnlyInt = 11;


	// Read & Write only in the Default
	// UPROPERTY(VisibleDefaultsOnly)
	// int32 VisibleDefaultsOnlyInt = 5;

	// UPROPERTY(EditDefaultsOnly)
	// int32 EditDefaultsOnlyInt = 10;
	

	// Read & Write only in both
	// UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	// float TestVariable = 12.0f;

	/*
		Exponed Variables in Event Graph use in UPROPERTY([PROPERTY], BlueprintReadWrite) || UPROPERTY([PROPERTY], BlueprintReadOnly)

		- BlueprintReadWrite: gives the user GET and SET access to the variable
		- BlueprintReadOnly: gives the user GET access to the variable

	*/

	// Method to Destroy Actor
	void HandleDestruction();

protected:
	// Method to Rotate Turrent
	void RotateTurrent(FVector LookAtTarget);

	// Method to Fire Projectile
	void Fire();

private:

	// Create Capsule Component to Pawn
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* CapsuleComp;

	// Create Static Mesh Component to Base of Actor
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh;

	// Create Static Mesh Component to Turrent of Actor
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurrentMesh;

	// Create Scene Component to Projectile of Actor
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* ProjectileSpawnPoint;

	/*
		When using private, and you want to expose to Event Graph, you require a third property on UPROPERTY:
		- meta = (AllowPrivateAccess = "true") ... for example:
			UPROPERTY([PROPERTY], [PROPERTY of Event Graph], meta = (AllowPrivateAccess = "true"))		
	*/

	/*
		You can add a category for the variables you add.
		This can be done with a new property in UPROPERTY
			UPROPERTY([PROPERTY], [PROPERTY of Event Graph], Category = "Example Name", meta = (AllowPrivateAccess = "true"))
		
		*** If you name the category with an existing name, this variable will be added to that same category
	*/

	// UPROPERTY(VisibleAnyWhere, BlueprintReadWrite, Category = "Nice Variables", meta = (AllowPrivateAccess = "true"))
	// int32 VisibleAnyWhereInt = 12;

	// UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "Nice Variables", meta = (AllowPrivateAccess = "true"))
	// int32 EditAnyWhereInt = 12;


	// Generate Projectiles
	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	TSubclassOf<class AProjectile> ProjectileClass;

};

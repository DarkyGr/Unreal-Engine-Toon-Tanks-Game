// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Projectile.h"
#include "Kismet/GameplayStatics.h"
// #include "DrawDebugHelpers.h"

// Sets default values
ABasePawn::ABasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(CapsuleComp);

	TurrentMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turrent Mesh"));
	TurrentMesh->SetupAttachment(BaseMesh);

	ProjectileSpawnPoint = CreateAbstractDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(TurrentMesh);


}


void ABasePawn::HandleDestruction()
{
	// All: Visual/Sound effects
	UGameplayStatics::SpawnEmitterAtLocation(this, DeadParticles, GetActorLocation(), GetActorRotation());
}

void ABasePawn::RotateTurrent(FVector LookAtTarget)
{
	// Get "ToTarget" = TraceLocation - TurrentLocation
	FVector ToTarget = LookAtTarget - TurrentMesh->GetComponentLocation();

	// Set Rotation 
	FRotator LookAtRotation = FRotator(0.f, ToTarget.Rotation().Yaw, 0.f);

	// Rotation of world
	TurrentMesh->SetWorldRotation(LookAtRotation);
}

void ABasePawn::Fire()
{
	// UE_LOG(LogTemp, Error, TEXT("FIREEEEE"));
	
	// Get Location of projectile
	FVector Location = ProjectileSpawnPoint->GetComponentLocation();
	
	// Draw sphere
	// DrawDebugSphere(
	// 	GetWorld(),
	// 	ProjectileSpawnPointLocation,
	// 	25.f,
	// 	12,
	// 	FColor::Red,
	// 	false,
	// 	3.f
	// );

	// Spawn Projectile
	FRotator Rotation = ProjectileSpawnPoint->GetComponentRotation();

	auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileClass, Location, Rotation);
	Projectile->SetOwner(this);
}

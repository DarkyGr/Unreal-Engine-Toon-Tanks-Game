// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "GameFramework/DamageType.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectile Mesh"));
	RootComponent = ProjectileMesh;

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement Component"));	
	ProjectileMovementComponent->MaxSpeed = 1300.f;
	ProjectileMovementComponent->InitialSpeed = 1300.f;

	TrailParticles = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Smoke Trail"));
	TrailParticles->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();

	// Dynamic to Projectile and Hit
	ProjectileMesh->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);

	// Check if Exist LaunchSound
	if (LaunchSound)
	{
		// Adding Launch Sound
		UGameplayStatics::PlaySoundAtLocation(this, LaunchSound, GetActorLocation());
	}
	
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// UE_LOG(LogTemp, Warning, TEXT("ON HIT"));
	// UE_LOG(LogTemp, Error, TEXT("HitComp: %s"), *HitComp->GetName());
	// UE_LOG(LogTemp, Warning, TEXT("OtherActor: %s"), *OtherActor->GetName());
	// UE_LOG(LogTemp, Display, TEXT("OtherComp: %s"), *OtherComp->GetName());

	// Set Owner
	auto MyOwner = GetOwner();

	// Check it doesn't be null
	if (MyOwner == nullptr)
	{
		Destroy();
		return;
	}

	// Set Instigator by Owner
	auto MyOwnerInstigator = MyOwner->GetInstigatorController();

	// Set Damage Type
	auto DamageTypeClass = UDamageType::StaticClass();
	
	if (OtherActor && OtherActor != this && OtherActor != MyOwner)
	{
		// Adding Damage
		UGameplayStatics::ApplyDamage(OtherActor, Damage, MyOwnerInstigator, this, DamageTypeClass);		

		if (HitParticles)
		{
			// Adding Particles
			UGameplayStatics::SpawnEmitterAtLocation(this, HitParticles, GetActorLocation(), GetActorRotation());			
		}		

		if (HitSound)
		{
			// Adding Hit Sound
			UGameplayStatics::PlaySoundAtLocation(this, HitSound, GetActorLocation());
		}		

		if(HitCameraShakeClass)
		{
			// Adding Hit Camera Shake
			GetWorld()->GetFirstPlayerController()->ClientPlayCameraShake(HitCameraShakeClass);
		}
	}

	Destroy();	
}


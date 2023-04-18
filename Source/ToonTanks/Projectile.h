// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

class USoundBase;

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	UStaticMeshComponent* ProjectileMesh;

	UPROPERTY(VisibleAnywhere, Category = "Movement")
	class UProjectileMovementComponent* ProjectileMovementComponent;

	// Hit of Projectile
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	// Variable to Damage
	UPROPERTY(EditAnywhere)
	float Damage = 50.f;

	// Particles for Projectile Hit
	UPROPERTY(EditAnywhere, Category = "Combat");
	class UParticleSystem* HitParticles;

	// Particles for Projectile Trail
	UPROPERTY(VisibleAnywhere, Category = "Combat");
	class UParticleSystemComponent* TrailParticles;

	// Sound for Laucnh Projectile
	UPROPERTY(EditAnywhere, Category = "Combat")
	USoundBase* LaunchSound;

	// Sound for Hit Projectile
	UPROPERTY(EditAnywhere, Category = "Combat")
	USoundBase* HitSound;

	// Hit Camera Shake
	UPROPERTY(EditAnywhere, Category = "Combat")
	TSubclassOf<class UCameraShakeBase> HitCameraShakeClass;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

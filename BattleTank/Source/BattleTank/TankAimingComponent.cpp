// Fill out your copyright notice in the Description page of Project Settings.
#include "TankAimingComponent.h"
#include "Components/ActorComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	Barrel = BarrelToSet;
}
void UTankAimingComponent::SetTurretReference(UTankTurret * TurretToSet)
{
	Turret = TurretToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	//Calculate the OutLaunchVelocity
	if (UGameplayStatics::SuggestProjectileVelocity(
			this,
			OutLaunchVelocity,
			StartLocation,
			HitLocation,
			LaunchSpeed,
		false,
		0,
		0,
			ESuggestProjVelocityTraceOption::DoNotTrace
		)
	)
		
	{
	
	auto AimDirection = OutLaunchVelocity.GetSafeNormal();
	MoveBarrelTowards(AimDirection);
	}
	else {
		UE_LOG(LogTemp,Warning,TEXT("Cant aim correctly"))
	};
}


void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection){
	//Workout difference between current barrel rotation and aimdirecton
	auto BarrelRotation = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotation;
	
		//Move the barrel the right amount this frame
		//Given max elevation speed , and frame time
		Barrel->Elevate(DeltaRotator.Pitch);
		Turret->RotateTurret(DeltaRotator.Yaw);
	
}
// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAiController.h"

void ATankAiController::BeginPlay() {
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	auto PlayerTank = GetPlayerTank();
	if (!ControlledTank && !PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("AIController not possesing a tank"))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Im possesed by an AI: %s"), *ControlledTank->GetName())
			UE_LOG(LogTemp, Warning, TEXT("Target : %s"), *PlayerTank->GetName())
	}
}
void ATankAiController::Tick(float DeltaTime)
{
	
	Super::Tick(DeltaTime);
	if (GetPlayerTank()) {
		//TODO move towards player

		//Aim Towards player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		//Fire when ready
	}
	
}
ATank* ATankAiController::GetControlledTank() const {

	return Cast<ATank>(GetPawn());
}

ATank* ATankAiController::GetPlayerTank() const {

	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}


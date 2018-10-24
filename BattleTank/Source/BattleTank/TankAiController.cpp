// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAiController.h"
#include "Tank.h"


void ATankAiController::BeginPlay() {
	Super::BeginPlay();

}
void ATankAiController::Tick(float DeltaTime)
{
	
	Super::Tick(DeltaTime);
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());
	if (!ControlledTank && !PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("AIController not possesing a tank"))
	}
	if (PlayerTank) {
		//TODO move towards player

		//Aim Towards player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		
		//Fire when ready
		ControlledTank->Fire(); //TODO dont fire everyframe
	}
	
}


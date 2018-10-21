// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing a tank"))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Im possesed : %s"), *ControlledTank->GetName())
	}
}
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
		AimTowardsCrosshair();
}
ATank* ATankPlayerController::GetControlledTank() const {return Cast<ATank>(GetPawn());}

void ATankPlayerController::AimTowardsCrosshair() {
	if (!GetControlledTank()) { return; }
	
	FVector HitLocation; //OUT parameter dont bother to initialise out parameters
	if (GetSightRayHitLocation(HitLocation)) { //has side effect , is going to line trace
		
			
		GetControlledTank()->AimAt(HitLocation);
	}
}
//Get World location of linetrace through crosshair, ture if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const  {

	//Find crosshair position in pixel coords
	int32 ViewportSizeX,ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX *CrosshairXLocation, ViewportSizeY *CrosshairYLocation);
	
	//DE-project screenposition of the crosshair to a world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection)) {
		
			//Linetrace along that look direction and see what we hit up to max range
		GetLookVectorHitLocation(LookDirection, HitLocation);
	}
	
	
	return true;
}
bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
			HitResult,
			StartLocation,
			EndLocation,
			ECC_Visibility
	)
		) {
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection)const {
	FVector CameraWorldLocation; //discard
	return DeprojectScreenPositionToWorld(
									ScreenLocation.X,
									ScreenLocation.Y,
									CameraWorldLocation, 
									LookDirection
								);
	
	
}



// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/PlayerController.h"
#include "GameFramework/Controller.h"
#include "Engine/World.h"

#include "TankPlayerController.generated.h"
class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public: 
protected:
	UFUNCTION(BlueprintCallable,Category ="Setup")
	ATank* GetControlledTank() const;
private:
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	//Start the tank moving the barrel so that a shot would hit where 
	//the crosshair intersects the world
	void AimTowardsCrosshair();
	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = 0.5f;
	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = 0.333333f;
	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 100000.f;


	//return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	//return the direction the player looks on screen
	bool GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const;
	//return the hitlocation via linetrace
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation)const;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTracks.generated.h"

/**
 * Tank  Track is used to set maximum drving force, and move the tank
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTracks : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public: 
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);
	//This is max force per track in  Newtons
	UPROPERTY(EditDefaultsOnly, Category = Driving)
		float MaxDrivingForce = 400000; // Assume 40 tons tank at 1g accel
	
};

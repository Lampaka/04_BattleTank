// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

/**
 * 
 */
class UTankTracks;
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable, Category = Setup)
		void IntendMoveForward(float Throw);
	UFUNCTION(BlueprintCallable, Category = Setup)
	void Initialise(UTankTracks * LeftTrackToSet, UTankTracks * RightTrackToSet);
	UFUNCTION(BlueprintCallable, Category = Setup)
	void IntendTurnRight(float Throw);

	
private:
	UTankTracks* RightTrack = nullptr;
	UTankTracks* LeftTrack = nullptr;
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;
};

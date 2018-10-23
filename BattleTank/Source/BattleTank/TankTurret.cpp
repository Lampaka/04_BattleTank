// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Engine/World.h"



void UTankTurret::RotateTurret(float RotateTurrets) {
	//Move the barrel the right amount this frame
	//Given a max elevation speed,and the frame time
	RotateTurrets = FMath::Clamp<float>(RotateTurrets, 0, 360);
	
	UE_LOG(LogTemp,Warning,TEXT("We got here Rotate Turret = %f"),RotateTurrets)
		

}

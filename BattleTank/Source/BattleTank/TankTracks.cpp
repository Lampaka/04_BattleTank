// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTracks.h"
#include "Tank.h"



void UTankTracks::SetThrottle(float Throttle) {
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s value: %f"), *Name, Throttle)

		//TODO Clamp actual throttle value

		auto ForceApplied = GetForwardVector() * Throttle * MaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot =Cast<UPrimitiveComponent>( GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
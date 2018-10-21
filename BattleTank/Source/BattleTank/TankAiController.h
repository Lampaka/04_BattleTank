// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Controller.h"
#include "Engine/World.h"
#include "TankAiController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAiController : public AAIController
{
	GENERATED_BODY()
	
	
public:
	ATank* GetControlledTank() const;
	ATank* GetPlayerTank() const;
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	
};

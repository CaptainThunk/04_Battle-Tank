// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "Engine.h"
//#include "CoreMinimal.h"
//#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // Must be the last include

// Forward Declarations
class ATank;


/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	
private:
	ATank* GetControlledTank() const;

	// Start the tank moving the barrel so that a shot would hit where
	// the crosshair intersects the world
	void AimTowardsCrosshair();

	// Return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333;

	// How far ahead of the player can we linetrace looking for hit (in cm)
	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000.f;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
};

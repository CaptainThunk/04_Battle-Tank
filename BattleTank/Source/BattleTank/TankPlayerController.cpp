// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"




void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("TankPlayerController Begin Play"));

	auto ControlledTank = GetControlledTank();
	
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController not possessed"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Possessed TankPlayerController is: %s"), *(ControlledTank->GetName()));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();

}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector OutHitLocation; // Out Parameter

	if (GetSightRayHitLocation(OutHitLocation)) // Has "side-effect", is going to line trace
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *OutHitLocation.ToString());
		
		// TODO Tell controlled tank to aim at this point
	}	
}

// Get world location if linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{/*
	// Linetrace
	/// Get player viewpoint
	FPlayerViewPoints PlayerViewPoints = GetPlayerViewPoints();
	FVector LineTraceEnd = PlayerViewPoints.PlayerViewPointLocation + (PlayerViewPoints.PlayerViewPointRotation.Vector() * Reach);

	/// Setup query parameters
	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());

	/// Line-trace (AKA ray-Cast) out to reach distance
	FHitResult HitResult;
	GetWorld()->LineTraceSingleByObjectType(
		OUT HitResult,
		PlayerViewPoints.PlayerViewPointLocation,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParameters
	);

	HitResult->Location();
	return true;
	*/
	OutHitLocation = FVector(1.0);
	return false;
}

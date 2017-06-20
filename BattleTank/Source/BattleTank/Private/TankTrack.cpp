// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
#include "BattleTank.h"


void UTankTrack::SetThrottle(float Throttle)
{
	//auto Time = GetWorld()->GetTimeSeconds();
	auto Name = GetName();

	UE_LOG(LogTemp, Warning, TEXT("%s: throttle at %f"), *Name, Throttle);

	// TODO clamp throttle between -1 and +1
}

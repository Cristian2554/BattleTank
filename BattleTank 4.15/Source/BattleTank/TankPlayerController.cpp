// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController Not Possesing a Tank"));
	} else {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController Possesing: %s"), *ControlledTank->GetName());
	}
	
}

ATank* ATankPlayerController::GetControlledTank() const {
	return Cast <ATank>(GetPawn());
}

virtual void ATankPlayerController::Tick(float DeltaTime) override {
	Super::Tick( DeltaTime );
}
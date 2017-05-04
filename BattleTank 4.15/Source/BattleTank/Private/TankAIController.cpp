// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("AIController Can't Find the Player"));
	} else {
		UE_LOG(LogTemp, Warning, TEXT("AIController found the player: %s"), *PlayerTank->GetName());
	}

}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	if (GetPlayerTank()) {
		//TODO Move towards the player

		//Aim  towards the player
		GetControlledTank()->AimAt(GetControlledTank()->GetActorLocation());

		//Fire if ready
	}
	
}

ATank* ATankAIController::GetControlledTank() const {
	return Cast <ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const {
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	return Cast <ATank>(PlayerTank);
}



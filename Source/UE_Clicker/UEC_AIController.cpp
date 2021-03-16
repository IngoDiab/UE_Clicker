// Fill out your copyright notice in the Description page of Project Settings.


#include "UEC_AIController.h"

AUEC_AIController::AUEC_AIController()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AUEC_AIController::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AUEC_AIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
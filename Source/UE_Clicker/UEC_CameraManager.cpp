// Fill out your copyright notice in the Description page of Project Settings.


#include "UEC_CameraManager.h"

// Sets default values
AUEC_CameraManager::AUEC_CameraManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AUEC_CameraManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUEC_CameraManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AUEC_CameraManager::TestMethods()
{
}


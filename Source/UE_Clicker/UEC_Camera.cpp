// Fill out your copyright notice in the Description page of Project Settings.


#include "UEC_Camera.h"
#include "UEC_CameraManager.h"
#include "UEC_CameraSettings.h"
#include "ClickerGM.h"

// Sets default values
AUEC_Camera::AUEC_Camera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AUEC_Camera::BeginPlay()
{
	Super::BeginPlay();
	TestCamera();
	
}

// Called every frame
void AUEC_Camera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AUEC_Camera::TestCamera()
{
	AClickerGM* _gameMode = GetWorld()->GetAuthGameMode<AClickerGM>();
	if (!_gameMode) return;
	UE_LOG(LogTemp, Warning, TEXT("GAMEMODE"));
	AUEC_CameraManager* _cameraManager = _gameMode->GetCameraManager();
	if (!_cameraManager) return;
	UE_LOG(LogTemp, Warning, TEXT("CAMERAMANAGER"));
	_cameraManager->TestMethods();
}

void AUEC_Camera::MoveTo()
{
	UUEC_CameraSettings _settings = GetComponentByClass<UEC_CameraSettings>();
}


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
	InitCamera();
	
}

// Called every frame
void AUEC_Camera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveTo();
	LookAt();
	DrawDebug();
}

void AUEC_Camera::InitCamera()
{
	//Add camera to manager
	AddToManager();

	//Get Camera Settings
	InitCameraSettings();

	//Get Camera Component
	InitCameraComponent();
}

void AUEC_Camera::InitCameraSettings()
{
	UActorComponent* _comp = GetComponentByClass(UUEC_CameraSettings::StaticClass());
	if (!_comp) return;
	cameraSettings = Cast<UUEC_CameraSettings>(_comp);
}

void AUEC_Camera::InitCameraComponent()
{
	UActorComponent* _comp = GetComponentByClass(UCameraComponent::StaticClass());
	if (!_comp) return;
	cameraComp = Cast<UCameraComponent>(_comp);
}

void AUEC_Camera::AddToManager()
{
	AClickerGM* _gameMode = GetWorld()->GetAuthGameMode<AClickerGM>();
	if (!_gameMode) return;
	AUEC_CameraManager* _cameraManager = _gameMode->GetCameraManager();
	if (!_cameraManager) return;
	_cameraManager->Add(this);
}

bool AUEC_Camera::IsAtPos()
{
	return FVector::Distance(GetActorLocation(), GetFinalPositionCamera()) < 1;
}

void AUEC_Camera::MoveTo()
{
	if (IsAtPos() || !IsValid()) return;
	SetActorLocation(UKismetMathLibrary::VLerp(GetActorLocation(), GetFinalPositionCamera(), GetWorld()->DeltaTimeSeconds*cameraSettings->GetSpeedMove()));
}

void AUEC_Camera::LookAt()
{
	UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), GetFinalLookAtCamera());
}

FVector AUEC_Camera::GetFinalPositionCamera()
{
	if (!IsValid()) return GetActorLocation();
	FVector _offsetPos = cameraSettings->GetPosition();
	FVector _pos = cameraSettings->GetTarget()->GetActorLocation() + FVector::ForwardVector * _offsetPos.X + FVector::RightVector * _offsetPos.Y + FVector::UpVector * _offsetPos.Z;
	return _pos;
}

FVector AUEC_Camera::GetFinalLookAtCamera()
{
	if (!IsValid()) return FVector();
	FVector _offsetLookAt = cameraSettings->GetPosition();
	FVector _posLookAt = cameraSettings->GetTarget()->GetActorLocation() + FVector::ForwardVector * _offsetLookAt.X + FVector::RightVector * _offsetLookAt.Y + FVector::UpVector * _offsetLookAt.Z;
	return _posLookAt;
}

bool AUEC_Camera::IsValid()
{
	return cameraSettings && cameraComp;
}

int AUEC_Camera::GetID()
{
	return id;
}

UUEC_CameraSettings* AUEC_Camera::GetCameraSettings()
{
	return cameraSettings;
}

UCameraComponent* AUEC_Camera::GetCameraComponent()
{
	return cameraComp;
}

void AUEC_Camera::DrawDebug()
{
	DrawDebugSphere(GetWorld(), GetFinalPositionCamera(), 50, 100, FColor::Cyan, false, .1f, .1f);
	DrawDebugLine(GetWorld(), GetFinalPositionCamera(), cameraSettings->GetTarget()->GetActorLocation(), FColor::Cyan, false, .1f, .1f);

	DrawDebugSphere(GetWorld(), GetFinalLookAtCamera(), 50, 100, FColor::Red , false, .1f, .1f);
	DrawDebugLine(GetWorld(), GetFinalLookAtCamera(), GetActorLocation(), FColor::Red, false, .1f, .1f);
}


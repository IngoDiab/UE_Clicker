// Fill out your copyright notice in the Description page of Project Settings.


#include "UEC_Camera.h"
#include "UEC_CameraManager.h"
#include "UEC_CameraSettings.h"
#include "ClickerGM.h"

#pragma region UEMethods
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

	onCameraUpdate.AddLambda([this]()
	{
		MoveTo();
		LookAt();
		DrawDebug();
	});
	
}

// Called every frame
void AUEC_Camera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
#pragma endregion

#pragma region CustomMethods
AUEC_CameraManager* AUEC_Camera::GetCameraManager()
{
	AClickerGM* _gamemode = GetWorld()->GetAuthGameMode<AClickerGM>();
	if (!_gamemode) return nullptr;
	return _gamemode->GetCameraManager();
}

void AUEC_Camera::InitCamera()
{
	//Add camera to manager
	AddToManager();

	//Get Camera Component
	InitCameraComponent();
}

void AUEC_Camera::InitCameraSettings(int _id, FCameraSettings& _settings)
{
	id = _id;
	cameraSettings = _settings;
}

void AUEC_Camera::InitCameraComponent()
{
	UActorComponent* _comp = GetComponentByClass(UCameraComponent::StaticClass());
	if (!_comp) return;
	cameraComp = Cast<UCameraComponent>(_comp);
}

void AUEC_Camera::AddToManager()
{
	AUEC_CameraManager* _cameraManager = GetCameraManager();
	if (!_cameraManager) return;
	_cameraManager->Add(this);
}

bool AUEC_Camera::IsAtPos()
{
	return FVector::Distance(GetActorLocation(), GetFinalPositionCamera()) < 1;
}

void AUEC_Camera::MoveTo()
{
	if (!IsValid() || !cameraSettings.canMove || IsAtPos()) return;
	SetActorLocation(UKismetMathLibrary::VLerp(GetActorLocation(), GetFinalPositionCamera(), GetWorld()->DeltaTimeSeconds*cameraSettings.speedMove));
}

void AUEC_Camera::LookAt()
{
	if (!IsValid() || !cameraSettings.canLookAt) return;
	FRotator _newRotation = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), GetFinalLookAtCamera());
	SetActorRotation(UKismetMathLibrary::RInterpTo(GetActorRotation(), _newRotation, GetWorld()->DeltaTimeSeconds, cameraSettings.speedLookAt));
}

FVector AUEC_Camera::GetFinalPositionCamera()
{
	if (!IsValid()) return GetActorLocation();
	FVector _offsetPos = cameraSettings.offsetPos;
	FVector _pos = cameraSettings.target->GetActorLocation() + FVector::ForwardVector * _offsetPos.X + FVector::RightVector * _offsetPos.Y + FVector::UpVector * _offsetPos.Z;
	return _pos;
}

FVector AUEC_Camera::GetFinalLookAtCamera()
{
	if (!IsValid()) return FVector();
	FVector _offsetLookAt = cameraSettings.offsetLookAt;
	FVector _posLookAt = cameraSettings.target->GetActorLocation() + FVector::ForwardVector * _offsetLookAt.X + FVector::RightVector * _offsetLookAt.Y + FVector::UpVector * _offsetLookAt.Z;
	return _posLookAt;
}

bool AUEC_Camera::IsValid()
{
	return cameraComp && cameraSettings.target != nullptr;
}

int AUEC_Camera::GetID()
{
	return id;
}

FCameraSettings AUEC_Camera::GetCameraSettings()
{
	return cameraSettings;
}

void AUEC_Camera::SetCameraSettings(FCameraSettings _settings)
{
	cameraSettings = _settings;
}

UCameraComponent* AUEC_Camera::GetCameraComponent()
{
	return cameraComp;
}

void AUEC_Camera::DrawDebug()
{
	if (!IsValid() || !canDraw)return;

	//DEBUG POSITION CAMERA
	DrawDebugSphere(GetWorld(), GetFinalPositionCamera(), 50, 100, FColor::Cyan, false, .1f, .1f);
	DrawDebugLine(GetWorld(), GetFinalPositionCamera(), cameraSettings.target->GetActorLocation(), FColor::Cyan, false, .1f, .1f);

	//DEBUG LOOKAT CAMERA
	DrawDebugSphere(GetWorld(), GetFinalLookAtCamera(), 50, 100, FColor::Red , false, .1f, .1f);
	DrawDebugLine(GetWorld(), GetFinalLookAtCamera(), GetActorLocation(), FColor::Red, false, .1f, .1f);
}
#pragma endregion


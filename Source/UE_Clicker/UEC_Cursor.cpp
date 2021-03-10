// Fill out your copyright notice in the Description page of Project Settings.

#include "UEC_Cursor.h"
#include "ClickerGM.h"
#include "Kismet/KismetMathLibrary.h"

#pragma region UEMethods
// Sets default values
AUEC_Cursor::AUEC_Cursor()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AUEC_Cursor::BeginPlay()
{
	Super::BeginPlay();
	EnablePlayerCamera();
	lastClickPosition = GetActorLocation();
}

// Called every frame
void AUEC_Cursor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move();
	Rotate();
}

// Called to bind functionality to input
void AUEC_Cursor::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAction("SetMoveTarget", IE_Pressed, this, &AUEC_Cursor::Click);
}

#pragma endregion

#pragma region CustomMethods
APlayerController* AUEC_Cursor::GetPlayerController()
{
	return GetWorld()->GetFirstPlayerController();
}

AUEC_CameraManager* AUEC_Cursor::GetCameraManager()
{
	AClickerGM* _gamemode = GetWorld()->GetAuthGameMode<AClickerGM>();
	if (!_gamemode) return nullptr;
	return _gamemode->GetCameraManager();
}

AUEC_FXManager* AUEC_Cursor::GetFXManager()
{
	AClickerGM* _gamemode = GetWorld()->GetAuthGameMode<AClickerGM>();
	if (!_gamemode) return nullptr;
	return _gamemode->GetFXManager();
}

void AUEC_Cursor::EnablePlayerCamera()
{
	//ENABLE THE PLAYER CAMERA
	AUEC_CameraManager* _manager = GetCameraManager();
	if (!_manager) return;
	_manager->Enable(id);
}

void AUEC_Cursor::Click()
{
	//GET POSITION TO GO
	APlayerController* _controller = GetPlayerController();
	if (!_controller)return;
	FHitResult _hit;
	_controller->GetHitResultUnderCursorForObjects(allObjectsHitable, true, _hit);
	lastClickPosition = _hit.Location;

	//SET THE FX CURSOR TO THE POSITION TO GO
	AUEC_FXManager* _fxManager = GetFXManager();
	if (!_fxManager) return;
	_fxManager->SetPosition(lastClickPosition);
	_fxManager->Hide(false);
}

FVector AUEC_Cursor::GetLastClickPosition()
{
	return lastClickPosition;
}

bool AUEC_Cursor::IsAtPos()
{
	return FVector::Distance(GetActorLocation(), lastClickPosition) < 1;
}

void AUEC_Cursor::Move()
{
	//HIDE FX CURSOR
	if (!stats.canMove || IsAtPos())
	{
		AUEC_FXManager* _fxManager = GetFXManager();
		if (!_fxManager) return;
		_fxManager->Hide(true);
	}

	//MOVE THE PLAYER
	else
		SetActorLocation(UKismetMathLibrary::VInterpTo(GetActorLocation(), lastClickPosition, GetWorld()->DeltaTimeSeconds, stats.moveSpeed));
}

void AUEC_Cursor::Rotate() 
{
	//ROTATE THE PLAYER IF HE CAN
	if (!stats.canRotate || IsAtPos()) return;
	FRotator _newRotation = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), lastClickPosition);
	SetActorRotation(UKismetMathLibrary::RInterpTo(GetActorRotation(), _newRotation, GetWorld()->DeltaTimeSeconds, stats.rotateSpeed));
}
#pragma endregion


// Fill out your copyright notice in the Description page of Project Settings.

#include "UEC_Cursor.h"
#include "ClickerGM.h"
#include "Kismet/KismetMathLibrary.h"

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

void AUEC_Cursor::EnablePlayerCamera()
{
	AClickerGM* _gamemode = GetWorld()->GetAuthGameMode<AClickerGM>();
	if (!_gamemode) return;
	AUEC_CameraManager* _manager = _gamemode->GetCameraManager();
	if (!_manager) return;
	_manager->Enable(id);
}

void AUEC_Cursor::Click()
{
	APlayerController* _controller = GetWorld()->GetFirstPlayerController();
	if (!_controller)return;
	FHitResult _hit;
	_controller->GetHitResultUnderCursorForObjects(allObjectsHitable, true, _hit);
	lastClickPosition = _hit.Location;
	UE_LOG(LogTemp, Warning, TEXT("%f,%f,%f"), _hit.Location.X, _hit.Location.Y, _hit.Location.Z);
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
	if (!stats.canMove || IsAtPos()) return;
	SetActorLocation(UKismetMathLibrary::VInterpTo(GetActorLocation(), lastClickPosition, GetWorld()->DeltaTimeSeconds, stats.moveSpeed));
}

void AUEC_Cursor::Rotate() 
{
	if (!stats.canRotate || IsAtPos()) return;
	FRotator _newRotation = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), lastClickPosition);
	SetActorRotation(UKismetMathLibrary::RInterpTo(GetActorRotation(), _newRotation, GetWorld()->DeltaTimeSeconds, stats.rotateSpeed));
}


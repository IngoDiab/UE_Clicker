// Fill out your copyright notice in the Description page of Project Settings.

#include "UEC_Cursor.h"

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

	ShowCursor(true);
	
}

// Called every frame
void AUEC_Cursor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AUEC_Cursor::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAction("SetMoveTarget", IE_Pressed, this, &AUEC_Cursor::Click);
}

void AUEC_Cursor::ShowCursor(bool _show)
{
	APlayerController* _controller = GetWorld()->GetFirstPlayerController();
	if (!_controller)return;
	_controller->bShowMouseCursor = _show;
}

void AUEC_Cursor::Click()
{
	APlayerController* _controller = GetWorld()->GetFirstPlayerController();
	if (!_controller)return;
	FHitResult _hit;
	_controller->GetHitResultUnderCursorByChannel(ETraceTypeQuery::TraceTypeQuery1, true, _hit);
	lastClickPosition = _hit.Location;
	UE_LOG(LogTemp, Warning, TEXT("%f,%f,%f"), _hit.Location.X, _hit.Location.Y, _hit.Location.Z);
}

FVector AUEC_Cursor::GetLastClickPosition()
{
	return lastClickPosition;
}


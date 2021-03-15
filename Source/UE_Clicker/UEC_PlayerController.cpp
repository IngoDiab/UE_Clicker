// Fill out your copyright notice in the Description page of Project Settings.


#include "UEC_PlayerController.h"
#include "UEC_Cursor.h"

/*AUEC_PlayerController::AUEC_PlayerController()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AUEC_PlayerController::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AUEC_PlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AUEC_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	//SETMOVETARGET BUTTON => CLICK METHOD
	InputComponent->BindAction("SetMoveTarget", IE_Pressed, this, &AUEC_PlayerController::ActionOnClick);
}

void AUEC_PlayerController::ActionOnClick()
{
	AUEC_Cursor* _pawn = GetPawn<AUEC_Cursor>();
	UE_LOG(LogTemp, Warning, TEXT("CLICK"));

	FHitResult _hit;
	bool _hasHit = GetHitResultUnderCursorForObjects(allObjectsHitable, true, _hit);
	if (!_hasHit) return;
	lastClickPosition = _hit.Location;

	AController* _IA = GetPawn()->AIControllerClass.GetDefaultObject();
	if (!_IA) return;
	UE_LOG(LogTemp, Warning, TEXT("SALOPE"));
	AUEC_AIController* _iaContr = Cast<AUEC_AIController>(_IA);
	if (!_iaContr) return;
	UE_LOG(LogTemp, Warning, TEXT("SALOPE111"));
	_iaContr->SetTargetToGo(lastClickPosition);

	/*if (!_pawn) return;
	UE_LOG(LogTemp, Warning, TEXT("PAWN"));
	_pawn->Click();
}*/

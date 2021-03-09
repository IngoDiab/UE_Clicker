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
	UE_LOG(LogTemp, Warning, TEXT("Input"));
	InputComponent->BindAction("SetMoveTarget", IE_Pressed, this, &AUEC_Cursor::TestInput);
}

void AUEC_Cursor::TestInput()
{
	UE_LOG(LogTemp, Warning, TEXT("Click"));
}


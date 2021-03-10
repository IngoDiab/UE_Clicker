// Fill out your copyright notice in the Description page of Project Settings.


#include "UEC_Player.h"
#include "Components/ActorComponent.h"

// Sets default values
AUEC_Player::AUEC_Player()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AUEC_Player::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AUEC_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Move();
}

void AUEC_Player::SetTargetPosition(FVector _position)
{
	targetPosition = _position;
}

bool AUEC_Player::IsAtPos()
{
	return FVector::Distance(GetActorLocation(),targetPosition) < 1;
}

void AUEC_Player::Move()
{
	if (IsAtPos()) return;
	//SetActorLocation(UKismetMathLibrary::VLerp(GetActorLocation(), targetPosition, GetWorld()->DeltaTimeSeconds));
}

bool AUEC_Player::IsValid() 
{
	return true;
	//return cursor!=nullptr;
}

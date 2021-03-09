// Fill out your copyright notice in the Description page of Project Settings.


#include "UEC_Player.h"
#include "Kismet/KismetMathLibrary.h"
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

	//TOCHANGE
	APlayerController* _controller = GetWorld()->GetFirstPlayerController();
	if (!_controller)return;
	UE_LOG(LogTemp, Warning, TEXT("tg1"));
	APawn* _pawn = _controller->GetPawn();
	if (!_pawn)return;
	UE_LOG(LogTemp, Warning, TEXT("tg2"));
	cursor = Cast<AUEC_Cursor>(_pawn);
}

// Called every frame
void AUEC_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move();

}

bool AUEC_Player::IsAtPos()
{
	return FVector::Distance(GetActorLocation(), cursor->GetLastClickPosition()) < 1;
}

void AUEC_Player::Move()
{
	if (!IsValid() || !stats.canMove || IsAtPos()) return;
	UE_LOG(LogTemp, Warning, TEXT("tg"));
	SetActorLocation(UKismetMathLibrary::VLerp(GetActorLocation(), cursor->GetLastClickPosition(), GetWorld()->DeltaTimeSeconds * stats.moveSpeed));
}

bool AUEC_Player::IsValid() 
{
	return cursor!=nullptr;
}

// Fill out your copyright notice in the Description page of Project Settings.

#include "UEC_HealPotion.h"
#include "UEC_Cursor.h"

// Sets default values
AUEC_HealPotion::AUEC_HealPotion()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	id = 50;
	name = "Heal Potion";
	description = "Potion that you can use to heal yourself";
}

// Called when the game starts or when spawned
void AUEC_HealPotion::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AUEC_HealPotion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AUEC_HealPotion::IncreaseQuantity()
{
	quantity += 1;
}

void AUEC_HealPotion::DecreaseQuantity()
{
	quantity -=1;
}

void AUEC_HealPotion::Use()
{
	UE_LOG(LogTemp, Warning, TEXT("You used : Healing Potion x1"));
	APlayerController* _controller = GetPlayerController();
	if (!_controller) return;

	IITarget* _target = Cast<IITarget>(_controller->GetPawn());
	if (!_target) return;
	_target->AddLife_Implementation(amountHPRegen);

	AUEC_Cursor* _player = Cast<AUEC_Cursor>(_controller->GetPawn());
	if (!_player) return;
	_player->TriggerDrinkAnimation();
}


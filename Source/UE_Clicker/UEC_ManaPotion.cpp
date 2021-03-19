// Fill out your copyright notice in the Description page of Project Settings.


#include "UEC_ManaPotion.h"
#include "UEC_Cursor.h"

// Sets default values
AUEC_ManaPotion::AUEC_ManaPotion()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	id = 51;
	name = "Mana Potion";
	description = "Potion that you can use to regenerate your mana";
}

// Called when the game starts or when spawned
void AUEC_ManaPotion::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AUEC_ManaPotion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AUEC_ManaPotion::IncreaseQuantity()
{
	quantity += 1;
}

void AUEC_ManaPotion::DecreaseQuantity()
{
	quantity -= 1;
}

void AUEC_ManaPotion::Use()
{
	UE_LOG(LogTemp, Warning, TEXT("You used : Mana Potion x1"));
	APlayerController* _controller = GetPlayerController();
	if (!_controller) return;

	IITarget* _target = Cast<IITarget>(_controller->GetPawn());
	if (!_target) return;
	_target->AddMana_Implementation(amountManaRegen);

	AUEC_Cursor* _player = Cast<AUEC_Cursor>(_controller->GetPawn());
	if (!_player) return;
	_player->TriggerDrinkAnimation();
}


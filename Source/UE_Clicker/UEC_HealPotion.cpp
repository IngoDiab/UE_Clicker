// Fill out your copyright notice in the Description page of Project Settings.

#include "UEC_HealPotion.h"
#include "UEC_Cursor.h"
#include "Components/SphereComponent.h"

// Sets default values
AUEC_HealPotion::AUEC_HealPotion()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	sphereTrigger = CreateDefaultSubobject<USphereComponent>(TEXT("SphereTrigger"));
	sphereTrigger->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	id = 50;
	name = "Heal Potion";
	description = "Potion that you can use to heal yourself";
}

// Called when the game starts or when spawned
void AUEC_HealPotion::BeginPlay()
{
	Super::BeginPlay();
	sphereTrigger->OnComponentBeginOverlap.AddDynamic(this, &AUEC_HealPotion::OnActorBeginOverlapMethod);
}

// Called every frame
void AUEC_HealPotion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move();
}

void AUEC_HealPotion::OnActorBeginOverlapMethod(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AUEC_Cursor* _player = Cast<AUEC_Cursor>(OtherActor);
	if (!_player) return;
	AUEC_HealPotion* _potion = Cast<AUEC_HealPotion>(OverlappedComponent->GetOwner());
	if (!_potion) return;
	UE_LOG(LogTemp, Warning, TEXT("You found : Healing Potion x1"));
	_player->AddInventory(_potion);
	_potion->Destroy(true);
}

void AUEC_HealPotion::Move()
{

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
	IITarget* _player = Cast<IITarget>(_controller->GetPawn());
	_player->AddLife_Implementation(amountHPRegen);
}


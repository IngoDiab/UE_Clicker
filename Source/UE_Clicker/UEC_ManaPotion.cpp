// Fill out your copyright notice in the Description page of Project Settings.


#include "UEC_ManaPotion.h"
#include "UEC_Cursor.h"
#include "Components/SphereComponent.h"

// Sets default values
AUEC_ManaPotion::AUEC_ManaPotion()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	sphereTrigger = CreateDefaultSubobject<USphereComponent>(TEXT("SphereTrigger"));
	sphereTrigger->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	id = 51;
	name = "Mana Potion";
	description = "Potion that you can use to regenerate your mana";
}

// Called when the game starts or when spawned
void AUEC_ManaPotion::BeginPlay()
{
	Super::BeginPlay();
	sphereTrigger->OnComponentBeginOverlap.AddDynamic(this, &AUEC_ManaPotion::OnActorBeginOverlapMethod);
}

// Called every frame
void AUEC_ManaPotion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AUEC_ManaPotion::OnActorBeginOverlapMethod(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AUEC_Cursor* _player = Cast<AUEC_Cursor>(OtherActor);
	if (!_player) return;
	AUEC_ManaPotion* _potion = Cast<AUEC_ManaPotion>(OverlappedComponent->GetOwner());
	if (!_potion) return;
	UE_LOG(LogTemp, Warning, TEXT("You found : Mana Potion x1"));
	_player->AddInventory(_potion);
	_potion->Destroy(true);
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


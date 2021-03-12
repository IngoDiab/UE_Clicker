// Fill out your copyright notice in the Description page of Project Settings.


#include "UE_TriggerInside.h"
#include "UEC_Cursor.h"

AUE_TriggerInside::AUE_TriggerInside()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	OnActorEndOverlap.AddDynamic(this, &AUE_TriggerInside::OnActorEndOverlapMethod);
}

// Called when the game starts or when spawned
void AUE_TriggerInside::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Begin"));
}

// Called every frame
void AUE_TriggerInside::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AUE_TriggerInside::OnActorEndOverlapMethod(AActor* OverlappedActor, AActor* OtherActor)
{
	UE_LOG(LogTemp, Warning, TEXT("Actor Detected"));
	AUEC_Cursor* _player = Cast<AUEC_Cursor>(OtherActor);
	if (!_player) return;
	UE_LOG(LogTemp, Warning, TEXT("Player Detected"));
	_player->ChangeInsideOutside();
}

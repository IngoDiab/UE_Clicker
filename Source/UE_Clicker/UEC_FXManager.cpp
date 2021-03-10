// Fill out your copyright notice in the Description page of Project Settings.


#include "UEC_FXManager.h"

#pragma region UEMethods
// Sets default values
AUEC_FXManager::AUEC_FXManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AUEC_FXManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUEC_FXManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
#pragma endregion

#pragma region CustomMethods
void AUEC_FXManager::SetPosition(FVector _pos)
{
	if (!IsValid()) return;
	fxCursor->SetActorLocation(_pos);
}

void AUEC_FXManager::Hide(bool _hide)
{
	if (!IsValid()) return;
	fxCursor->SetActorHiddenInGame(_hide);
}

bool AUEC_FXManager::IsValid()
{
	return fxCursor != nullptr;
}
#pragma endregion

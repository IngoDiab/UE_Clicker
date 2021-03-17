// Fill out your copyright notice in the Description page of Project Settings.

#include "UEC_ItemAbstract.h"
#include "ClickerGM.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AUEC_ItemAbstract::AUEC_ItemAbstract()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	mesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

}

// Called when the game starts or when spawned
void AUEC_ItemAbstract::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUEC_ItemAbstract::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

APlayerController* AUEC_ItemAbstract::GetPlayerController()
{
	return GetWorld()->GetFirstPlayerController();
}

AUEC_CameraManager* AUEC_ItemAbstract::GetCameraManager()
{
	AClickerGM* _gamemode = GetWorld()->GetAuthGameMode<AClickerGM>();
	if (!_gamemode) return nullptr;
	return _gamemode->GetCameraManager();
}

AUEC_FXManager* AUEC_ItemAbstract::GetFXManager()
{
	AClickerGM* _gamemode = GetWorld()->GetAuthGameMode<AClickerGM>();
	if (!_gamemode) return nullptr;
	return _gamemode->GetFXManager();
}


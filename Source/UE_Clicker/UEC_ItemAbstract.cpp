// Fill out your copyright notice in the Description page of Project Settings.

#include "UEC_ItemAbstract.h"
#include "ClickerGM.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
AUEC_ItemAbstract::AUEC_ItemAbstract()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	mesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	particle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle"));
	particle->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
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
	Move();
	Rotate();
}

void AUEC_ItemAbstract::Move()
{
	FVector _newPos = GetActorLocation() + GetActorUpVector() * cos(GetWorld()->TimeSeconds) / 10.f;
	SetActorLocation(_newPos);
}

void AUEC_ItemAbstract::Rotate()
{
	//float _rotate = (int)GetWorld()->TimeSeconds * 50 %360;
	FRotator _rotator = FRotator(0, GetWorld()->TimeSeconds * 50, 0);
	SetActorRotation(_rotator);
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


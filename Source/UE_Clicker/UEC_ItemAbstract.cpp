// Fill out your copyright notice in the Description page of Project Settings.

#include "UEC_ItemAbstract.h"
#include "ClickerGM.h"
#include "UEC_Cursor.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/SphereComponent.h"

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

	detectionTrigger = CreateDefaultSubobject<USphereComponent>(TEXT("SphereTrigger"));
	detectionTrigger->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	onUpdate.AddLambda([this]()
	{
		if (target) MoveToTarget();
		else Move();
		Rotate();
		if (CanBeAddToInventory()) AddToInventory();
	});
}

// Called when the game starts or when spawned
void AUEC_ItemAbstract::BeginPlay()
{
	Super::BeginPlay();
	detectionTrigger->OnComponentBeginOverlap.AddDynamic(this, &AUEC_ItemAbstract::DetectPlayerOnOverlap);
	detectionTrigger->OnComponentEndOverlap.AddDynamic(this, &AUEC_ItemAbstract::LoosePlayer);
}

// Called every frame
void AUEC_ItemAbstract::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	onUpdate.Broadcast();
}

void AUEC_ItemAbstract::DetectPlayerOnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AUEC_Cursor* _player = Cast<AUEC_Cursor>(OtherActor);
	if (!_player) return;
	target = OtherActor;
}

void AUEC_ItemAbstract::LoosePlayer(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	target = nullptr;
}

void AUEC_ItemAbstract::AddToInventory()
{
	AUEC_Cursor* _player = Cast<AUEC_Cursor>(target);
	if (!_player) return;
	UE_LOG(LogTemp, Warning, TEXT("You found : Healing Potion x1"));
	_player->AddInventory(this);
	Destroy(true);
}

bool AUEC_ItemAbstract::CanBeAddToInventory()
{
	if (!target) return false;
	return FVector::Distance(GetActorLocation(), target->GetActorLocation()) < distanceToAdd;
}

void AUEC_ItemAbstract::Move()
{
	FVector _newPos = GetActorLocation() + GetActorUpVector() * cos(GetWorld()->TimeSeconds) / 10.f;
	SetActorLocation(_newPos);
}

void AUEC_ItemAbstract::Rotate()
{
	FRotator _rotator = FRotator(0, GetWorld()->TimeSeconds * 50, 0);
	SetActorRotation(_rotator);
}

void AUEC_ItemAbstract::MoveToTarget()
{
	SetActorLocation(UKismetMathLibrary::VInterpTo_Constant(GetActorLocation(), target->GetActorLocation(), GetWorld()->DeltaTimeSeconds, speedFollowTarget));
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


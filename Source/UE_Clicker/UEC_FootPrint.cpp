// Fill out your copyright notice in the Description page of Project Settings.


#include "UEC_FootPrint.h"
#include "Components/DecalComponent.h"

// Sets default values
AUEC_FootPrint::AUEC_FootPrint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	decal = CreateDefaultSubobject<UDecalComponent>(TEXT("Decal"));
	decal->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void AUEC_FootPrint::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUEC_FootPrint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


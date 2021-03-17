// Fill out your copyright notice in the Description page of Project Settings.

#include "UEC_ItemAbstract.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AUEC_ItemAbstract::AUEC_ItemAbstract()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	//mesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

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


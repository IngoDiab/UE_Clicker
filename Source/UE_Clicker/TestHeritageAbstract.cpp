// Fill out your copyright notice in the Description page of Project Settings.


#include "TestHeritageAbstract.h"

// Sets default values
ATestHeritageAbstract::ATestHeritageAbstract()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestHeritageAbstract::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestHeritageAbstract::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int ATestHeritageAbstract::Test_Implementation()
{
	return 0;
}

void ATestHeritageAbstract::Toto()
{
}


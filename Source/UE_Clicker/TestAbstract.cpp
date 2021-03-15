// Fill out your copyright notice in the Description page of Project Settings.


#include "TestAbstract.h"

// Sets default values
ATestAbstract::ATestAbstract()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestAbstract::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestAbstract::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

/*int ATestAbstract::Test_Implementation()
{
	return 0;
}*/



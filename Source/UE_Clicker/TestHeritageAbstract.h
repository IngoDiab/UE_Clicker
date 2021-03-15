// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestAbstract.h"
#include "TestHeritageAbstract.generated.h"

UCLASS()
class UE_CLICKER_API ATestHeritageAbstract : public ATestAbstract
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestHeritageAbstract();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual int Test_Implementation() override;
	virtual void Toto() override;
};

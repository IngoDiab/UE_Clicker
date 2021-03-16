// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "UEC_AIController.generated.h"

/**
 * 
 */
UCLASS()
class UE_CLICKER_API AUEC_AIController : public AAIController
{
	GENERATED_BODY()
	
public:
	// Sets default values for this pawn's properties
	AUEC_AIController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};

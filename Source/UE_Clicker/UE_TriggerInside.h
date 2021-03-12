// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "UE_TriggerInside.generated.h"

/**
 * 
 */
UCLASS()
class UE_CLICKER_API AUE_TriggerInside : public ATriggerBox
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AUE_TriggerInside();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION()
	void OnActorEndOverlapMethod(AActor* OverlappedActor, AActor* OtherActor);
};

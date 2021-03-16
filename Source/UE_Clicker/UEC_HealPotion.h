// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UEC_ItemAbstract.h"
#include "UEC_HealPotion.generated.h"

UCLASS()
class UE_CLICKER_API AUEC_HealPotion : public AUEC_ItemAbstract
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUEC_HealPotion();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

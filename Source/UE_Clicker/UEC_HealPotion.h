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

	UPROPERTY(EditAnywhere)
		int amountHPRegen = 10;

	UPROPERTY(EditAnywhere)
		class USphereComponent* sphereTrigger = nullptr;
	
public:	
	// Sets default values for this actor's properties
	AUEC_HealPotion();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION()
		void OnActorBeginOverlapMethod(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:
	virtual void Move();

	virtual void IncreaseQuantity() override;

	virtual void DecreaseQuantity() override;

	virtual void Use() override;

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UEC_ItemAbstract.generated.h"

UCLASS(ABSTRACT)
class UE_CLICKER_API AUEC_ItemAbstract : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		int id;

	UPROPERTY(EditAnywhere)
		FString name;

	UPROPERTY(EditAnywhere)
		FString description;

	UPROPERTY(EditAnywhere)
		int quantity;
	
public:	
	// Sets default values for this actor's properties
	AUEC_ItemAbstract();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public: 
	FORCEINLINE int GetID() { return id; };
	FORCEINLINE bool IsUnique() { return quantity == 1; };
	virtual void IncreaseQuantity() PURE_VIRTUAL(AUEC_ItemAbstract::IncreaseQuantity, );
	virtual void DecreaseQuantity() PURE_VIRTUAL(AUEC_ItemAbstract::DecreaseQuantity, );
	virtual void Use() PURE_VIRTUAL(AUEC_ItemAbstract::Use, );
};

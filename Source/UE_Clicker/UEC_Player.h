// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UEC_Cursor.h"
#include "UEC_Player.generated.h"

USTRUCT()
struct UE_CLICKER_API FPlayerStats 
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		float moveSpeed = 0;

	UPROPERTY(EditAnywhere)
		bool canMove = true;
};

UCLASS()
class UE_CLICKER_API AUEC_Player : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		FPlayerStats stats;

	UPROPERTY()
		AUEC_Cursor* cursor;
	
public:	
	// Sets default values for this actor's properties
	AUEC_Player();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public :
	bool IsAtPos();
	void Move();

public :
	bool IsValid();

};

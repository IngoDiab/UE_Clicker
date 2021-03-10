// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UEC_Player.generated.h"

UCLASS()
class UE_CLICKER_API AUEC_Player : public AActor
{
	GENERATED_BODY()


	
	UPROPERTY(VisibleAnywhere)
		FVector targetPosition;

	/*UPROPERTY()
		AUEC_Cursor* cursor;*/
	
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
	void SetTargetPosition(FVector _position);
	bool IsAtPos();
	void Move();

public :
	bool IsValid();

};

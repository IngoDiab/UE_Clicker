// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "UEC_Cursor.generated.h"

UCLASS()
class UE_CLICKER_API AUEC_Cursor : public APawn
{
	GENERATED_BODY()

		UPROPERTY(VisibleAnywhere)
		FVector lastClickPosition = FVector::ZeroVector;

public:
	// Sets default values for this pawn's properties
	AUEC_Cursor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	void ShowCursor(bool);
	void Click();

public :
	FVector GetLastClickPosition();
};

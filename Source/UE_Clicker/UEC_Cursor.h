// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "UEC_Player.h"
#include "UEC_Cursor.generated.h"

USTRUCT()
struct UE_CLICKER_API FPlayerStats
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		float moveSpeed = 1;

	UPROPERTY(EditAnywhere)
		bool canMove = true;

	UPROPERTY(EditAnywhere)
		float rotateSpeed = 1;

	UPROPERTY(EditAnywhere)
		bool canRotate = true;
};

UCLASS()
class UE_CLICKER_API AUEC_Cursor : public APawn
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		int id = 0;
	
	UPROPERTY(EditAnywhere)
		FPlayerStats stats;

	UPROPERTY(VisibleAnywhere)
		FVector lastClickPosition = FVector::ZeroVector;

	UPROPERTY(EditAnywhere)
		TArray<TEnumAsByte<EObjectTypeQuery>> allObjectsHitable;

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
	APlayerController* GetPlayerController();
	class AUEC_CameraManager* GetCameraManager();
	class AUEC_FXManager* GetFXManager();

	void InitPlayer();
	void CreatePlayerCamera();
	void EnablePlayerCamera();
	void Click();
	bool IsAtPos();
	void Move();

	void Rotate();

public :
	FVector GetLastClickPosition();
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "UEC_Camera.h"
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

	UPROPERTY(EditAnywhere, Category = "Player Feedback")
		int id = 0;
	
	UPROPERTY(VisibleAnywhere, Category = "Player Feedback")
		bool isInside = true;

	UPROPERTY(EditAnywhere, Category = "Player Stats")
		FPlayerStats stats;
	
	UPROPERTY(EditAnywhere, Category = "Own Camera Settings | Inside")
		FCameraSettings ownCameraSettingsInside;
	
	UPROPERTY(EditAnywhere, Category = "Own Camera Settings | Outside")
		FCameraSettings ownCameraSettingsOutside;
	
	UPROPERTY(VisibleAnywhere, Category = "SkeletalMesh")
		class USkeletalMeshComponent* skeletalMesh = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Animator")
		class UPlayerAnimInstance* animator = nullptr;
	
	UPROPERTY(VisibleAnywhere, Category = "Collider")
		class UCapsuleComponent* capsuleCollider = nullptr;

	UPROPERTY()
		FVector lastClickPosition = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, Category = "RayCast Parameters")
		TArray<TEnumAsByte<EObjectTypeQuery>> allObjectsHitable;


	DECLARE_EVENT(AUEC_Cursor, PlayerUpdate)
	PlayerUpdate onPlayerUpdate;

	DECLARE_EVENT(AUEC_Cursor, PlayerAtPos)
	PlayerAtPos onPlayerAtPos;

	DECLARE_EVENT(AUEC_Cursor, PlayerMoving)
	PlayerMoving onPlayerMoving;

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
	void InitMecanim();
	void CreatePlayerCamera();
	void EnablePlayerCamera();
	void Click();
	void SpawnFXOnClick();
	void ShowFXDestination(bool);
	bool IsAtPos();
	void Move();
	void IDLEtoRUN(bool);

	void Rotate();

public :
	void ChangeInsideOutside();
	void ModifyPlayerCamOffset();
	FVector GetLastClickPosition();
};

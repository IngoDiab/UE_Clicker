// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "UEC_Camera.h"
#include "ITarget.h"
#include "UEC_Cursor.generated.h"

USTRUCT()
struct UE_CLICKER_API FPlayerSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		float moveSpeed = 1;

	UPROPERTY(EditAnywhere)
		bool canMove = true;

	UPROPERTY(EditAnywhere)
		float distanceIsAtPos = 10;

	UPROPERTY(EditAnywhere)
		float rotateSpeed = 1;

	UPROPERTY(EditAnywhere)
		bool canRotate = true;
};

USTRUCT()
struct UE_CLICKER_API FPlayerStats
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		int life = 100;

	UPROPERTY(EditAnywhere)
		bool canHeal = true;

	UPROPERTY(EditAnywhere)
		int mana = 100;

	UPROPERTY(EditAnywhere)
		bool canMana = true;

	UPROPERTY(EditAnywhere)
		bool isDead = false;
};

UCLASS()
class UE_CLICKER_API AUEC_Cursor : public APawn, public IITarget
{
	GENERATED_BODY()

#pragma region Player
	UPROPERTY(EditAnywhere, Category = "Player | Feedback")
		int id = 0;
	
	UPROPERTY(EditAnywhere, Category = "Player | Feedback")
		bool isInside = true;

	UPROPERTY(EditAnywhere, Category = "Player | Stats")
		FPlayerStats stats;

	UPROPERTY(EditAnywhere, Category = "Player | Settings")
		FPlayerSettings settings;

	UPROPERTY(EditAnywhere, Category = "Player | Inventory")
		class UInventory* inventory = nullptr;
#pragma endregion
	
#pragma region CamPreset
	UPROPERTY(EditAnywhere, Category = "Own Camera Settings | Inside")
		FCameraSettings ownCameraSettingsInside;
	
	UPROPERTY(EditAnywhere, Category = "Own Camera Settings | Outside")
		FCameraSettings ownCameraSettingsOutside;
#pragma endregion

#pragma region Component
	UPROPERTY(VisibleAnywhere, Category = "PlayerComponent | Movement")
		class UFloatingPawnMovement* movement = nullptr;
	
	UPROPERTY(VisibleAnywhere, Category = "PlayerComponent | SkeletalMesh")
		class USkeletalMeshComponent* skeletalMesh = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "PlayerComponent | Animator")
		class UPlayerAnimInstance* animator = nullptr;
	
	UPROPERTY(VisibleAnywhere, Category = "PlayerComponent | Collider")
		class UCapsuleComponent* capsuleCollider = nullptr;
#pragma endregion

	UPROPERTY(EditAnywhere, Category = "RayCast Parameters")
		TArray<TEnumAsByte<EObjectTypeQuery>> allObjectsHitable;


	UPROPERTY()
		FVector lastClickPosition = FVector::ZeroVector;

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

	void IDLEtoRUN();
	void TriggerDrinkAnimation();

	void AddInventory(class AUEC_ItemAbstract*);
	void UseHealPotion();
	void UseManaPotion();

	void Rotate();

public :
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void AddLife(int _life);
	virtual void AddLife_Implementation(int _life);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void AddMana(int _mana);
	virtual void AddMana_Implementation(int _mana);

public :
	void RightFootLocation();
	void LeftFootLocation();

	void RightKneeLocation();
	void LeftKneeLocation();

public :
	void ChangeInsideOutside();
	void ModifyPlayerCamOffset();
	FVector GetLastClickPosition();
};

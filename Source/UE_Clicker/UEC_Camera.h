// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/CameraComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "DrawDebugHelpers.h"
#include "UEC_CameraSettings.h"
#include "UEC_Camera.generated.h"

USTRUCT()
struct UE_CLICKER_API FCameraSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Target")
		AActor* target = nullptr;

	UPROPERTY(EditAnywhere, Category = "Movement|Position")
		FVector offsetPos = FVector::ZeroVector;
	UPROPERTY(EditAnywhere, Category = "Movement|Speed")
		float speedMove = 10;
	UPROPERTY(EditAnywhere, Category = "Movement")
		bool canMove = true;

	UPROPERTY(EditAnywhere, Category = "Focus|Position")
		FVector offsetLookAt = FVector::ZeroVector;
	UPROPERTY(EditAnywhere, Category = "Focus|Speed")
		float speedLookAt = 10;
	UPROPERTY(EditAnywhere, Category = "LookAt")
		bool canLookAt = true;
};

UCLASS()
class UE_CLICKER_API AUEC_Camera : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		int id = 0;
	
	UPROPERTY(EditAnywhere, Category = "Settings")
		FCameraSettings cameraSettings;

	UPROPERTY(VisibleAnywhere, Category = "Camera")
		UCameraComponent* cameraComp = nullptr;

	UPROPERTY(EditAnywhere, Category = "Debug")
		bool canDraw = false;

	DECLARE_EVENT(AUEC_Camera, CameraUpdate)
		CameraUpdate onCameraUpdate;
	
public:	
	// Sets default values for this actor's properties
	AUEC_Camera();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public :
	class AUEC_CameraManager* GetCameraManager();

	//Initialisation of the camera
	void InitCamera();
	void InitCameraSettings(int _id, FCameraSettings& _settings);
	void InitCameraComponent();

	void AddToManager();

	bool IsAtPos();
	void MoveTo();

	void LookAt();

public:
	FVector GetFinalPositionCamera();
	FVector GetFinalLookAtCamera();

public :
	bool IsValid();

	int GetID();
	FCameraSettings GetCameraSettings();
	void SetCameraSettings(FCameraSettings);
	UCameraComponent* GetCameraComponent();
	FORCEINLINE CameraUpdate OnCameraUpdate() { return onCameraUpdate; };

public :
	void DrawDebug();
};

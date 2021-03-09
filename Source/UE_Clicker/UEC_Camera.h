// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/CameraComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "DrawDebugHelpers.h"
#include "UEC_CameraSettings.h"
#include "UEC_Camera.generated.h"

UCLASS()
class UE_CLICKER_API AUEC_Camera : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		int id = 0;
	
	UPROPERTY(VisibleAnywhere, Category = "Settings")
		UUEC_CameraSettings* cameraSettings = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Camera")
		UCameraComponent* cameraComp = nullptr;
	
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
	//Initialisation of the camera
	void InitCamera();
	void InitCameraSettings();
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
	UUEC_CameraSettings* GetCameraSettings();
	UCameraComponent* GetCameraComponent();

public :
	void DrawDebug();
};

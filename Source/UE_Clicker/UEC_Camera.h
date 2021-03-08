// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UEC_CameraSettings.h"
#include "UEC_Camera.generated.h"

UCLASS()
class UE_CLICKER_API AUEC_Camera : public AActor
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere)
		UUEC_CameraSettings* cameraSettings = nullptr;
	
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
	void InitCamera();
	void TestCamera();
	void MoveTo();

};

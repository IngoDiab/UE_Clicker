// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UEC_Camera.h"
#include "UEC_CameraManager.generated.h"

UCLASS()
class UE_CLICKER_API AUEC_CameraManager : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "All Cameras")
	TMap<int, AUEC_Camera*> allCameras;

	DECLARE_EVENT(AUEC_CameraManager, UpdateCameras)
	UpdateCameras onUpdateCameras;

public:	
	// Sets default values for this actor's properties
	AUEC_CameraManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	void Add(AUEC_Camera*);

	AUEC_Camera* Get(int);

	void Remove(int);
	void Remove(AUEC_Camera*);

	bool Exists(int);
	bool Exists(AUEC_Camera*);

	void Enable(int);

	void Disable(int);
	void DisableAll();
};

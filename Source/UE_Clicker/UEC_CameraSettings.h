// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UEC_CameraSettings.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UE_CLICKER_API UUEC_CameraSettings : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Target")
		AActor* target = nullptr;

	UPROPERTY(EditAnywhere, Category = "Movement|Position")
		FVector offsetPos = FVector::ZeroVector;
	UPROPERTY(EditAnywhere, Category = "Movement|Speed")
		float speedMove = 0;
	UPROPERTY(EditAnywhere, Category = "Movement")
		bool canMove = true;

	UPROPERTY(EditAnywhere, Category = "Focus|Position")
		FVector offsetLookAt = FVector::ZeroVector;
	UPROPERTY(EditAnywhere, Category = "Focus|Speed")
		float speedLookAt = 0;
	UPROPERTY(EditAnywhere, Category = "LookAt")
		bool canLookAt = true;


public:	
	// Sets default values for this component's properties
	UUEC_CameraSettings();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	bool IsValid();

	AActor* GetTarget();

	FVector GetOffsetPosition();
	float GetSpeedMove();
	bool CanMove();

	FVector GetOffsetLookAt();
	float GetSpeedRotate();
	bool CanLookAt();

	void SetTarget(AActor*);

	void SetOffsetPosition(FVector);
	void SetSpeedMove(float);
	void SetCanMove(bool);

	void SetOffsetLookAt(FVector);
	void SetSpeedRotate(float);
	void SetCanLookAt(bool);
};

// Fill out your copyright notice in the Description page of Project Settings.


#include "UEC_CameraSettings.h"

#pragma region UEMethods
// Sets default values for this component's properties
UUEC_CameraSettings::UUEC_CameraSettings()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UUEC_CameraSettings::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UUEC_CameraSettings::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
#pragma endregion

#pragma region CustomMethods
bool UUEC_CameraSettings::IsValid()
{
	return target != nullptr;
}

AActor* UUEC_CameraSettings::GetTarget()
{
	return target;
}

FVector UUEC_CameraSettings::GetOffsetPosition()
{
	return offsetPos;
}

float UUEC_CameraSettings::GetSpeedMove()
{
	return speedMove;
}

bool UUEC_CameraSettings::CanMove()
{
	return canMove;
}

FVector UUEC_CameraSettings::GetOffsetLookAt()
{
	return offsetLookAt;
}

float UUEC_CameraSettings::GetSpeedRotate()
{
	return LookAtMove;
}

bool UUEC_CameraSettings::CanLookAt()
{
	return canLookAt;
}
#pragma endregion

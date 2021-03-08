// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UEC_CameraManager.h"
#include "ClickerGM.generated.h"

/**
 * 
 */
UCLASS()
class UE_CLICKER_API AClickerGM : public AGameModeBase
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere)
		TSoftObjectPtr<AUEC_CameraManager> cameraManager = nullptr;

public:
	FORCEINLINE AUEC_CameraManager* GetCameraManager() { return cameraManager.Get(); };
		
};

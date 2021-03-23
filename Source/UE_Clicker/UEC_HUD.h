// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UEC_HUD.generated.h"

/**
 * 
 */
UCLASS()
class UE_CLICKER_API AUEC_HUD : public AHUD
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		TSubclassOf<class UUEC_UI> classUI = nullptr;

	UPROPERTY(EditAnywhere)
		UUEC_UI* widget = nullptr;
	
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void InitHUD();
};

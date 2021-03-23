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

	UPROPERTY(EditAnywhere)
		bool isLoaded = false;
	
public:
	virtual void PostInitProperties() override;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void InitHUD();
	void UpdateCharacterHUD(int _life, int _mana);
	void UpdateInventoryHUD(int _nbPotionLife, int _nbPotionMana);

public:
	FORCEINLINE bool IsLoaded() { return isLoaded; };
};

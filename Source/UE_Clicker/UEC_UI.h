// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "UEC_UI.generated.h"

/**
 * 
 */
UCLASS()
class UE_CLICKER_API UUEC_UI : public UUserWidget
{
	GENERATED_BODY()
	
public:
		UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
			UProgressBar* lifeBar = nullptr;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
			UProgressBar* manaBar = nullptr;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
			UTextBlock* life = nullptr;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
			UTextBlock* mana = nullptr;

public:
	void UpdateLife(int _life);
	void UpdateMana(float _mana);
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ITarget.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UITarget : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class UE_CLICKER_API IITarget
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void AddLife(int _life);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void AddMana(int _mana);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void LooseLife(int _life);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void LooseMana(int _mana);
};

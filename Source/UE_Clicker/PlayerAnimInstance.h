// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PlayerAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class UE_CLICKER_API UPlayerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

protected:
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool inputRun = false;
	
public :
	FORCEINLINE bool GetInputRun() { return inputRun; };
	FORCEINLINE void SetInputRun(bool _inputRun) { inputRun = _inputRun; };
};

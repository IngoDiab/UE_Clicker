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
		float velocity = 0;
	
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isDrinking = false;
public :
	FORCEINLINE float GetVelocity() { return velocity; };
	FORCEINLINE void SetVelocity(float _velocity) { velocity = _velocity; };

	FORCEINLINE bool GetIsDrinking() { return isDrinking; };
	FORCEINLINE void SetIsDrinking(bool _isDrinking) { isDrinking = _isDrinking; };
};

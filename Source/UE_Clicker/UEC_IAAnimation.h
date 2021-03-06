// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "UEC_IAAnimation.generated.h"

/**
 * 
 */
UCLASS()
class UE_CLICKER_API UUEC_IAAnimation : public UAnimInstance
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float velocity = 0;
public:
	FORCEINLINE float GetVelocity() { return velocity; };
	FORCEINLINE void SetVelocity(float _velocity) { velocity = _velocity; };
};

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

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
			FVector leftFootPos;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
			FVector rightFootPos;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
			FVector leftKneePos;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
			FVector rightKneePos;
public :
	FORCEINLINE float GetVelocity() { return velocity; };
	FORCEINLINE void SetVelocity(float _velocity) { velocity = _velocity; };

	FORCEINLINE bool GetIsDrinking() { return isDrinking; };
	FORCEINLINE void SetIsDrinking(bool _isDrinking) { isDrinking = _isDrinking; };

	FORCEINLINE FVector GetLeftFootPos() { return leftFootPos; };
	FORCEINLINE void SetLeftFootPos(FVector _leftFootPos) { leftFootPos = _leftFootPos; };
	
	FORCEINLINE FVector GetRightFootPos() { return rightFootPos; };
	FORCEINLINE void SetRightFootPos(FVector _rightFootPos) { rightFootPos = _rightFootPos; };
	
	FORCEINLINE FVector GetLeftKneePos() { return leftKneePos; };
	FORCEINLINE void SetLeftKneePos(FVector _leftKneePos) { leftKneePos = _leftKneePos; };
	
	FORCEINLINE FVector GetRightKneePos() { return rightKneePos; };
	FORCEINLINE void SetRightKneePos(FVector _rightKneePos) { rightKneePos = _rightKneePos; };
};

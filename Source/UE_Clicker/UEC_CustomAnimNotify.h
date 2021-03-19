// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "UEC_CustomAnimNotify.generated.h"

/**
 * 
 */
UCLASS()
class UE_CLICKER_API UUEC_CustomAnimNotify : public UAnimNotify
{
	GENERATED_BODY()
	
public:
	virtual void Notify(USkeletalMeshComponent* _mesh, UAnimSequenceBase* _animation) override;
};

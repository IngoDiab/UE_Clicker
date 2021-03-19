// Fill out your copyright notice in the Description page of Project Settings.


#include "UEC_CustomAnimNotify.h"

void UUEC_CustomAnimNotify::Notify(USkeletalMeshComponent* _mesh, UAnimSequenceBase* _animation)
{
	Super::Notify(_mesh, _animation);
	UE_LOG(LogTemp, Warning, TEXT("AAA"));
}
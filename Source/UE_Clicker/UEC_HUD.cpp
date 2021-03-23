// Fill out your copyright notice in the Description page of Project Settings.


#include "UEC_HUD.h"
#include "UEC_UI.h"

void AUEC_HUD::BeginPlay()
{
	Super::BeginPlay();
	InitHUD();
}

void AUEC_HUD::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AUEC_HUD::InitHUD()
{
	widget = CreateWidget<UUEC_UI>(GetWorld(), classUI);
	if (!widget) return;
	widget->AddToViewport();
	widget->UpdateLife(54);
	widget->UpdateMana(37);
}

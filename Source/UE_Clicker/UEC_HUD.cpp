// Fill out your copyright notice in the Description page of Project Settings.


#include "UEC_HUD.h"
#include "UEC_UI.h"

void AUEC_HUD::PostInitProperties()
{
	Super::PostInitProperties();
}

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
	isLoaded = true;
	/*widget->UpdateLife(100);
	widget->UpdateMana(100);
	widget->UpdateNumberLifePotion(3);
	widget->UpdateNumberManaPotion(10);*/
}

void AUEC_HUD::UpdateCharacterHUD(int _life, int _mana)
{
	if (!widget) return;
	widget->UpdateLife(_life);
	widget->UpdateMana(_mana);
}

void AUEC_HUD::UpdateInventoryHUD(int _nbPotionLife, int _nbPotionMana)
{
	if (!widget) return;
	widget->UpdateNumberLifePotion(_nbPotionLife);
	widget->UpdateNumberManaPotion(_nbPotionMana);
}

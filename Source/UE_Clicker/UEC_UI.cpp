// Fill out your copyright notice in the Description page of Project Settings.


#include "UEC_UI.h"

void UUEC_UI::UpdateLife(int _life)
{
	if (lifeBar) 
	{
		lifeBar->SetPercent((float)_life/100.f);
	}
	if (life)
	{
		life->SetText(FText::FromString(FString::FromInt(_life).AppendChar(TCHAR('%'))));
	}
}

void UUEC_UI::UpdateMana(int _mana)
{
	if (manaBar)
	{
		manaBar->SetPercent((float)_mana / 100.f);
	}
	if (mana)
	{
		mana->SetText(FText::FromString(FString::FromInt(_mana).AppendChar(TCHAR('%'))));
	}
}

void UUEC_UI::UpdateNumberLifePotion(int _number)
{
	if (!numLifePotion) return;
	numLifePotion->SetText(FText::FromString(FString::FromInt(_number)));
}

void UUEC_UI::UpdateNumberManaPotion(int _number)
{
	if (!numManaPotion) return;
	numManaPotion->SetText(FText::FromString(FString::FromInt(_number)));
}

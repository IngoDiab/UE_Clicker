// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory.h"
#include "UEC_ItemAbstract.h"

// Sets default values for this component's properties
UInventory::UInventory()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInventory::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInventory::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UInventory::ShowInventory()
{
	UE_LOG(LogTemp, Warning, TEXT("Your Inventory :"));
	for (TPair<int, AUEC_ItemAbstract*> _item : allItems)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s x%i"), *_item.Value->GetName(), _item.Value->GetQuantity());
	}
}

void UInventory::UseItem(int _id)
{
	AUEC_ItemAbstract* _item = Get(_id);
	if (!_item) return;
	_item->Use();
	Remove(_id);
}

void UInventory::Add(AUEC_ItemAbstract* _item)
{
	if (!Exists(_item)) 
	{
		AUEC_ItemAbstract* _potion = NewObject<AUEC_ItemAbstract>(this, _item->GetClass());
		allItems.Add(_item->GetID(), _potion);
	}
	else 
	{
		AUEC_ItemAbstract* _itemInInventory = Get(_item->GetID());
		_itemInInventory->IncreaseQuantity();
	}
	ShowInventory();
}

AUEC_ItemAbstract* UInventory::Get(int _id)
{
	if (IsEmpty() || !Exists(_id)) return nullptr;
	return allItems[_id];
}

void UInventory::Remove(int _id)
{
	if (IsEmpty() || !Exists(_id)) return;
	AUEC_ItemAbstract* _item = Get(_id);
	if (_item->IsUnique()) allItems.Remove(_id);
	else _item->DecreaseQuantity();
}

void UInventory::Remove(AUEC_ItemAbstract* _item)
{
	if (IsEmpty() || !Exists(_item)) return;
	if (!_item->IsUnique()) _item->DecreaseQuantity();
	else allItems.Remove(_item->GetID());
}

bool UInventory::Exists(int _id)
{
	return allItems.Contains(_id);
}

bool UInventory::Exists(AUEC_ItemAbstract* _item)
{
	return allItems.Contains(_item->GetID());
}

bool UInventory::IsFull()
{
	return allItems.Num() >= maxSlots;
}

bool UInventory::IsEmpty()
{
	return allItems.Num() <= 0;
}


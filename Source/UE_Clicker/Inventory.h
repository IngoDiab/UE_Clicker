// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Inventory.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UE_CLICKER_API UInventory : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, meta = (AllowAbstract = true))
		TMap<int, class AUEC_ItemAbstract*> allItems;

	UPROPERTY(EditAnywhere)
		int maxSlots = 5;

	DECLARE_EVENT(UInventory, ItemAdded)
	ItemAdded onItemAdded;

	DECLARE_EVENT(UInventory, DelayedInit)
	DelayedInit onDelayedInit;

	DECLARE_EVENT(UInventory, InventoryUpdated)
	InventoryUpdated onInventoryUpdated;

public:	
	// Sets default values for this component's properties
	UInventory();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public :

	APlayerController* GetPlayerController();
	class AUEC_HUD* GetHUD();

	void InitInventory();

	UFUNCTION()
	void DelayedInit();

	void ShowInventory();
	void UpdateInventory();
	void UseItem(int _id);

	void Add(AUEC_ItemAbstract*);

	AUEC_ItemAbstract* Get(int);

	void Remove(int);
	void Remove(AUEC_ItemAbstract*);

	bool Exists(int);
	bool Exists(AUEC_ItemAbstract*);

	bool IsFull();
	bool IsEmpty();
};

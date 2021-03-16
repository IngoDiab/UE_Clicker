// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Inventory.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UE_CLICKER_API UInventory : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, meta = (AllowAbstract = true))
		TMap<int, class AUEC_ItemAbstract> allItems;

	UPROPERTY(EditAnywhere)
		int maxSlots = 5;
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
	void Add(AUEC_ItemAbstract);

	AUEC_ItemAbstract Get(int);

	void Remove(int);
	void Remove(AUEC_ItemAbstract);

	bool Exists(int);
	bool Exists(AUEC_ItemAbstract);

	bool IsFull();
	bool IsEmpty();
};

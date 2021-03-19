// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UEC_ItemAbstract.generated.h"

UCLASS(ABSTRACT)
class UE_CLICKER_API AUEC_ItemAbstract : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category = "Settings")
		AActor* target = nullptr;

	UPROPERTY(EditAnywhere, Category = "Settings")
		float distanceToAdd = 100;
	
	UPROPERTY(EditAnywhere, Category = "Settings")
		float speedFollowTarget = 100;

	UPROPERTY(EditAnywhere, Category = "Features")
		int id = -1;

	UPROPERTY(EditAnywhere, Category = "Features")
		FString name = "";

	UPROPERTY(EditAnywhere, Category = "Features")
		FString description = "";

	UPROPERTY(EditAnywhere, Category = "Features")
		int quantity = 1;

	UPROPERTY(EditAnywhere, Category = "Component")
		class UStaticMeshComponent* mesh = nullptr;

	UPROPERTY(EditAnywhere, Category = "Component")
		class UParticleSystemComponent* particle = nullptr;

	UPROPERTY(EditAnywhere, Category = "Component")
		class USphereComponent* detectionTrigger = nullptr;

	DECLARE_EVENT(UInventory, ItemUpdate)
	ItemUpdate onUpdate;
	
public:	
	// Sets default values for this actor's properties
	AUEC_ItemAbstract();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION()
	void DetectPlayerOnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void LoosePlayer(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	void AddToInventory();

public: 
	FORCEINLINE int GetID() { return id; };
	FORCEINLINE FString GetName() { return name; };
	FORCEINLINE int GetQuantity() { return quantity; };
	FORCEINLINE bool IsUnique() { return quantity == 1; };

	APlayerController* GetPlayerController();
	class AUEC_CameraManager* GetCameraManager();
	class AUEC_FXManager* GetFXManager();

	virtual bool CanBeAddToInventory();
	virtual void Move();
	virtual void Rotate();
	virtual void MoveToTarget();
	virtual void IncreaseQuantity() PURE_VIRTUAL(AUEC_ItemAbstract::IncreaseQuantity, );
	virtual void DecreaseQuantity() PURE_VIRTUAL(AUEC_ItemAbstract::DecreaseQuantity, );
	virtual void Use() PURE_VIRTUAL(AUEC_ItemAbstract::Use, );
};

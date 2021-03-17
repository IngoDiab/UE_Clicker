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
	UPROPERTY(EditAnywhere)
		int id;

	UPROPERTY(EditAnywhere)
		FString name;

	UPROPERTY(EditAnywhere)
		FString description;

	UPROPERTY(EditAnywhere)
		int quantity = 1;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* mesh = nullptr;
	
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
	FORCEINLINE int GetID() { return id; };
	FORCEINLINE FString GetName() { return name; };
	FORCEINLINE int GetQuantity() { return quantity; };
	FORCEINLINE bool IsUnique() { return quantity == 1; };

	APlayerController* GetPlayerController();
	class AUEC_CameraManager* GetCameraManager();
	class AUEC_FXManager* GetFXManager();

	virtual void IncreaseQuantity() PURE_VIRTUAL(AUEC_ItemAbstract::IncreaseQuantity, );
	virtual void DecreaseQuantity() PURE_VIRTUAL(AUEC_ItemAbstract::DecreaseQuantity, );
	virtual void Use() PURE_VIRTUAL(AUEC_ItemAbstract::Use, );
};

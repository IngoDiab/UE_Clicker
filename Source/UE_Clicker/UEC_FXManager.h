// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UEC_FXManager.generated.h"

UCLASS()
class UE_CLICKER_API AUEC_FXManager : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "CursorFX")
		AActor* fxCursor = nullptr;

	
public:	
	// Sets default values for this actor's properties
	AUEC_FXManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public :
	void SetPosition(FVector _pos);
	void Hide(bool _hide);

public:
	bool IsValid();

};

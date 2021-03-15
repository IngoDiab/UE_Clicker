// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestInterface.h"
#include "TestAbstract.generated.h"

UCLASS(ABSTRACT)
class UE_CLICKER_API ATestAbstract : public AActor, public ITestInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestAbstract();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Test") 
		int Test();
	virtual int Test_Implementation() PURE_VIRTUAL(ATestAbstract::Toto, return 0;);

	virtual void Toto() PURE_VIRTUAL(ATestAbstract::Toto, );

};

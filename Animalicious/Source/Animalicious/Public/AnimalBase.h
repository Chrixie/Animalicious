// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AnimalDataAsset.h"
#include "AnimalBase.generated.h"

UCLASS()
class ANIMALICIOUS_API AAnimalBase : public ACharacter
{
	GENERATED_BODY()


public:
	// Sets default values for this character's properties
	AAnimalBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DATA")
	//TObjectPtr<UAnimalDataAsset> AnimalDA;
	UAnimalDataAsset* AnimalDA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CurrentHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CurrentHunger;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CurrentThirst;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


private:

	//Setting up all stat values from Data Asset
	void SetupStats();

	void DecreseHunger(float DeltaTime);
	void DecreseThirst(float DeltaTime);

};

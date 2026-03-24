// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AnimalDataAsset.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include <Components/TextRenderComponent.h>
#include <Perception/AIPerceptionStimuliSourceComponent.h>
#include "AnimalBase.generated.h"

UCLASS()
class ANIMALICIOUS_API AAnimalBase : public ACharacter
{
	GENERATED_BODY()


public:
	// Sets default values for this character's properties
	AAnimalBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DATA")
	TObjectPtr<UAnimalDataAsset> AnimalDA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CurrentHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CurrentHunger;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CurrentThirst;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UTextRenderComponent> StatusText;


	UPROPERTY(BlueprintReadOnly, Category = "Perception Listener")
	TObjectPtr<UAIPerceptionStimuliSourceComponent> AIPerceptionSource;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void SetDebugStatusText(FText StatusDebugText);


private:

	//Setting up all stat values from Data Asset
	void SetupStats();

	void DecreseHunger(float DeltaTime);
	void DecreseThirst(float DeltaTime);

	void StatusTextInit();
};

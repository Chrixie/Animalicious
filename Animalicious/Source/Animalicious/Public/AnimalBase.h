// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AnimalDataAsset.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/TextRenderComponent.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "AnimalBase.generated.h"

UCLASS()
class ANIMALICIOUS_API AAnimalBase : public ACharacter
{
	GENERATED_BODY()


public:
	AAnimalBase();

	virtual void Tick(float DeltaTime) override;

	FORCEINLINE UAnimalDataAsset* GetAnimalDA() const { return AnimalDA; }

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void SetDebugStatusText(FText StatusDebugText);

	//------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DATA")
	UAnimalDataAsset* AnimalDA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CurrentHealth;	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Damage;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsDead;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CurrentHunger;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CurrentThirst;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsPredator;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTagContainer ThreatTags;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTagContainer PreyTags;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag GameplayTag;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UTextRenderComponent> StatusText;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Perception Listener")
	TObjectPtr<UAIPerceptionStimuliSourceComponent> AIPerceptionSource;


protected:
	virtual void PostInitializeComponents() override;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



private:

	//Setting up all stat values from Data Asset
	void SetupStats();

	void DecreaseHunger(float DeltaTime);
	void DecreaseThirst(float DeltaTime);

	void StatusTextInit();


};

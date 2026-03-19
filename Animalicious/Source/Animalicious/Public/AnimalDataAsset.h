// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AnimalDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class ANIMALICIOUS_API UAnimalDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Survival Stats")
	float MaxHealth = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Survival Stats")
	float MaxHunger = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Survival Stats")
	float MaxThirst = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Survival Stats")
	float DecayValue = 1.0f;

	//-----------------------------------------------------------------------------------------//

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement Stats")
	float WalkSpeed = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement Stats")
	float SprintSpeed = 200.0f;

	//-----------------------------------------------------------------------------------------//

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI Stimuli")
	float SightDistance = 300.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI Stimuli")
	float HearingDistance = 1000.0f;
};

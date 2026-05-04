// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "AnimalDataAsset.generated.h"

USTRUCT(BlueprintType)
struct FGamePlayTagOrThreats
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	FGameplayTagContainer ThreatTags;	
	
	UPROPERTY(EditAnywhere)
	FGameplayTagContainer PreyTags;
	
	UPROPERTY(EditAnywhere)
	FGameplayTag GameplayTag;
};

USTRUCT(BlueprintType)
struct FCombatStats
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	float MaxHealth = 100.0f;

	UPROPERTY(EditAnywhere)
	float Damage = 1.0f;
	
	UPROPERTY(EditAnywhere)
	bool IsPredator = false;
};

USTRUCT(BlueprintType)
struct FSurvivalStats
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, Category = "Survival Stats")
	float MaxHunger = 100.0f;

	UPROPERTY(EditAnywhere, Category = "Survival Stats")
	float MaxThirst = 100.0f;

	UPROPERTY(EditAnywhere, Category = "Survival Stats")
	float DecayValue = 1.0f;	
};

USTRUCT(BlueprintType)
struct FMoveStats
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement Stats")
	float WalkSpeed = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement Stats")
	float SprintSpeed = 200.0f;
};

USTRUCT(BlueprintType)
struct FDetection
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	bool bDetectEnemies = false;
	UPROPERTY(EditAnywhere)
	bool bDetectFriendlies = false;
	UPROPERTY(EditAnywhere)
	bool bDetectNeutral = false;
};

USTRUCT(BlueprintType)
struct FStimuli 
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI Stimuli|Sight")
	float SightDistance = 300.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI Stimuli|Sight")
	float LoseSightRadius = 300.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI Stimuli|Hearing")
	float HearingDistance = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI Stimuli|Hearing")
	float MaxAge = 0;
	
	UPROPERTY(EditAnywhere, blueprintReadWrite, Category = "AI Stimuli|Hearing")
	float FOV = 180;
};

UCLASS()
class ANIMALICIOUS_API UAnimalDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	FGamePlayTagOrThreats GamePlayTagOrThreats;
	
	UPROPERTY(EditAnywhere)
	FCombatStats CombatStats;
	
	UPROPERTY(EditAnywhere)
	FSurvivalStats SurvivalStats;
	
	UPROPERTY(EditAnywhere)
	FMoveStats FMoveStats;
	
	UPROPERTY(EditAnywhere)
	FDetection Detection;

	UPROPERTY(EditAnywhere)
	FStimuli Stimuli;

};

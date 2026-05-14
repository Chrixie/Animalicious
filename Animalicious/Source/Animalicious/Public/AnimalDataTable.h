#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "AnimalDataTable.generated.h"

USTRUCT(BlueprintType)
struct FGamePlayTagOrThreats
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, meta=(Categories="Species"))
	FGameplayTagContainer ThreatTags;	
	
	UPROPERTY(EditAnywhere, meta=(Categories="Species"))
	FGameplayTagContainer PreyTags;
	
	UPROPERTY(EditAnywhere, meta=(Categories="Species"))
	FGameplayTag GameplayTag;
};

USTRUCT(BlueprintType)
struct FCombatStats
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, Category = "Survival Stats")
	float MaxHealth = 100.0f;

	UPROPERTY(EditAnywhere, Category = "Survival Stats")
	float Damage = 1.0f;
	
	UPROPERTY(EditAnywhere, Category = "Survival Stats")
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

	UPROPERTY(EditAnywhere, Category = "Movement Stats")
	float WalkSpeed = 100.0f;

	UPROPERTY(EditAnywhere, Category = "Movement Stats")
	float SprintSpeed = 200.0f;
};

USTRUCT(BlueprintType)
struct FDetection
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	bool bDetectEnemies = true;
	UPROPERTY(EditAnywhere)
	bool bDetectFriendlies = true;
	UPROPERTY(EditAnywhere)
	bool bDetectNeutral = true;
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

USTRUCT(BlueprintType)
struct ANIMALICIOUS_API FAnimalDataTable: public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, meta = (ShowOnlyInnerProperties))
	FGamePlayTagOrThreats GamePlayTagOrThreats;
	
	UPROPERTY(EditAnywhere, meta = (ShowOnlyInnerProperties))
	FCombatStats CombatStats;
	
	UPROPERTY(EditAnywhere, meta = (ShowOnlyInnerProperties))
	FSurvivalStats SurvivalStats;
	
	UPROPERTY(EditAnywhere, meta = (ShowOnlyInnerProperties))
	FMoveStats FMoveStats;
	
	UPROPERTY(EditAnywhere, meta = (ShowOnlyInnerProperties))
	FDetection Detection;

	UPROPERTY(EditAnywhere, meta = (ShowOnlyInnerProperties))
	FStimuli Stimuli;
};
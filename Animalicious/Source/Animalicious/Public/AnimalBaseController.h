// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AISenseConfig_Hearing.h"
#include "AnimalBase.h"
#include "Components/StateTreeAIComponent.h"
#include "AnimalBaseController.generated.h"

struct FAIStimulus;

UCLASS()
class ANIMALICIOUS_API AAnimalBaseController : public AAIController
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Perception")
	TObjectPtr<UAIPerceptionComponent> AIPerception;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Perception")
	TObjectPtr<UAISenseConfig_Sight> SightConfig;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Perception")
	TObjectPtr<UAISenseConfig_Hearing> HearingConfig;

	UPROPERTY()
	AAnimalBase* AnimalBase;

	

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "StateTree")
	TObjectPtr<UStateTreeAIComponent> StateTreeComponent;

	//--------------------------------------------------------------------------------------------------------------

	UFUNCTION(BlueprintCallable)
	void OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);
	AAnimalBaseController();

protected:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* Inpawn) override;

private:

};

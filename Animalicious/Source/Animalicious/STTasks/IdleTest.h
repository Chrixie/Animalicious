// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/StateTreeTaskBlueprintBase.h"
#include "AnimalBase.h"
#include "AnimalBaseController.h"
#include "IdleTest.generated.h"

/**
 * 
 */
UCLASS()
class ANIMALICIOUS_API UIdleTest : public UStateTreeTaskBlueprintBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly, Category = Context, meta = (Context))
	TObjectPtr<AAnimalBase> Character;

	UPROPERTY(BlueprintReadOnly, Category = Context, meta = (Context))
	TObjectPtr<AAnimalBaseController> AIController;
};

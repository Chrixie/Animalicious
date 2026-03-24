// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimalBaseController.h"

AAnimalBaseController::AAnimalBaseController()
{
	AIPerception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerception"));

	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
	AIPerception->ConfigureSense(*SightConfig);


	HearingConfig = CreateDefaultSubobject<UAISenseConfig_Hearing>(TEXT("HearingConfig"));
	//HearingConfig->DetectionByAffiliation.DetectAllFlags();
	AIPerception->ConfigureSense(*HearingConfig);
	AIPerception->SetDominantSense(SightConfig->GetSenseImplementation());
}

void AAnimalBaseController::BeginPlay()
{
	Super::BeginPlay();

}

void AAnimalBaseController::OnPossess(APawn* Inpawn)
{
	Super::OnPossess(Inpawn);

	AnimalBase = Cast<AAnimalBase>(Inpawn);
	if (AnimalBase && AnimalBase->AnimalDA)
	{
		SightConfig->SightRadius = AnimalBase->AnimalDA->SightDistance;
		SightConfig->LoseSightRadius = AnimalBase->AnimalDA->LoseSightRadius;
		SightConfig->DetectionByAffiliation.DetectAllFlags();
		AIPerception->ConfigureSense(*SightConfig);

		HearingConfig->HearingRange = AnimalBase->AnimalDA->HearingDistance;
		HearingConfig->LoSHearingRange = AnimalBase->AnimalDA->LosHearingRange;
		HearingConfig->SetMaxAge(AnimalBase->AnimalDA->MaxAge);

		AIPerception->OnTargetPerceptionUpdated.AddDynamic(this, &AAnimalBaseController::OnTargetPerceptionUpdated);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Possessed Pawn is not an AAnimalBase or is missing AnimalDA!"));
	}

}

void AAnimalBaseController::OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	if(Stimulus.WasSuccessfullySensed())
	{
	AnimalBase->SetDebugStatusText(FText::FromString("Sensed"));
	}
}

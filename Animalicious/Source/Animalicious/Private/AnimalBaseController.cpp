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

	StateTreeComponent = CreateDefaultSubobject<UStateTreeAIComponent>(TEXT("StateTreeComponent"));
}

void AAnimalBaseController::BeginPlay()
{
	Super::BeginPlay();

}

void AAnimalBaseController::OnPossess(APawn* Inpawn)
{
	Super::OnPossess(Inpawn);

	AnimalBase = Cast<AAnimalBase>(Inpawn);

	if (AnimalBase && AnimalBase->GetAnimalDA())
	{
		const UAnimalDataAsset* AnimalDA = AnimalBase->GetAnimalDA();
		const FDetection& AnimalDADetection = AnimalDA->Detection;
		const FStimuli& AnimalDAStimuli = AnimalDA->Stimuli;

		SightConfig->SightRadius = AnimalDAStimuli.SightDistance;
		SightConfig->LoseSightRadius = AnimalDAStimuli.LoseSightRadius;
		SightConfig->DetectionByAffiliation.bDetectEnemies = AnimalDADetection.bDetectEnemies;
		SightConfig->DetectionByAffiliation.bDetectFriendlies = AnimalDADetection.bDetectFriendlies;
		SightConfig->DetectionByAffiliation.bDetectNeutrals = AnimalDADetection.bDetectNeutral;
		SightConfig->PeripheralVisionAngleDegrees = AnimalDAStimuli.FOV;
		AIPerception->ConfigureSense(*SightConfig);

		HearingConfig->HearingRange = AnimalDAStimuli.HearingDistance;
		HearingConfig->DetectionByAffiliation.bDetectEnemies = AnimalDADetection.bDetectEnemies;
		HearingConfig->DetectionByAffiliation.bDetectFriendlies = AnimalDADetection.bDetectFriendlies;
		HearingConfig->DetectionByAffiliation.bDetectNeutrals = AnimalDADetection.bDetectNeutral;
		HearingConfig->SetMaxAge(AnimalDAStimuli.MaxAge);

		
	
		AIPerception->ConfigureSense(*HearingConfig);
		AIPerception->RequestStimuliListenerUpdate();
		AIPerception->OnTargetPerceptionUpdated.AddDynamic(this, &AAnimalBaseController::OnTargetPerceptionUpdated);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Possessed Pawn is not an AAnimalBase or is missing AnimalDA!"));
	}

}

void AAnimalBaseController::OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	if (Stimulus.WasSuccessfullySensed())
	{
		AnimalBase->SetDebugStatusText(FText::FromString("Sensed"));
	}
}

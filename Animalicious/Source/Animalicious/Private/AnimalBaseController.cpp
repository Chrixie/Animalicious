// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimalBaseController.h"

AAnimalBaseController::AAnimalBaseController()
{
	/*
	AIPerception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerceptionss"));
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
	AIPerception->ConfigureSense(*SightConfig);

	HearingConfig = CreateDefaultSubobject<UAISenseConfig_Hearing>(TEXT("HearingConfig"));
	//HearingConfig->DetectionByAffiliation.DetectAllFlags();
	AIPerception->ConfigureSense(*HearingConfig);
	
	DamageConfig = CreateDefaultSubobject<UAISenseConfig_Damage>(TEXT("DamageConfig"));
	AIPerception->ConfigureSense(*DamageConfig);

	StateTreeComponent = CreateDefaultSubobject<UStateTreeAIComponent>(TEXT("StateTreeComponent"));
	*/
}

void AAnimalBaseController::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	AIPerception = FindComponentByClass<UAIPerceptionComponent>();
	
	SightConfig = AIPerception->GetSenseConfig<UAISenseConfig_Sight>();
	
	HearingConfig = AIPerception->GetSenseConfig<UAISenseConfig_Hearing>();
	
	DamageConfig = AIPerception->GetSenseConfig<UAISenseConfig_Damage>();
	
	StateTreeComponent = FindComponentByClass<UStateTreeAIComponent>();
}

void AAnimalBaseController::BeginPlay()
{
	Super::BeginPlay();

	AIPerception->OnTargetPerceptionUpdated.AddDynamic(this, &AAnimalBaseController::OnPerception);
	//SightConfig = AIPerception->GetSenseConfig(UAISenseConfig_Sight::StaticClass());
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

		if (AIPerception)
		{
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
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Possessed Pawn is not an AAnimalBase or is missing AnimalDA!"));
	}
}

void AAnimalBaseController::OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	//TSubclassOf<UAISense> DamageSense = UAISense_Damage::StaticClass();

	if (Stimulus.WasSuccessfullySensed())
	{
		AnimalBase->SetDebugStatusText(FText::FromString("Sensed"));
	}

	// if (UAIPerceptionSystem::GetSenseClassForStimulus(GetWorld(), Stimulus) && Stimulus == ReceiveAnyDamage())
	// {
	// 	float DamageAmount = Stimulus.Strength;
	// 	
	// 	AnimalBase->CurrentHealth -= DamageAmount;
	// }
}

void AAnimalBaseController::OnPerception(AActor* Actor, FAIStimulus Stimulus)
{
	// Check if the stimulus that just triggered is Damage
	if (Stimulus.Type == UAISense::GetSenseID<UAISense_Damage>())
	{
		UE_LOG(LogTemp, Warning, TEXT("I was hit by %s!"), *Actor->GetName());
	}
}

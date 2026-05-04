// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimalBase.h"
#include "AnimalBaseController.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AAnimalBase::AAnimalBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// AIPerceptionSource = CreateDefaultSubobject<UAIPerceptionStimuliSourceComponent>(TEXT("AIPerceptionStimuliSource"));
	// AIPerceptionSource->RegisterForSense(TSubclassOf<UAISense_Sight>());
	// AIPerceptionSource->RegisterForSense(TSubclassOf<UAISense_Hearing>());
	// AIPerceptionSource->RegisterForSense(TSubclassOf<UAISense_Damage>());
	// AIPerceptionSource->RegisterWithPerceptionSystem();
	
	StatusText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("StatusText"));
	StatusTextInit();
	
}

void AAnimalBase::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	
	AIPerceptionSource = FindComponentByClass<UAIPerceptionStimuliSourceComponent>();
}

// Called when the game starts or when spawned
void AAnimalBase::BeginPlay()
{
	Super::BeginPlay();

	if (!IsValid(AnimalDA))
	{
		UE_LOG(LogTemp, Error, TEXT("AnimalDA IS NOT VALID"));
			return;
	}

	// AIPerceptionSource->RegisterForSense(TSubclassOf<UAISense_Sight>());
	// AIPerceptionSource->RegisterForSense(TSubclassOf<UAISense_Hearing>());
	// AIPerceptionSource->RegisterWithPerceptionSystem();

	SetupStats();
}

// Called every frame
void AAnimalBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	StatusText->SetWorldRotation(FRotator(0.0f,0.0f,0.0f));
	
	if (!bIsDead && GetCharacterMovement()->Velocity.Length() > 0.1f)
	UAISense_Hearing::ReportNoiseEvent(GetWorld(), GetActorLocation(), 1, this, 0);
	
	if (!bIsDead)
	{
	DecreaseHunger(DeltaTime);
	DecreaseThirst(DeltaTime);
	}
	
	
	if (CurrentHealth <= 0.0f)
		bIsDead = true;

}

// Called to bind functionality to input
void AAnimalBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


}

void AAnimalBase::SetupStats()
{
	const FCombatStats* CombatStats = &AnimalDA->CombatStats;
	const FSurvivalStats* SurvivalStats = &AnimalDA->SurvivalStats;
	const FGamePlayTagOrThreats* GameplayTags = &AnimalDA->GamePlayTagOrThreats;
	
	//Combatstats
	CurrentHealth = CombatStats->MaxHealth;
	Damage = CombatStats->Damage;
	IsPredator = CombatStats->IsPredator;
	
	//SurvivalStats
	CurrentHunger = SurvivalStats->MaxHunger;
	CurrentThirst = SurvivalStats->MaxThirst;
	
	//GameplayTags
	ThreatTags = GameplayTags->ThreatTags;
	PreyTags = GameplayTags->PreyTags;
	GameplayTag = GameplayTags->GameplayTag;

}

void AAnimalBase::DecreaseHunger(float DeltaTime)
{
	CurrentHunger -= AnimalDA->SurvivalStats.DecayValue * DeltaTime;
}

void AAnimalBase::DecreaseThirst(float DeltaTime)
{
	CurrentThirst -= AnimalDA->SurvivalStats.DecayValue * DeltaTime;
}

void AAnimalBase::SetDebugStatusText(FText StatusDebugText)
{
	StatusText->SetText((StatusDebugText));
}

void AAnimalBase::StatusTextInit()
{
	StatusText->SetupAttachment(RootComponent);
	StatusText->SetHorizontalAlignment(EHTA_Center);
	StatusText->SetWorldSize(50.0f);
	StatusText->SetTextRenderColor(FColor::Red);
	StatusText->SetRelativeLocation(FVector(0,0,40));
}


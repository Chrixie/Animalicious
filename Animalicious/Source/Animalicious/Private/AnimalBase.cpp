// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimalBase.h"

// Sets default values
AAnimalBase::AAnimalBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
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

	SetupStats();
}

// Called every frame
void AAnimalBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DecreseHunger(DeltaTime);
	DecreseThirst(DeltaTime);
}

// Called to bind functionality to input
void AAnimalBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


}



void AAnimalBase::SetupStats()
{
	CurrentHealth = AnimalDA->MaxHealth;
	CurrentHunger = AnimalDA->MaxHunger;
	CurrentThirst = AnimalDA->MaxThirst;
}

void AAnimalBase::DecreseHunger(float DeltaTime)
{
	CurrentHunger -= AnimalDA->DecayValue * DeltaTime;
}

void AAnimalBase::DecreseThirst(float DeltaTime)
{
	CurrentThirst -= AnimalDA->DecayValue * DeltaTime;
}


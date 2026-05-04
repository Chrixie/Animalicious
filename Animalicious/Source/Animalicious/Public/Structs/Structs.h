// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Object.h"
#include "Structs.generated.h"

USTRUCT(BlueprintType)
struct FAIStimulusPayload
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = AIStimulus)
	FVector StimulusLocation;
	
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = AIStimulus)
	FVector ReceiverLocation;
	
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = AIStimulus)
	TObjectPtr<AActor> SourceActor;	
	
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = AIStimulus)
	FGameplayTagContainer SourceTags;
	
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = AIStimulus)
	FGameplayTag SenseTag;
	
	FAIStimulusPayload() = default;
	
	/*FAIStimulusPayload() : StimulusLocation(FVector::Zero()), ReceiverLocation(FVector::Zero()), SourceActor(nullptr), SenseTag(FGameplayTag::EmptyTag)
	{
		
	}
	
	FAIStimulusPayload(const FAIStimulusPayload& Other)
	: StimulusLocation(Other.StimulusLocation),
	  ReceiverLocation(Other.ReceiverLocation),
	  SourceActor(Other.SourceActor),
	  SourceTags(Other.SourceTags),
	  SenseTag(Other.SenseTag)
	{
	}

	FAIStimulusPayload(FAIStimulusPayload&& Other) noexcept
		: StimulusLocation(std::move(Other.StimulusLocation)),
		  ReceiverLocation(std::move(Other.ReceiverLocation)),
		  SourceActor(std::move(Other.SourceActor)),
		  SourceTags(std::move(Other.SourceTags)),
		  SenseTag(std::move(Other.SenseTag))
	{
	}

	FAIStimulusPayload& operator=(const FAIStimulusPayload& Other)
	{
		if (this == &Other)
			return *this;
		StimulusLocation = Other.StimulusLocation;
		ReceiverLocation = Other.ReceiverLocation;
		SourceActor = Other.SourceActor;
		SourceTags = Other.SourceTags;
		SenseTag = Other.SenseTag;
		return *this;
	}

	FAIStimulusPayload& operator=(FAIStimulusPayload&& Other) noexcept
	{
		if (this == &Other)
			return *this;
		StimulusLocation = std::move(Other.StimulusLocation);
		ReceiverLocation = std::move(Other.ReceiverLocation);
		SourceActor = std::move(Other.SourceActor);
		SourceTags = std::move(Other.SourceTags);
		SenseTag = std::move(Other.SenseTag);
		return *this;
	}*/
};
UCLASS()
class ANIMALICIOUS_API UStructs : public UObject
{
	GENERATED_BODY()
};

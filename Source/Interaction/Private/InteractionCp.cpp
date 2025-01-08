// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionCp.h"

// Sets default values for this component's properties
UInteractionCp::UInteractionCp()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInteractionCp::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInteractionCp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

FString UInteractionCp::GetInteractionLabel() const
{
	return InteractionLabel;
}

void UInteractionCp::Interact()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Interact"));
	OnInteractionStart();
}

void UInteractionCp::OnInteractionStart()
{
	
}

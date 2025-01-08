// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerInteractionComponent.h"



UPlayerInteractionComponent::UPlayerInteractionComponent()
{
	OnComponentBeginOverlap.AddDynamic(this, &UPlayerInteractionComponent::OnOverlapBegin);
	OnComponentEndOverlap.AddDynamic(this, &UPlayerInteractionComponent::OnOverlapEnd);
}

void UPlayerInteractionComponent::OnAskInteract()
{
	if (canInteract)
	{
		UInteractionCp* InteractionCp = interactingActor->FindComponentByClass<UInteractionCp>();
		if (InteractionCp == nullptr){ return; }
		InteractionCp->Interact();
	}
}

void UPlayerInteractionComponent::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == nullptr){ return; }
	UInteractionCp* InteractionCp = OtherActor->FindComponentByClass<UInteractionCp>();
	if (InteractionCp == nullptr){ return; }
	interactingActor = OtherActor;
	canInteract = true;
}

void UPlayerInteractionComponent::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor == nullptr){ return; }
	UInteractionCp* InteractionCp = OtherActor->FindComponentByClass<UInteractionCp>();
	if (InteractionCp == nullptr){ return; }
	interactingActor = nullptr;
	canInteract = false;
}
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "InteractionCp.h"
#include "PlayerInteractionComponent.generated.h"

/**
 * 
 */
UCLASS( ClassGroup=(Interaction), meta=(BlueprintSpawnableComponent) )
class INTERACTION_API UPlayerInteractionComponent : public UCapsuleComponent
{
	GENERATED_BODY()

private:

	UPROPERTY()
	bool canInteract = false;

	UPROPERTY()
	AActor* interactingActor;

public:
	
	UFUNCTION(BlueprintCallable)
	void OnAskInteract();
	
	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	UPlayerInteractionComponent();

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
};

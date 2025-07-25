// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "ObjectiveZone.generated.h"

class UBoxComponent;
class UDecalComponent;

UCLASS()
class IPVMULTI_API AObjectiveZone : public AActor
{
	GENERATED_BODY()

public:
	
	AObjectiveZone();

protected:
	
	virtual void BeginPlay() override;

	virtual void PostInitializeComponents() override;
	
	//UPROPERTY(VisibleAnywhere, Category="Component")
	//UBoxComponent* OverlapComp;

	UPROPERTY(VisibleAnywhere, Category="Component")
	TObjectPtr<UBoxComponent> OverlapComponent;

	UFUNCTION()
	void HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
						int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UPROPERTY(VisibleAnywhere, Category="Component")
	UDecalComponent* DecalComp;

};

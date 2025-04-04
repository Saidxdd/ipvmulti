﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "Ipvmulti/Public/Actors/LaunchPad.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Character.h"


// Sets default values
ALaunchPad::ALaunchPad()
{
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
	OverlapComp = CreateDefaultSubobject<UBoxComponent>("BoxComp");
	RootComponent = OverlapComp;
	MeshComp->SetupAttachment(OverlapComp);
	LaunchForce = 1000;
	LaunchAngle = 90;
}

// Called when the game starts or when spawned
void ALaunchPad::BeginPlay()
{
	Super::BeginPlay();
	OverlapComp->OnComponentBeginOverlap.AddDynamic(this, &ALaunchPad::OverlapLaunchpad); 
}

// Called every frame
void ALaunchPad::OverlapLaunchpad(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult){

	FRotator LaunchDirection = GetActorRotation();
	LaunchDirection.Pitch += LaunchAngle;
	FVector LaunchVelocity = LaunchDirection.Vector()*LaunchForce;

	ACharacter* MyCharacter = Cast<ACharacter>(OtherActor);
	if (MyCharacter)
		{
		MyCharacter->LaunchCharacter(LaunchVelocity, true, true);
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("Overlap"));
		}
	}
}


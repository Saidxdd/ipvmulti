// Copyright Epic Games, Inc. All Rights Reserved.

#include "IpvmultiGameMode.h"
#include "Actors/IpvmultiCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Actors/IpvmultiCharacter.h"
#include "Game/ipvmultiGameState.h"
#include "Kismet/GameplayStatics.h"

AIpvmultiGameMode::AIpvmultiGameMode()
{
	
	/*static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}*/
	GameStateClass = AipvmultiGameState::StaticClass();
}

void AIpvmultiGameMode::CompleteMission(APawn* Pawn)
{
	if (Pawn == nullptr) return;
	//Pawn->DisableInput(nullptr);

	if (SpectatorViewClass)
	{
		TArray<AActor*> ReturnActors;
		UGameplayStatics::GetAllActorsOfClass(this,SpectatorViewClass, ReturnActors);
		if (ReturnActors.Num() > 0)
		{
			AActor* NewViewTarget = ReturnActors[0];
			for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
			{
				APlayerController* PC = It->Get();
				if (PC)
				{
					PC->SetViewTargetWithBlend(NewViewTarget, 1.0f, VTBlend_Linear);
				}
			}
			
		}
	}
	AipvmultiGameState* GS = GetGameState<AipvmultiGameState>();
	if (GS)
	{
		GS->MultiCastOnMissionCompleted(Pawn, true);
	}
	OnMissionCompleted(Pawn);
}


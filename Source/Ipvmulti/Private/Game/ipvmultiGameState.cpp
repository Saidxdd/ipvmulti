#include "Game/ipvmultiGameState.h"

#include "EngineUtils.h"
#include "Player/IpvmultiPlayerController.h"

void AipvmultiGameState::MultiCastOnMissionCompleted_Implementation(APawn* instagorPawn, bool bMissionSuccess)
{
	//Afecta solo al que toco la meta con el tesoro
	/*if (APlayerController* PC = GetWorld()->GetFirstPlayerController())
		if (APawn* Pawn = PC->GetPawn())
			Pawn->DisableInput(nullptr);
*/
	//Afecta a todos los players
	/*for (TActorIterator<APawn> It(GetWorld()); It; ++It)
	{
		APawn* Pawn = *It;
		if (Pawn && Pawn->IsLocallyControlled())
		{
			Pawn->DisableInput(nullptr); 
		}
	}*/

	for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
	{
		AIpvmultiPlayerController* PC = Cast<AIpvmultiPlayerController>(It->Get());
		if (PC)
		{
			PC->OnMissionComplete(instagorPawn, bMissionSuccess);
			APawn* Pawn = PC->GetPawn();
			if (Pawn)
			{
				Pawn->DisableInput(nullptr);
			}
		}
	}
}



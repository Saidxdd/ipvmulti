#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "ipvmultiGameState.generated.h"


UCLASS()
class IPVMULTI_API AipvmultiGameState : public AGameStateBase
{
	GENERATED_BODY()
public:
	UFUNCTION(NetMulticast, Reliable)
	void MultiCastOnMissionCompleted(APawn* instagorPawn, bool bMissionSuccess);
};

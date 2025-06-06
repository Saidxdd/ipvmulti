
#include "MyAmoo.h"
#include "Components/BoxComponent.h"
#include "Ipvmulti/IpvmultiCharacter.h"


AMyAmoo::AMyAmoo()
{
 	
	PrimaryActorTick.bCanEverTick = true;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));

	CollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CollisionBox->SetCollisionObjectType(ECC_Pawn);
	CollisionBox->SetCollisionResponseToAllChannels(ECR_Overlap);
	CollisionBox->SetGenerateOverlapEvents(true);

	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AMyAmoo::OnOverlapBegin);

}

void AMyAmoo::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor == Cast<AIpvmultiCharacter>(OtherActor))
	{
		AIpvmultiCharacter* player = Cast<AIpvmultiCharacter>(OtherActor);
		player->AddAmmo();
		Destroy();
	}
}


void AMyAmoo::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMyAmoo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


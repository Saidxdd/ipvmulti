#include "ObjectiveActor.h"

#include "Components/SphereComponent.h"
#include "Actors/IpvmultiCharacter.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AObjectiveActor::AObjectiveActor()
{
	bReplicates = true;
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RootComponent = MeshComp;

	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("spherecomp"));
	SphereComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SphereComp->SetCollisionResponseToChannels(ECR_Ignore);
	SphereComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	SphereComp->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AObjectiveActor::BeginPlay()
{
	Super::BeginPlay();

}

void AObjectiveActor::PlayEffects()
{
	UGameplayStatics::SpawnEmitterAtLocation(this, PickUpVfx, GetActorLocation());
}

// Called every frame
void AObjectiveActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AObjectiveActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	PlayEffects();

	AIpvmultiCharacter* MyCharacter = Cast<AIpvmultiCharacter>(OtherActor);
	if (MyCharacter)
	{
		MyCharacter->bIsCarryingObejective = true;
		Destroy();
	}
}


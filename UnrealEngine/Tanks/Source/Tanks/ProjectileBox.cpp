#include "ProjectileBox.h"
#include "Components\StaticMeshComponent.h"
#include "Components\SceneComponent.h"
#include "TankPawn.h"
#include "Cannon.h"

AProjectileBox::AProjectileBox()
{
	PrimaryActorTick.bCanEverTick = false;

	USceneComponent* SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = SceneComp;

	AmmoMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AmmoMesh"));
	AmmoMesh->SetupAttachment(SceneComp);
	AmmoMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	AmmoMesh->SetCollisionProfileName("OverlapAll");
	AmmoMesh->OnComponentBeginOverlap.AddDynamic(this, &AProjectileBox::OnMeshOverlapBegin);
}

void AProjectileBox::OnMeshOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ATankPawn* TankPawn = Cast<ATankPawn>(OtherActor);
	if (TankPawn)
	{
		TankPawn->GetCannon()->IncreaseProjectileAmount(value);
	}
}
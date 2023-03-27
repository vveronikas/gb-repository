#include "Projectile.h"
#include "Components\StaticMeshComponent.h"
#include "TimerManager.h"
#include "Cannon.h"

AProjectile::AProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

	USceneComponent* SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root component"));
	RootComponent = SceneComponent;

	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh"));
	ProjectileMesh->SetupAttachment(SceneComponent);
	ProjectileMesh->SetCollisionObjectType(ECollisionChannel::ECC_EngineTraceChannel1);
	ProjectileMesh->OnComponentBeginOverlap.AddDynamic(this, &AProjectile::OnMeshOverlapBegin);
}

void AProjectile::Start()
{
	GetWorld()->GetTimerManager().SetTimer(MovementTimer, this, &AProjectile::Move, MoveRate, true, 0.0f);
}

void AProjectile::Move()
{
	FVector nextPosition = GetActorLocation() + GetActorForwardVector() * MoveSpeed * MoveRate;
	SetActorLocation(nextPosition);
}

void AProjectile::OnMeshOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
									int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("Overlapped with %s. "), *OtherActor->GetName());
		OtherActor->Destroy();
		Destroy();
	}
}
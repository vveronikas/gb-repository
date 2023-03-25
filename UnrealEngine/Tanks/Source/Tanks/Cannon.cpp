// Fill out your copyright notice in the Description page of Project Settings.


#include "Cannon.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ArrowComponent.h"

ACannon::ACannon()
{
	PrimaryActorTick.bCanEverTick = true;

	USceneComponent* SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = SceneComp;

	CannonMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CannonMesh"));
	CannonMesh->SetupAttachment(SceneComp);

	ProjectileSwanPoint = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComponent"));
	ProjectileSwanPoint->SetupAttachment(CannonMesh);
}

void ACannon::BeginPlay()
{
	Super::BeginPlay();
	bReadyToFire = true;
}

void ACannon::Fire()
{
	if (!IsReadyToFire())
	{
		return;
	}

	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, FString::Printf(TEXT("Projectile amount: %d"), projectileAmount));

	if (CannonType == ECannonType::FireProjectile)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Purple, FString::Printf(TEXT("Fire projectile")));
		projectileAmount--;
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Purple, FString::Printf(TEXT("FireTrace")));
		projectileAmount--;
	}
	bReadyToFire = false;
	GetWorld()->GetTimerManager().SetTimer(ReloadTimer, this, &ACannon::Reload, FireRate, false);
}

bool ACannon::IsReadyToFire()
{
	return bReadyToFire;
}

void ACannon::Reload()
{
	if (projectileAmount <= 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, FString::Printf(TEXT("Reload 10 sec")));
		bReadyToFire = false;
		GetWorld()->GetTimerManager().SetTimer(ReloadTimer, this, &ACannon::ReloadProjectileAmount, ReloadRate, false);
	}
	else
	{
		bReadyToFire = true;
	}
}

void ACannon::ReloadProjectileAmount()
{
	projectileAmount = 10;
	bReadyToFire = true;
}

void ACannon::ChangeCannonType()
{
	if (CannonType == ECannonType::FireProjectile)
	{
		CannonType = ECannonType::FireTrace;
	}
	else
	{
		CannonType = ECannonType::FireProjectile;
	}
}
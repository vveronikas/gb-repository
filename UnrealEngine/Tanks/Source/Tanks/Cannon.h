// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameStruct.h"
#include "Cannon.generated.h"

UCLASS()
class TANKS_API ACannon : public AActor
{
	GENERATED_BODY()
	
public:	
	ACannon();

	void Fire();
	bool IsReadyToFire();
	void Reload();
	void ReloadProjectileAmount();
	void ChangeCannonType();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Components")
	class UStaticMeshComponent* CannonMesh;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Components")
	class UArrowComponent* ProjectileSwanPoint;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Components")
	ECannonType CannonType = ECannonType::FireProjectile;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Fire params")
	float FireRate = 1.0f;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Fire params")
	float Danmage = 1.0f;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Fire params")
	float ReloadRate = 10.0f;

	bool bReadyToFire = true;
	FTimerHandle ReloadTimer;
	int projectileAmount = 10;
};

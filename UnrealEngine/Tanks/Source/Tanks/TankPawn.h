// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TankPawn.generated.h"

class ACannon;

UCLASS()
class TANKS_API ATankPawn : public APawn
{
	GENERATED_BODY()

public:
	ATankPawn();
	
	void MoveForward(float DeltaTime);
	void MoveRight(float Value);
	void RotateRight(float Value);

	void Fire();

	void SetupCannon(TSubclassOf<ACannon> newCannonClass);
	void SwapCannon();

	ACannon* GetCannon() const { return Cannon; };

protected:
	virtual void BeginPlay() override;

	void SetLocation(const float DeltaTime);

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Components")
	class UStaticMeshComponent* BodyMesh;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Components")
	class UStaticMeshComponent* TurretMesh;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Components")
	class UBoxComponent* BoxCollision;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Components")
	class USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Components")
	class UCameraComponent* Camera;

	UPROPERTY()
	ACannon* Cannon;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Cannon")
	class UArrowComponent* CannonSetupPoint;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Cannon")
	TSubclassOf<ACannon> EquippedCannonCalss;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Cannon")
	TSubclassOf<ACannon> SecondCannonCalss;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Movement")
	float MoveSpeed = 100.0f;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Movement")
	float RotationSpeed = 100.0f;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Movement")
	float TurretRotationInterpolationKey = 0.1f;

	UPROPERTY()
	class ATankPlayerController* TankController;


private:
	float targetForwardAxisValue = 0;
	float targetRightAxisValue = 0;
	float targetRotateRightAxisValue = 0;


public:	
	virtual void Tick(float DeltaTime) override;
};

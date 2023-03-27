#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class TANKS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	AProjectile();
	void Start();

protected:

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Components")
	class UStaticMeshComponent* ProjectileMesh;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Movement")
	float MoveSpeed = 100.0f;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Movement")
	float MoveRate = 0.1f;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Movement")
	float Damage = 1.0f;

	FTimerHandle MovementTimer;

	UFUNCTION()
	void Move();

	UFUNCTION()
	void OnMeshOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, 
							class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, 
							const FHitResult& SweepResult);
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Paddle_Controller.generated.h"

/**
 * 
 */

class ABall;

UCLASS()
class ARKANOID_API APaddle_Controller : public APlayerController
{
	GENERATED_BODY()

		APaddle_Controller();

		//virtual void SetupInputComponent() override;

public:
	virtual void BeginPlay() override;

	void SpawnNewBall();


	UPROPERTY()
		class UInputMappingContext* PawnMappingContext;

	UPROPERTY()
		class UInputAction* MoveAction;

	UPROPERTY(EditAnywhere)
		class TSubclassOf<ABall> Ballobj;
	
	ABall* MyBall;

	FVector SpawnLocation = FVector(10.f, 0.f, 250.0f);
	FRotator SpawnRotation = FRotator(0.f, 0.f, 0.f);
	FActorSpawnParameters SpawnInfo;

};

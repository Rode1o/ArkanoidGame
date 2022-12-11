// Fill out your copyright notice in the Description page of Project Settings.


#include "Paddle_Controller.h"
#include "Kismet/GameplayStatics.h"
#include "InputAction.h"
#include "Templates/SubclassOf.h"
#include "Ball.h"
#include "InputMappingContext.h"
#include "Camera/CameraActor.h"
#include "Paddle.h"

APaddle_Controller::APaddle_Controller()
{
}


void APaddle_Controller::BeginPlay()
{
	TArray<AActor*> CameraActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActors);

	FViewTargetTransitionParams Params;
	SetViewTarget(CameraActors[0], Params);

	SpawnNewBall();
}

void APaddle_Controller::SpawnNewBall()
{
	if (!MyBall)
		MyBall = nullptr;

	if (Ballobj) {
		MyBall = GetWorld()->SpawnActor<ABall>(Ballobj, SpawnLocation, SpawnRotation, SpawnInfo);
	}
}



/*void APaddle_Controller::SetupInputComponent()
{
	Super::SetupInputComponent();

	PawnMappingContext = NewObject<UInputMappingContext>(this);
	MoveAction = NewObject<UInputAction>(this);
	MoveAction->ValueType = EInputActionValueType::Axis1D;
	PawnMappingContext->MapKey(MoveAction, EKeys::D);



}
*/
// Fill out your copyright notice in the Description page of Project Settings.


#include "Paddle.h"
#include "Paddle_Controller.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
APaddle::APaddle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SM_Paddle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = SM_Paddle;
	SM_Paddle->SetEnableGravity(false);
	//SM_Paddle->SetConstraintMode(EDOFMode::XZPlane);
	SM_Paddle->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SM_Paddle->SetCollisionProfileName(TEXT("PhysicsActor"));
	
	Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Floating Movement"));
	Movement->Acceleration = 20000.f;
	
}

// Called when the game starts or when spawned
void APaddle::BeginPlay()
{
	Super::BeginPlay();
	SM_Paddle->SetConstraintMode(EDOFMode::XZPlane);
	
}

// Called every frame
void APaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


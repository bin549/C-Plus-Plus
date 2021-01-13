// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActor.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AMyActor::AMyActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MyStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyStaticMesh"));

	InitLocation = FVector(0.0f);
	PlacedLocation = FVector(0.0f);
	bGotoInitLocation = false;
	WorldOrigin = FVector(0.0f);
	TickLocationOffset = FVector(0.0f);
	bShouldMove = false;

	//InitForce = FVector(0.0f);
	//InitTorque = FVector(0.0f);
	//bAccelChange = false;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	PlacedLocation = GetActorLocation();
	if (bGotoInitLocation)
	{
		SetActorLocation(InitLocation);
	}

	//MyStaticMesh->AddForce(InitForce, "NAME_None", bAccelChange);
	//MyStaticMesh->AddTorque(InitTorque, "NAME_None", bAccelChange);
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bShouldMove)
	{
		FHitResult HitResult;
		AddActorLocalOffset(TickLocationOffset * DeltaTime, true, &HitResult);
		//UE_LOG(LogTemp, Warning, TEXT("X: %f,Y: %f,Z: %f"), HitResult.Location.X, HitResult.Location.Y, HitResult.Location.Z);
	}
}
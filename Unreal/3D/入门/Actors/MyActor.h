// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class BASICTRAINING_API AMyActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMyActor();

	UPROPERTY(VisibleAnywhere, Category = "My Actor Components")
	class UStaticMeshComponent *MyStaticMesh;

	UPROPERTY(EditInstanceOnly, Category = "My Actor Properties | Vector")
	FVector InitLocation;

	UPROPERTY(VisibleInstanceOnly, Category = "My Actor Properties | Vector")
	FVector PlacedLocation;

	UPROPERTY(EditDefaultsOnly, Category = "My Actor Properties | Vector")
	bool bGotoInitLocation;

	UPROPERTY(VisibleDefaultsOnly, Category = "My Actor Properties | Vector")
	FVector WorldOrigin;

	UPROPERTY(EditAnywhere, Category = "My Actor Properties | Vector", meta = (ClampMin = -500.0f, ClampMax = 500.0f, UIMin = -500.0f, UIMax = 500.0f))
	FVector TickLocationOffset;

	UPROPERTY(EditAnywhere, Category = "My Actor Properties | Vector")
	bool bShouldMove;

	/*
	UPROPERTY(EditInstanceOnly, Category = "My Actor Properties | Physics")
	FVector InitForce;

	UPROPERTY(EditInstanceOnly, Category = "My Actor Properties | Physics")
	FVector InitTorque;

	UPROPERTY(EditInstanceOnly, Category = "My Actor Properties | Physics")
	bool bAccelChange;
	*/

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};

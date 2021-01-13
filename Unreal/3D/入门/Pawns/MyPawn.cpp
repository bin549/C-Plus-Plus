// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPawn.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AMyPawn::AMyPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MyStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyStaticMesh"));
	RootComponent = MyStaticMesh;
	MyStaticMesh->SetCollisionProfileName(TEXT("Pawn"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> MaterialAsset(TEXT("Material'/Game/StarterContent/Materials/M_Metal_Burnished_Steel.M_Metal_Burnished_Steel'"));
	if (StaticMeshAsset.Succeeded() && MaterialAsset.Succeeded())
	{
		MyStaticMesh->SetStaticMesh(StaticMeshAsset.Object);
		MyStaticMesh->SetMaterial(0, MaterialAsset.Object);
		MyStaticMesh->SetWorldScale3D(FVector(0.5f));
	}

	MySpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("MySpringArm"));
	MySpringArm->SetupAttachment(GetStaticMeshComponent());
	MySpringArm->RelativeRotation = FRotator(-45.0f, 0.0f, 0.0f);
	MySpringArm->TargetArmLength = 400.0f;
	MySpringArm->bEnableCameraLag = true;
	MySpringArm->CameraLagSpeed = 3.0f;

	MyCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MyCamera"));
	MyCamera->SetupAttachment(GetSpringArmComponent());

	AutoPossessPlayer = EAutoReceiveInput::Player0;
	bUseControllerRotationYaw = true;

	MaxSpeed = 100.0f;
	Velocity = FVector::ZeroVector;
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalOffset(Velocity * DeltaTime, true);

	AddControllerYawInput(MouseInput.X);

	//X,Y,Z
	//Row,Pitch,Yaw
	FRotator NewSpringArmRotation = MySpringArm->GetComponentRotation();
	NewSpringArmRotation.Pitch = FMath::Clamp(NewSpringArmRotation.Pitch += MouseInput.Y, -80.0f, 0.0f);
	MySpringArm->SetWorldRotation(NewSpringArmRotation);
}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AMyPawn::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AMyPawn::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AMyPawn::LookUp);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &AMyPawn::LookRight);
}

void AMyPawn::MoveForward(float Value)
{
	Velocity.X = FMath::Clamp(Value, -1.0f, 1.0f) * MaxSpeed;
}

void AMyPawn::MoveRight(float Value)
{
	Velocity.Y = FMath::Clamp(Value, -1.0f, 1.0f) * MaxSpeed;
}

void AMyPawn::LookUp(float Value)
{
	MouseInput.Y = FMath::Clamp(Value, -1.0f, 1.0f);
}

void AMyPawn::LookRight(float Value)
{
	MouseInput.X = FMath::Clamp(Value, -1.0f, 1.0f);
}

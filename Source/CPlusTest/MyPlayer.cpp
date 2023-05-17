// Fill out your copyright notice in the Description page of Project Settings.
//In this class (.cpp) the interactions will be created


#include "MyPlayer.h"

// Sets default values
AMyPlayer::AMyPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AMyPlayer::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AMyPlayer::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AMyPlayer::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AMyPlayer::AddControllerPitchInput);
	PlayerInputComponent->BindAction(TEXT("Jump"),IE_Pressed, this, &AMyPlayer::Jump);
}

//Set the actions 
void AMyPlayer::MoveForward(float AxisVal)
{
	AddMovementInput(GetActorForwardVector() * AxisVal);
}

void AMyPlayer::MoveRight(float AxisVal)
{
	AddMovementInput(GetActorRightVector() * AxisVal);
}



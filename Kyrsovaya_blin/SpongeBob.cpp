// Fill out your copyright notice in the Description page of Project Settings.
#include "GameFramework/CharacterMovementComponent.h"
#include "Engine/World.h"
#include "Components/SkeletalMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Controller.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "SpongeBob.h"

// Sets default values
ASpongeBob::ASpongeBob()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	/*максимальный угол на который будет подниматься*/
	GetCharacterMovement()->SetWalkableFloorAngle(60);

}

// Called when the game starts or when spawned
void ASpongeBob::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpongeBob::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASpongeBob::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


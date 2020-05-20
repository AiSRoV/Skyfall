// Fill out your copyright notice in the Description page of Project Settings.
#include "Patrick.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Engine/World.h"
#include "Components/SkeletalMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Controller.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"


// Sets default values
APatrick::APatrick() //����������
{ PrimaryActorTick.bCanEverTick = true; 
/*������������ ���� �� ������� ����� �����������*/
GetCharacterMovement()->SetWalkableFloorAngle(60);

}

/*����� ������� ���������� � ������ ����*/
void APatrick::BeginPlay()
{ Super::BeginPlay();
	
}

/* Called every frame*/
void APatrick::Tick(float DeltaTime)
{ Super::Tick(DeltaTime);
	

}

/* Called to bind functionality to input*/
void APatrick::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{ Super::SetupPlayerInputComponent(PlayerInputComponent);

}


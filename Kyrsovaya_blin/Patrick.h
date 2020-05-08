// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Project1.h"
#include "UObject/ConstructorHelpers.h" //����������, ��� ���� ����� ����� ���������� ����� ��� ������ 
#include "Kismet/GameplayStatics.h" //����� ������ �������
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Patrick.generated.h"


UCLASS()
class PROJECT1_API APatrick : public ACharacter	
{
	GENERATED_BODY()//������������ ���� 													 

public:
	APatrick(); //����������� ��� �������� �������, ������											
						
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};

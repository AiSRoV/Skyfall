// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Project1.h"
#include "UObject/ConstructorHelpers.h" //библиотека, для того чтобы могли подключить метод для поиска 
#include "Kismet/GameplayStatics.h" //будет искать бубочку
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Patrick.generated.h"


UCLASS()
class PROJECT1_API APatrick : public ACharacter	
{
	GENERATED_BODY()//генерировать тело 													 

public:
	APatrick(); //конструктор для создания объекта, класса											
						
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Buba.generated.h"

UCLASS()
class PROJECT1_API ABuba : public AActor
{
	GENERATED_BODY()   
	
public:	
	// Sets default values for this actor's properties
	ABuba();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyComponents")
		UStaticMeshComponent* Bubka; //компонент для отображения

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyComponents")
		UBoxComponent* Col; //колизия
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int index;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
		
};


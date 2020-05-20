// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Patrick.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "Containers/Array.h"
#include "GameFramework/PlayerController.h"
#include "ControllerPatrick.generated.h"


UCLASS()
class PROJECT1_API AControllerPatrick : public AAIController
{
	GENERATED_BODY()
public:
		AControllerPatrick();
	
		/*PlayerTick- ф-я которая будет вызываться каждый кадр (она уже есть в ареале но пустая)*/
	virtual void Tick(float DeltaTime) override;   
	virtual void BeginPlay() override;
	

	/*хранит ссылку на мир (Gubka Bob)*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		const UObject* world;

	/*объявление переменной, которая хранит номер бубки на который стоит персонаж*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int OldPozition;

	/*объявление переменной, которая хранит номер бубки на которую пойдет персонаж*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int NewPozition;

	/*будет хранится указатель на класс керектер, наш павн*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<class ACharacter> FindMyPawn;
	
	/*будет хранится ссылка на павна*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		 ATP_ThirdPersonCharacter* TPC;

	/*ф-я, которая будет искать в классе элемент(корневого персонажа)*/
	void FindMainCharacter();
	bool MoveComplete();



};

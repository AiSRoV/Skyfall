// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Containers/Array.h"
#include "UObject/Object.h"
#include "TP_ThirdPersonCharacter.generated.h"

UCLASS(config=Game)
class ATP_ThirdPersonCharacter : public ACharacter //конструктор, выполн€етс€ при создании объекта
{
	GENERATED_BODY()

public:
	ATP_ThirdPersonCharacter();

	/**ќбъ€вл€ем методы движени€ вперед-назад, влево-вправо и прыжки*/
	void MoveForward(float Axis); 
	void MoveRight(float Axis);
	void Jump();
	void StopJumping();

	/*ћетод который вызываетс€ в начале игры*/
	virtual void BeginPlay() override; 
	/*ћетод который вызываетс€ во врем€ игры */
	virtual void Tick(float DeltaTime) override;  
	/*„тобы подключать компоненты которые управл€ют персонажем*/
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override; 

	/*ќбъ€вл€ем переменную дл€ св€зки с кнопкой рандомного определени€ кол-ва ходов от 1 до 6*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int RandKub; 
	/*ќбъ€вл€ем переменную дл€ рандомного определени€ первого ходившего*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool RandHod;
	/*ќбъ€вл€ем переменную дл€ опредени€ нажата ли кнопка или нет*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool ClickButton;
	/*ќбъ€вл€ем переменную дл€ блокировки кнопки во врем€ хода */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool BlockButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Winner; 

	/*хранит ссылку на мир (Gubka Bob)*/
	UPROPERTY()
		const UObject* world;

	/*массив где будут хранитьс€ все экторы класса бубок, <тип>*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<AActor*> VseBub;

	/**хранит указатель на класс бубок*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<class AActor> NahoditClass;

	void FindArray();


};


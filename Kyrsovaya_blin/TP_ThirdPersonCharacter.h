// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Containers/Array.h"
#include "UObject/Object.h"
#include "TP_ThirdPersonCharacter.generated.h"

UCLASS(config=Game)
class ATP_ThirdPersonCharacter : public ACharacter //�����������, ����������� ��� �������� �������
{
	GENERATED_BODY()

public:
	ATP_ThirdPersonCharacter();

	/**��������� ������ �������� ������-�����, �����-������ � ������*/
	void MoveForward(float Axis); 
	void MoveRight(float Axis);
	void Jump();
	void StopJumping();

	/*����� ������� ���������� � ������ ����*/
	virtual void BeginPlay() override; 
	/*����� ������� ���������� �� ����� ���� */
	virtual void Tick(float DeltaTime) override;  
	/*����� ���������� ���������� ������� ��������� ����������*/
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override; 

	/*��������� ���������� ��� ������ � ������� ���������� ����������� ���-�� ����� �� 1 �� 6*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int RandKub; 
	/*��������� ���������� ��� ���������� ����������� ������� ���������*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool RandHod;
	/*��������� ���������� ��� ��������� ������ �� ������ ��� ���*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool ClickButton;
	/*��������� ���������� ��� ���������� ������ �� ����� ���� */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool BlockButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Winner; 

	/*������ ������ �� ��� (Gubka Bob)*/
	UPROPERTY()
		const UObject* world;

	/*������ ��� ����� ��������� ��� ������ ������ �����, <���>*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<AActor*> VseBub;

	/**������ ��������� �� ����� �����*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<class AActor> NahoditClass;

	void FindArray();


};


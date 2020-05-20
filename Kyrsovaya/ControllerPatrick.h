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
	
		/*PlayerTick- �-� ������� ����� ���������� ������ ���� (��� ��� ���� � ������ �� ������)*/
	virtual void Tick(float DeltaTime) override;   
	virtual void BeginPlay() override;
	

	/*������ ������ �� ��� (Gubka Bob)*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		const UObject* world;

	/*���������� ����������, ������� ������ ����� ����� �� ������� ����� ��������*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int OldPozition;

	/*���������� ����������, ������� ������ ����� ����� �� ������� ������ ��������*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int NewPozition;

	/*����� �������� ��������� �� ����� ��������, ��� ����*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<class ACharacter> FindMyPawn;
	
	/*����� �������� ������ �� �����*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		 ATP_ThirdPersonCharacter* TPC;

	/*�-�, ������� ����� ������ � ������ �������(��������� ���������)*/
	void FindMainCharacter();
	bool MoveComplete();



};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "SpongeBob.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "Containers/Array.h"
#include "GameFramework/PlayerController.h"
#include "ControllerSpongeBob.generated.h"


UCLASS()
class PROJECT1_API AControllerSpongeBob : public AAIController
{
	GENERATED_BODY()
public:
	AControllerSpongeBob();
	
	/*PlayerTick- �-� ������� ����� ���������� ������ ���� (��� ��� ���� � ������ �� ������)*/
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;

	/*������ ������ �� ���������, ������ ����� ��������� ���� ����������*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ASpongeBob* SBob;

	/*������ ������ �� ��� (Gubka Bob)*/
	UPROPERTY()
		const UObject* world;

	/*����� �������� ��������� �� ����� ��������, ��� ����*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<class ACharacter> FindMyPawn;
	/*����� �������� ������ �� �����*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ATP_ThirdPersonCharacter* TPC;
	
	/*���������� ����������, ������� ������ ����� ����� �� ������� ����� ��������*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int OldPozition;
	/*���������� ����������, ������� ������ ����� ����� �� ������� ������ ��������*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int NewPozition;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Swin;


	/*�-�, ������� ����� ������ � ������ �������(��������� ���������)*/
	void FindMainCharacter();

	
};

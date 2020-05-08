// Fill out your copyright notice in the Description page of Project Settings.

#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "EngineUtils.h"
#include "Kismet/KismetSystemLibrary.h"
#include "ControllerPatrick.h"


AControllerPatrick::AControllerPatrick() {

	/*���� ����� �� ������� ����*/
	//UWorld* FindWorld =ConstructorHelpers::FObjectFinder<UWorld>(TEXT("/Game/ThirdPersonBP/Maps/Gubka_Bob.Gubka_Bob")).Object;
	/*cast ����� ���� ������������ �� FindWorld � ��������*/
	world = Cast<UObject>(GetWorld());


	/*������������� ����������*/
	OldPozition = 0;
	NewPozition = 0;

	/*������� ����� ��������, ��������� ���������*/
	static ConstructorHelpers::FClassFinder<ACharacter> PwClass(TEXT("/Game/DECORACII/Moi_character/Animation_MOI/Patric/MyTP_ThirdPersonCharacter"));
	/*����������� ���������� FindMyPawn ������ �� ����� ������� ����� */
	FindMyPawn = PwClass.Class;
	


}


/*����� ������� ���������� � ������ ����*/
void AControllerPatrick::BeginPlay() {
	/*� ������������� ������ �������� ���� �����*/
	Super::BeginPlay();			

	/* � ���������� SPat �������� ������ �� �������*/
	SPat = Cast<APatrick>(GetCharacter());				
}

/*�����, ������� ���������� �� ����� ����*/
void AControllerPatrick::Tick(float DeltaTime) {
	//Super - �������� ����� � �������� 
	Super::Tick(DeltaTime);	

	FindMainCharacter(); //����� ���������

	/* ���� �������� �������*//*���-�� ����� �� ����� 0*//*����  ��� �������*/
	if ((TPC != NULL) && (TPC->VseBub.Num() != 0) && (TPC->RandHod) && (TPC->Winner == false)) {
		/*���� ������ ������ */
		if ((TPC->ClickButton) && (TPC->RandKub != 0)) {

			NewPozition += TPC->RandKub;
			TPC->ClickButton = false;
			/*��������� ������*/
			TPC->BlockButton = true;
		}
		/*���� �������� ������� =0, ������ �� ����� � ��� ����� ����// OldPozition < NewPozition - ������������ �� ������ ������� ����*/
		else if ((TPC->RandKub != 0) && (TPC->BlockButton) && (SPat->GetVelocity().IsZero())) {
			
			if (OldPozition == TPC->VseBub.Num()) { //���� ������� ����� ��������� �� ������ ������� 
				TPC->Winner = true;
			}

			if ((OldPozition < NewPozition) && (TPC->Winner ==false)) {
				/*���� ������ ��� �� OldPozition-��� �����*/
				UAIBlueprintHelperLibrary::SimpleMoveToActor(this, TPC->VseBub[OldPozition]);
				OldPozition++;
			}
			else if (OldPozition == NewPozition) { //���� ��� �����, ������ ������ ������ �� ������ �����
				TPC->RandKub = 0;
				TPC->RandHod = false; //� ��� ��������� ����� ����
				TPC->BlockButton = false; //������ �������������� 
			}
			
		
	}
	}
}


/*������� ������� ���� ��������� ��������� � ������ ���������*/
void AControllerPatrick::FindMainCharacter() {
	//���� ������ ��� �� ����
	if (TPC == NULL) {
		/*������*/
		TArray<AActor*> Out;
		/*����� � ����, � ������ FindMyPawn ��������� ���������, � �.�. �� 1, �� ������ 0*/
		UGameplayStatics::GetAllActorsOfClass(world, FindMyPawn, Out);
		if (Out.Num()!=0) { //Num- ���-�� ���������
		TPC = Cast<ATP_ThirdPersonCharacter>(Out[0]);
		}
	}
}

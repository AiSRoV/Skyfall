// Fill out your copyright notice in the Description page of Project Settings.

#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "EngineUtils.h"
#include "ControllerSpongeBob.h"

AControllerSpongeBob::AControllerSpongeBob() {
	


	/*������� ����� ��������, ��������� ���������*/
	static ConstructorHelpers::FClassFinder<ACharacter> PwClass(TEXT("/Game/DECORACII/Moi_character/Animation_MOI/Patric/MyTP_ThirdPersonCharacter"));
	/*����������� ���������� FindMyPawn ������ �� ����� ������� ����� */
	FindMyPawn = PwClass.Class;
	
	/*� world ���� ������ (�����), ����� ��������� ������ �� ��� � ������� ����-�� �����*/
/*cast ����� ���� ������������ �� �������� � ��������*/
	world = Cast<UObject>(GetWorld());

	/*������������� ����������*/
	OldPozition = 0;
	NewPozition = 0;

}


/*����� ������� ���������� � ������ ����*/
void AControllerSpongeBob::BeginPlay() {
	/*� ������������� ������ �������� ���� �����*/
	Super::BeginPlay();

	/* � ���������� SBob �������� ������ �� ����� ����*/
	SBob = Cast<ASpongeBob>(GetCharacter());

}


/*�����, ������� ���������� �� ����� ����*/
void AControllerSpongeBob::Tick(float DeltaTime) {
	//Super - �������� ����� � �������� 
	Super::Tick(DeltaTime);
	
	FindMainCharacter(); //����� ���������

	if ((TPC != NULL) && (TPC->VseBub.Num() != 0) && (TPC->RandHod==false) && (TPC->Winner == false)) {
		
		/*���� ������ ������*/
		if ((TPC->ClickButton) && (TPC->RandKub != 0)) {

			NewPozition += TPC->RandKub;
			TPC->ClickButton = false;
			/*��������� ������*/  
			TPC->BlockButton = true;
		}
		/*���� �������� ������ =0, ������ �� ����� � ��� ����� ����// OldPozition < NewPozition - ������������ �� ������ ������� ����*/
		else if ((TPC->RandKub != 0) && (TPC->BlockButton) && (SBob->GetVelocity().IsZero())) {
			if (OldPozition == TPC->VseBub.Num()) { //���� ������� ����� ��������� �� ����� ������� 

				TPC->Winner = true;
			}
			if (OldPozition < NewPozition && TPC->Winner == false) {
				/*���� ������ ��� �� OldPozition-��� �����*/
				UAIBlueprintHelperLibrary::SimpleMoveToActor(this, TPC->VseBub[OldPozition]);
				OldPozition++;
			}
			else if (OldPozition == NewPozition) { //���� ��� �����, ������ Sponge ������ �� ������ �����
				TPC->RandKub = 0;
				TPC->RandHod = true; //� ��� ��������� �������
				TPC->BlockButton = false; //������ �������������� 
			}
			 
		}
	}
}


/*������� ������� ���� ��������� ��������� � ������ ���������*/
void AControllerSpongeBob::FindMainCharacter() {
	//���� ������ ��� �� ����
	if (TPC == NULL) {
		/*������*/
		TArray<AActor*> Out;
		/*����� � ����, � ������ FindMyPawn ��������� ���������, � �.�. �� 1, �� ������ 0*/
		UGameplayStatics::GetAllActorsOfClass(world, FindMyPawn, Out);
		if (Out.Num() != NULL) { //Num- ���-�� ���������
			TPC = Cast<ATP_ThirdPersonCharacter>(Out[0]);
		}
	}
}


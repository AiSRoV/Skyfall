// Fill out your copyright notice in the Description page of Project Settings.

#include "ControllerPatrick.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "EngineUtils.h"
#include "Kismet/KismetSystemLibrary.h"



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

			
}

/*�����, ������� ���������� �� ����� ����*/
void AControllerPatrick::Tick(float DeltaTime) {
	//Super - �������� ����� � �������� 
	Super::Tick(DeltaTime);	

	FindMainCharacter(); //����� ���������
	if ((TPC != NULL) && (TPC->RandHod) && (TPC->Winner == false) && (TPC->sort)) {

		/*���� ������ ������*/
		if ((TPC->ClickButton) && (TPC->RandKub != 0)) {

			NewPozition += TPC->RandKub;
			TPC->ClickButton = false;
			/*��������� ������*/
			TPC->BlockButton = true;
		}
		/*���� �������� ������ =0, ������ �� ����� � ��� ����� ����// OldPozition < NewPozition - ������������ �� ������ ������� ����*/
		else if ((TPC->RandKub != 0) && (TPC->BlockButton) && (GetCharacter()->GetVelocity().IsZero())) {
			
			if (OldPozition == TPC->VseBub.Num()-1 && MoveComplete()) { //���� ������� ����� ��������� �� ������ ������� 

				TPC->Winner = true;
			}
			if (TPC->Winner == false) {
				/*���� ������ ��� �� OldPozition-��� �����*/
				UAIBlueprintHelperLibrary::SimpleMoveToActor(this, TPC->VseBub[OldPozition]);

			}
			if (OldPozition < NewPozition - 1 && TPC->Winner == false && MoveComplete()) {
				OldPozition++;
			}
			else if (OldPozition == NewPozition-1 && MoveComplete()) { //���� ��� �����, ������ ������ ������ �� ������ �����
				TPC->RandKub = 0;
				if (NewPozition != TPC->VseBub.Num()) {
					TPC->RandHod = false; //� ��� ��������� �����
				}
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

bool AControllerPatrick::MoveComplete() {
	FVector Dist = GetCharacter()->GetActorLocation() - TPC->VseBub[OldPozition]->GetActorLocation();
	
	if (Dist.Size() < 1000.0f) {
		return true;
	}

	return false;

}
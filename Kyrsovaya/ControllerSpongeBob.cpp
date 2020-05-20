// Fill out your copyright notice in the Description page of Project Settings.

#include "ControllerSpongeBob.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "EngineUtils.h"

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

}


/*�����, ������� ���������� �� ����� ����*/
void AControllerSpongeBob::Tick(float DeltaTime) {
	//Super - �������� ����� � �������� 
	Super::Tick(DeltaTime);
	
	FindMainCharacter(); //����� ���������

	if ((TPC != NULL) && (TPC->RandHod==false) && (TPC->Winner == false)&&(TPC->sort)) {
		
		/*���� ������ ������*/
		if ((TPC->ClickButton) && (TPC->RandKub != 0)) {

			NewPozition += TPC->RandKub;
			TPC->ClickButton = false;
			/*��������� ������*/  
			TPC->BlockButton = true;
		}
		/*���� �������� ������ =0, ������ �� ����� � ��� ����� ����// OldPozition < NewPozition - ������������ �� ������ ������� ����*/
		else if ((TPC->RandKub != 0) && (TPC->BlockButton) && (GetCharacter()->GetVelocity().IsZero())) {
		//	Check = MoveComplete();
			if (OldPozition == TPC->VseBub.Num() - 1 && MoveComplete()) { //���� ������� ����� ��������� �� ����� ������� 

				TPC->Winner = true;   
			}
			if (TPC->Winner == false) {
				/*���� ������ ��� �� OldPozition-��� �����*/
				UAIBlueprintHelperLibrary::SimpleMoveToActor(this, TPC->VseBub[OldPozition]);
				
			}
			if (OldPozition < NewPozition-1 && TPC->Winner == false && MoveComplete())  {
			OldPozition++;
			}
			else if (OldPozition == NewPozition-1 && MoveComplete()) { //���� ��� �����, ������ Sponge ������ �� ������ �����
				TPC->RandKub = 0;
				if (NewPozition != TPC->VseBub.Num()) {
					TPC->RandHod = true; //� ��� ��������� �������
				}
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

bool AControllerSpongeBob::MoveComplete() {
	FVector Dist = GetCharacter()->GetActorLocation() - TPC->VseBub[OldPozition]->GetActorLocation();
	
	if (Dist.Size()<1000.0f)  {
		return true;
	}

	return false; 

}
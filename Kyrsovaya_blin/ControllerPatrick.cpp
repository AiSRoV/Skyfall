// Fill out your copyright notice in the Description page of Project Settings.

#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "EngineUtils.h"
#include "Kismet/KismetSystemLibrary.h"
#include "ControllerPatrick.h"


AControllerPatrick::AControllerPatrick() {

	/*ищет карту на которой игра*/
	//UWorld* FindWorld =ConstructorHelpers::FObjectFinder<UWorld>(TEXT("/Game/ThirdPersonBP/Maps/Gubka_Bob.Gubka_Bob")).Object;
	/*cast пишем чтоб преобразовал из FindWorld в юобджект*/
	world = Cast<UObject>(GetWorld());


	/*Инициализация переменных*/
	OldPozition = 0;
	NewPozition = 0;

	/*находит класс керектер, корневого персонажа*/
	static ConstructorHelpers::FClassFinder<ACharacter> PwClass(TEXT("/Game/DECORACII/Moi_character/Animation_MOI/Patric/MyTP_ThirdPersonCharacter"));
	/*присваиваем переменной FindMyPawn ссылку на класс который нашли */
	FindMyPawn = PwClass.Class;
	


}


/*Метод который вызывается в начале игры*/
void AControllerPatrick::BeginPlay() {
	/*у родительского класса вызываем этот метод*/
	Super::BeginPlay();			

	/* в переменной SPat хранится ссылка на партика*/
	SPat = Cast<APatrick>(GetCharacter());				
}

/*метод, который вызывается во время игры*/
void AControllerPatrick::Tick(float DeltaTime) {
	//Super - вызываем метод у родителя 
	Super::Tick(DeltaTime);	

	FindMainCharacter(); //нашли персонажа

	/* если персонаж нашелся*//*кол-во бубок не равно 0*//*если  ход Патрика*/
	if ((TPC != NULL) && (TPC->VseBub.Num() != 0) && (TPC->RandHod) && (TPC->Winner == false)) {
		/*если нажата кнопка */
		if ((TPC->ClickButton) && (TPC->RandKub != 0)) {

			NewPozition += TPC->RandKub;
			TPC->ClickButton = false;
			/*Блокируем кнопку*/
			TPC->BlockButton = true;
		}
		/*если скорость патрика =0, значит он стоит и ему можно идти// OldPozition < NewPozition - ограничитель до какого момента идти*/
		else if ((TPC->RandKub != 0) && (TPC->BlockButton) && (SPat->GetVelocity().IsZero())) {
			
			if (OldPozition == TPC->VseBub.Num()) { //если позиция равна последней то Патрик победил 
				TPC->Winner = true;
			}

			if ((OldPozition < NewPozition) && (TPC->Winner ==false)) {
				/*чтоб Патрик шел на OldPozition-тую бубку*/
				UAIBlueprintHelperLibrary::SimpleMoveToActor(this, TPC->VseBub[OldPozition]);
				OldPozition++;
			}
			else if (OldPozition == NewPozition) { //если они равны, значит патрик пришел на нужное место
				TPC->RandKub = 0;
				TPC->RandHod = false; //и ход переходит спанч бобу
				TPC->BlockButton = false; //кнопка разблокируется 
			}
			
		
	}
	}
}


/*функция которая ищет корневого персонажа в классе керектерс*/
void AControllerPatrick::FindMainCharacter() {
	//если ничего нет то ищем
	if (TPC == NULL) {
		/*массив*/
		TArray<AActor*> Out;
		/*поиск в мире, в классе FindMyPawn корневого персонажа, а т.к. он 1, то индекс 0*/
		UGameplayStatics::GetAllActorsOfClass(world, FindMyPawn, Out);
		if (Out.Num()!=0) { //Num- кол-во элементов
		TPC = Cast<ATP_ThirdPersonCharacter>(Out[0]);
		}
	}
}

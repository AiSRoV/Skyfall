// Fill out your copyright notice in the Description page of Project Settings.

#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "EngineUtils.h"
#include "ControllerSpongeBob.h"

AControllerSpongeBob::AControllerSpongeBob() {
	


	/*находит класс керектер, корневого персонажа*/
	static ConstructorHelpers::FClassFinder<ACharacter> PwClass(TEXT("/Game/DECORACII/Moi_character/Animation_MOI/Patric/MyTP_ThirdPersonCharacter"));
	/*присваиваем переменной FindMyPawn ссылку на класс который нашли */
	FindMyPawn = PwClass.Class;
	
	/*в world ищем экторы (бубки), здесь находится ссылка на мир в котором осущ-ся поиск*/
/*cast пишем чтоб преобразовал из гетворлд в юобджект*/
	world = Cast<UObject>(GetWorld());

	/*Инициализация переменных*/
	OldPozition = 0;
	NewPozition = 0;

}


/*Метод который вызывается в начале игры*/
void AControllerSpongeBob::BeginPlay() {
	/*у родительского класса вызываем этот метод*/
	Super::BeginPlay();

	/* в переменной SBob хранится ссылка на спанч боба*/
	SBob = Cast<ASpongeBob>(GetCharacter());

}


/*метод, который вызывается во время игры*/
void AControllerSpongeBob::Tick(float DeltaTime) {
	//Super - вызываем метод у родителя 
	Super::Tick(DeltaTime);
	
	FindMainCharacter(); //нашли персонажа

	if ((TPC != NULL) && (TPC->VseBub.Num() != 0) && (TPC->RandHod==false) && (TPC->Winner == false)) {
		
		/*если нажата кнопка*/
		if ((TPC->ClickButton) && (TPC->RandKub != 0)) {

			NewPozition += TPC->RandKub;
			TPC->ClickButton = false;
			/*Блокируем кнопку*/  
			TPC->BlockButton = true;
		}
		/*если скорость спанча =0, значит он стоит и ему можно идти// OldPozition < NewPozition - ограничитель до какого момента идти*/
		else if ((TPC->RandKub != 0) && (TPC->BlockButton) && (SBob->GetVelocity().IsZero())) {
			if (OldPozition == TPC->VseBub.Num()) { //если позиция равна последней то Губка победил 

				TPC->Winner = true;
			}
			if (OldPozition < NewPozition && TPC->Winner == false) {
				/*чтоб Патрик шел на OldPozition-тую бубку*/
				UAIBlueprintHelperLibrary::SimpleMoveToActor(this, TPC->VseBub[OldPozition]);
				OldPozition++;
			}
			else if (OldPozition == NewPozition) { //если они равны, значит Sponge пришел на нужное место
				TPC->RandKub = 0;
				TPC->RandHod = true; //и ход переходит патрику
				TPC->BlockButton = false; //кнопка разблокируется 
			}
			 
		}
	}
}


/*функция которая ищет корневого персонажа в классе керектерс*/
void AControllerSpongeBob::FindMainCharacter() {
	//если ничего нет то ищем
	if (TPC == NULL) {
		/*массив*/
		TArray<AActor*> Out;
		/*поиск в мире, в классе FindMyPawn корневого персонажа, а т.к. он 1, то индекс 0*/
		UGameplayStatics::GetAllActorsOfClass(world, FindMyPawn, Out);
		if (Out.Num() != NULL) { //Num- кол-во элементов
			TPC = Cast<ATP_ThirdPersonCharacter>(Out[0]);
		}
	}
}


// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "TP_ThirdPersonCharacter.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"


/**конструктор, вызывается при создании объекта*/
ATP_ThirdPersonCharacter::ATP_ThirdPersonCharacter() 
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(130.f, 280.0f);
	/**Включаем тик(процесс игры)*/
	PrimaryActorTick.bCanEverTick = true;

	/**настраиваем мувмент компонент,*/
	/** автоматический поворот персонажа в сторону его движения*/
	GetCharacterMovement()->bOrientRotationToMovement = true;  
	/**Скорость поворота персонажа*//*FRotator() имеет 3 переменные XYZ*/ /*RotationRate расположение поворота*/
	GetCharacterMovement()->RotationRate = FRotator(0.0f,540.0f,0.0f);
	/**Высота прыжка*/
	GetCharacterMovement()->JumpZVelocity = 700.0f;
	/**насколько мы контролируем персонажа когда летит*/
	GetCharacterMovement()->AirControl = 0.2f;
	/*максимальная скорость*/
	GetCharacterMovement()->MaxWalkSpeed = 670.0f; 
	/*максимальный угол на который будет подниматься*/
	GetCharacterMovement()->SetWalkableFloorAngle(35);

	/*Инициализируем переменную для опредения нажата ли кнопка или нет*/
	ClickButton = false;
	/*Инициализируем переменную для блокировки кнопки во время хода */
	BlockButton = false;
	 
	/*Рандом для определния кто 1й ходит*/
	RandHod = UKismetMathLibrary::RandomBool();

	RandKub = 0;
	
	Winner = false;
	
	/*в world ищем экторы (бубки), здесь находится ссылка на мир в котором осущ-ся поиск*/
	/*cast пишем чтоб преобразовал из гетворлд в юобджект*/
	world = Cast<UObject>(GetWorld());
	static ConstructorHelpers::FClassFinder<AActor> FindClass(TEXT("/Game/DECORACII/Bbb/MyBuba"));
	/*присваиваем переменной NahoditClass ссылку на класс который нашли */
	NahoditClass = FindClass.Class;
}



void ATP_ThirdPersonCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	/*управление мышкой, поворот камеры*/
	/*поворот мыши в лево-право*/
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	/*поворот мыши в вверх-вниз*/
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	/*прыжок и остановка прыжка*/
	/**IE_Pressed- при нажатии, & - указали ссылку на пространство имет Jump'а*/
	/*когда мы нажимает спейс(джамп) срабатывает метод Jump*/
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ATP_ThirdPersonCharacter::Jump);
	/*когда не нажимаем срабатывает метот стопджампинг*/
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ATP_ThirdPersonCharacter::StopJumping);

	/**движение вперед-назад и влево-вправо */
	PlayerInputComponent->BindAxis("MoveForward", this, &ATP_ThirdPersonCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ATP_ThirdPersonCharacter::MoveRight);



}


/**Инициализируем методы движения вперед-назад, влево-вправо и прыжки*/
void ATP_ThirdPersonCharacter::MoveForward(float Axis)
{	/*контроллер должен существовать*/ /*кнопка нажата*/
	if ((Controller!=NULL)&&(Axis!=0.0f))
	{  /**получаем угол направления камеры по оси Yaw */
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0.0, Rotation.Yaw, 0.0);
		
		/**Рассчитываем вектор(направление) движение и задаем движение  */
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
			AddMovementInput(Direction, Axis);
	}
}

void ATP_ThirdPersonCharacter::MoveRight(float Axis)
{
	if ((Controller != NULL) && (Axis != 0.0f))
		
	{
		/**получаем угол направления камеры по оси Yaw */
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0.0, Rotation.Yaw, 0.0);

		/**Рассчитываем вектор(направление) движение и задаем движение  */
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Axis);
	}
}

void ATP_ThirdPersonCharacter::Jump()
{
	if (Controller != NULL)
	{
		ACharacter::Jump();

	}
}

void ATP_ThirdPersonCharacter::StopJumping()
{
	ACharacter::StopJumping();
}

/*Метод который вызывается в начале игры*/
void ATP_ThirdPersonCharacter::BeginPlay() {
	Super::BeginPlay();


}

/*Метод который вызывается во время игры */
void ATP_ThirdPersonCharacter::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	FindArray();
}


/*функция которая ищет все экземпляры бубочного класса  и сортирует элементы*/
void ATP_ThirdPersonCharacter::FindArray() {
	//если ничего нет то ищем
	if (VseBub.Num() == 0) {
		/* находим массив бубок*/
		UGameplayStatics::GetAllActorsOfClass(world, NahoditClass, VseBub);
		/*если нашли, сортируем*/
		if (VseBub.Num() != 0) {
			for (int i = 0; i < VseBub.Num(); i++) {
				for (int j = 0; j < VseBub.Num() - i - 1; j++) {
					if (UKismetSystemLibrary::GetDisplayName(VseBub[j]).Len() > UKismetSystemLibrary::GetDisplayName(VseBub[j + 1]).Len()) {
						VseBub.Swap(j, j + 1);
					}
					else if ((UKismetSystemLibrary::GetDisplayName(VseBub[j]).Len() == UKismetSystemLibrary::GetDisplayName(VseBub[j + 1]).Len()) && (UKismetSystemLibrary::GetDisplayName(VseBub[j]).Compare(UKismetSystemLibrary::GetDisplayName(VseBub[j + 1]), ESearchCase::CaseSensitive)) > 0) {
						VseBub.Swap(j, j + 1);
					}


				}
			}
		}
	}
}
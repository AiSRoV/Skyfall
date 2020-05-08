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


/**�����������, ���������� ��� �������� �������*/
ATP_ThirdPersonCharacter::ATP_ThirdPersonCharacter() 
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(130.f, 280.0f);
	/**�������� ���(������� ����)*/
	PrimaryActorTick.bCanEverTick = true;

	/**����������� ������� ���������,*/
	/** �������������� ������� ��������� � ������� ��� ��������*/
	GetCharacterMovement()->bOrientRotationToMovement = true;  
	/**�������� �������� ���������*//*FRotator() ����� 3 ���������� XYZ*/ /*RotationRate ������������ ��������*/
	GetCharacterMovement()->RotationRate = FRotator(0.0f,540.0f,0.0f);
	/**������ ������*/
	GetCharacterMovement()->JumpZVelocity = 700.0f;
	/**��������� �� ������������ ��������� ����� �����*/
	GetCharacterMovement()->AirControl = 0.2f;
	/*������������ ��������*/
	GetCharacterMovement()->MaxWalkSpeed = 670.0f; 
	/*������������ ���� �� ������� ����� �����������*/
	GetCharacterMovement()->SetWalkableFloorAngle(35);

	/*�������������� ���������� ��� ��������� ������ �� ������ ��� ���*/
	ClickButton = false;
	/*�������������� ���������� ��� ���������� ������ �� ����� ���� */
	BlockButton = false;
	 
	/*������ ��� ���������� ��� 1� �����*/
	RandHod = UKismetMathLibrary::RandomBool();

	RandKub = 0;
	
	Winner = false;
	
	/*� world ���� ������ (�����), ����� ��������� ������ �� ��� � ������� ����-�� �����*/
	/*cast ����� ���� ������������ �� �������� � ��������*/
	world = Cast<UObject>(GetWorld());
	static ConstructorHelpers::FClassFinder<AActor> FindClass(TEXT("/Game/DECORACII/Bbb/MyBuba"));
	/*����������� ���������� NahoditClass ������ �� ����� ������� ����� */
	NahoditClass = FindClass.Class;
}



void ATP_ThirdPersonCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	/*���������� ������, ������� ������*/
	/*������� ���� � ����-�����*/
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	/*������� ���� � �����-����*/
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	/*������ � ��������� ������*/
	/**IE_Pressed- ��� �������, & - ������� ������ �� ������������ ���� Jump'�*/
	/*����� �� �������� �����(�����) ����������� ����� Jump*/
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ATP_ThirdPersonCharacter::Jump);
	/*����� �� �������� ����������� ����� ������������*/
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ATP_ThirdPersonCharacter::StopJumping);

	/**�������� ������-����� � �����-������ */
	PlayerInputComponent->BindAxis("MoveForward", this, &ATP_ThirdPersonCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ATP_ThirdPersonCharacter::MoveRight);



}


/**�������������� ������ �������� ������-�����, �����-������ � ������*/
void ATP_ThirdPersonCharacter::MoveForward(float Axis)
{	/*���������� ������ ������������*/ /*������ ������*/
	if ((Controller!=NULL)&&(Axis!=0.0f))
	{  /**�������� ���� ����������� ������ �� ��� Yaw */
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0.0, Rotation.Yaw, 0.0);
		
		/**������������ ������(�����������) �������� � ������ ��������  */
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
			AddMovementInput(Direction, Axis);
	}
}

void ATP_ThirdPersonCharacter::MoveRight(float Axis)
{
	if ((Controller != NULL) && (Axis != 0.0f))
		
	{
		/**�������� ���� ����������� ������ �� ��� Yaw */
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0.0, Rotation.Yaw, 0.0);

		/**������������ ������(�����������) �������� � ������ ��������  */
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

/*����� ������� ���������� � ������ ����*/
void ATP_ThirdPersonCharacter::BeginPlay() {
	Super::BeginPlay();


}

/*����� ������� ���������� �� ����� ���� */
void ATP_ThirdPersonCharacter::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	FindArray();
}


/*������� ������� ���� ��� ���������� ��������� ������  � ��������� ��������*/
void ATP_ThirdPersonCharacter::FindArray() {
	//���� ������ ��� �� ����
	if (VseBub.Num() == 0) {
		/* ������� ������ �����*/
		UGameplayStatics::GetAllActorsOfClass(world, NahoditClass, VseBub);
		/*���� �����, ���������*/
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
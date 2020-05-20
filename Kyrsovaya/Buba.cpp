// Fill out your copyright notice in the Description page of Project Settings.

#include "Buba.h"
#include "UObject/ConstructorHelpers.h"
#include "Project1.h"


// Sets default values
ABuba::ABuba()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Bubka = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	//RootComponent = Bubka; 
	//sMesh - ���������� ��� ������ ��������
	Col = CreateDefaultSubobject<UBoxComponent>(TEXT("Coliz"));
	SetRootComponent(Col);//��� ����� 
	Bubka->AttachTo(Col);//��������� � ���������
	Col->InitBoxExtent(FVector(20.0f, 19.0f, 2.0f)); //������ ������
	UStaticMesh* sMesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/StarterContent/Materials/BUBOCHKA.BUBOCHKA'")).Object; //����� ������� ��� ������ FObjectFinder �� ������� �������� ��������� ������� � ����������
	UMaterialInterface* myMat = ConstructorHelpers::FObjectFinder<UMaterialInterface>(TEXT("Material'/Game/DECORACII/Bbb/MatirialForMyBuba.MatirialForMyBuba'")).Object; //������� �������� � ������� 
	if (sMesh != NULL) { Bubka->SetStaticMesh(sMesh); } 
	
	Bubka->SetMaterial(0, myMat);
	
	index = 0;


}


// Called when the game starts or when spawned
void ABuba::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABuba::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


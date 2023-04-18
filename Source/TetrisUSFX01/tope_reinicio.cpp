// Fill out your copyright notice in the Description page of Project Settings.


#include "Block.h"
#include "tope_reinicio.h"

// extras
#include"Components/BoxComponent.h"
#include"Kismet/GameplayStatics.h"
#include"Board.h"

// Called when the game starts or when spawned
void Atope_reinicio::BeginPlay()
{
	Super::BeginPlay();

	Box_Collision->OnComponentBeginOverlap.AddDynamic(this, &Atope_reinicio::OnOverlapBegin);

	referencs_reinico = Cast<ABoard>(
		UGameplayStatics::GetPlayerController(GetWorld(), 200));
	
}

void Atope_reinicio::OnOverlapBegin(UPrimitiveComponent* OverlappeComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType, bool bFromSweep, const FHitResult& SweepResult)
{

	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()));
	if (OtherActor->ActorHasTag("cubo")) {
	OtherActor->Destroy();

		referencs_reinico->reiniciar_nivl();
		UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()));
	}
}

// Called every frame
void Atope_reinicio::Tick(float Atope_reinicio)
{
	Super::Tick(Atope_reinicio);

}


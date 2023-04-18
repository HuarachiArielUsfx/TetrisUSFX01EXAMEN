// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "tope_reinicio.generated.h"

UCLASS()
class TETRISUSFX01_API Atope_reinicio : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	// Sets default values
	Atope_reinicio()
	{
		// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
		PrimaryActorTick.bCanEverTick = true, false;


		Box_Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
		RootComponent = Box_Collision;

	}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UBoxComponent* Box_Collision;



	UFUNCTION()

		void OnOverlapBegin(class UPrimitiveComponent* OverlappeComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndexType, bool bFromSweep, const FHitResult& SweepResult);



	// referencia para llamar a la funcion de reinicion 

	class ABoard* referencs_reinico;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};




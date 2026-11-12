// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainCharacter_CPP.generated.h"

UCLASS()
class PLATAFORMAS2_5D_API AMainCharacter_CPP : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter_CPP();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override; //override es solo informativo //virtual hace que priorice la función heredada

public:	
	UPROPERTY(EditAnywhere, Category = Components); //Necesario para que se pueda cambiar desde el editor(como SerializeField)
	UCameraComponent *camera;
	UPROPERTY(EditAnywhere, Category = Input);
	UInputMappingContext *myInputMapping;
	UPROPERTY(EditAnywhere, Category = Input);
	UInputAction *moveAction;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Move(const FInputActionValue &value);
};

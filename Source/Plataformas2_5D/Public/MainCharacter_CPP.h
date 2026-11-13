//Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "MainCharacter_CPP.generated.h"

//class UCameraComponent; //referencia blanda (no incluye el codigo, solo funciona en este codigo)
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS() //Macro
class PLATAFORMAS2_5D_API AMainCharacter_CPP : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter_CPP();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override; //override es solo informativo
	//virtual hace que se priorice la funcion heredada

public:	
	UPROPERTY(EditAnywhere, Category = Components)
	UCameraComponent* Camera;
	UPROPERTY(EditAnywhere, Category = Inputs)
	UInputMappingContext* mappingContext;
	UPROPERTY(EditAnywhere, Category = Inputs)
	UInputAction* moveAction;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override; //Sirve para setear los input
	
	void Move(const FInputActionValue& value);

};

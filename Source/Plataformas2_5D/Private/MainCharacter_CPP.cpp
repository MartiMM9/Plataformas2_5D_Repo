// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter_CPP.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Camera/CameraComponent.h"

// Sets default values
AMainCharacter_CPP::AMainCharacter_CPP()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	camera = CreateDefaultSubobject<UCameraComponent>("MyCamera");
	camera->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AMainCharacter_CPP::BeginPlay()
{
	Super::BeginPlay(); //Super es para llamar a la función original, no heredada
	APlayerController *playerController = Cast<APlayerController>(Controller); //Controller es una clase estática de Unreal que se crea al iniciar el juego
	if (playerController != nullptr) //IsValid(playerController)
	{
		UEnhancedInputLocalPlayerSubsystem *subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(playerController->GetLocalPlayer());
		if (subsystem != nullptr)
		{
			subsystem->AddMappingContext(myInputMapping, 1);
		}
	}
}

// Called every frame
void AMainCharacter_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainCharacter_CPP::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent *enhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (enhancedInputComponent == nullptr)
	{
		return;
	}
	enhancedInputComponent->BindAction(moveAction, ETriggerEvent::Triggered, this, &AMainCharacter_CPP::Move);
}

void AMainCharacter_CPP::Move(const FInputActionValue& value)
{
	float inputValue = value.Get<float>();
	AddMovementInput(FVector(inputValue, 0,0));
}


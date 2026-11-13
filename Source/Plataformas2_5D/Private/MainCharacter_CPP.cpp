// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter_CPP.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

// Sets default values
AMainCharacter_CPP::AMainCharacter_CPP()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera"); //Crear un objeto en Unreal
	Camera->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AMainCharacter_CPP::BeginPlay()
{
	Super::BeginPlay(); //Super sirve para llamar a la funcion original (necesario en Unreal)
	//Asignamos el PlayerController
	APlayerController* playerController = Cast<APlayerController>(Controller);
	if (!IsValid(playerController))
	{
		return;
	}
	//Asignamos el EnhancedInputLocalPlayerSubsystem
	UEnhancedInputLocalPlayerSubsystem* subsystem = 
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(playerController->GetLocalPlayer());
	if (!IsValid(subsystem))
	{
		return;
	}
	//Añadimos el Mapping Context
	subsystem->AddMappingContext(mappingContext, 0);
	
	//UE_Log(LogTemp, Log, TEXT("Antonio halcon patina mogollon")); //Es un log que aparece en la consola
	//GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Antonio halcon patina mogollon")); //Es el print string de blueprints
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
	UEnhancedInputComponent* enhancedComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (!IsValid(enhancedComponent))
	{
		return;
	}
	enhancedComponent->BindAction(moveAction, ETriggerEvent::Triggered, this, &AMainCharacter_CPP::Move);
}

void AMainCharacter_CPP::Move(const FInputActionValue& value)
{
	float inputValue = value.Get<float>();
	AddMovementInput(FVector(inputValue, 0,0));
}


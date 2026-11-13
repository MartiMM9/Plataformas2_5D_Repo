// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase_CPP.h"

AMyGameModeBase_CPP::AMyGameModeBase_CPP()
{
	//Buscamos el archivo del player en las carpetas
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawn
	(TEXT("/Game/BlueprintsCPP/MainCharacter_CPP_BP"));
	if (PlayerPawn.Class != NULL)
	{
		DefaultPawnClass = PlayerPawn.Class;
	}
}

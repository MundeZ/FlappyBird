// Fill out your copyright notice in the Description page of Project Settings.


#include "Levels/MenuPlayerController.h"

void AMenuPlayerController::BeginPlay()
{
    Super::BeginPlay();

    SetInputMode(FInputModeUIOnly());
    bShowMouseCursor = true;
}
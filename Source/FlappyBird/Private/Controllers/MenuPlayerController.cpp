// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/MenuPlayerController.h"

void AMenuPlayerController::BeginPlay()
{
    Super::BeginPlay();

    // Включаем курсор
    SetInputMode(FInputModeUIOnly());
    bShowMouseCursor = true;
}
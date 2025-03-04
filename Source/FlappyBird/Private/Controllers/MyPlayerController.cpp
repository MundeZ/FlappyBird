// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/MyPlayerController.h"

#include "GameFramework/GameUserSettings.h"

void AMyPlayerController::BeginPlay()
{
    Super::BeginPlay();

    UGameUserSettings* Settings = GEngine->GetGameUserSettings();
    if (Settings)
    {
        Settings->SetScreenResolution(FIntPoint(1280, 720));
        Settings->SetFullscreenMode(EWindowMode::Windowed);
        Settings->ApplySettings(true);
    }
}
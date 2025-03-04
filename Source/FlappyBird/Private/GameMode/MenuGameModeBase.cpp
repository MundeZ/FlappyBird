// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/MenuGameModeBase.h"

#include "Controllers/MenuPlayerController.h"
#include "UI/HUD/MenuHUD.h"

AMenuGameModeBase::AMenuGameModeBase()
{
    PlayerControllerClass = AMenuPlayerController::StaticClass();
    HUDClass = AMenuHUD::StaticClass();
}
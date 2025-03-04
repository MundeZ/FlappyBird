// Fill out your copyright notice in the Description page of Project Settings.


#include "Levels/MenuGameModeBase.h"

#include "Levels/MenuPlayerController.h"
#include "UI/MenuHUD.h"

AMenuGameModeBase::AMenuGameModeBase()
{
    PlayerControllerClass = AMenuPlayerController::StaticClass();
    HUDClass = AMenuHUD::StaticClass();
}
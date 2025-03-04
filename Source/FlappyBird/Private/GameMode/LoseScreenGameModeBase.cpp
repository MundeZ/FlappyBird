// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/LoseScreenGameModeBase.h"

#include "UI/HUD/LoseScreenHUD.h"

ALoseScreenGameModeBase::ALoseScreenGameModeBase()
{
    HUDClass = ALoseScreenHUD::StaticClass();
}
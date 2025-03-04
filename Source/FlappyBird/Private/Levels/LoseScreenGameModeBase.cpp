// Fill out your copyright notice in the Description page of Project Settings.


#include "Levels/LoseScreenGameModeBase.h"

#include "UI/LoseScreenHUD.h"

ALoseScreenGameModeBase::ALoseScreenGameModeBase()
{
    HUDClass = ALoseScreenHUD::StaticClass();
}
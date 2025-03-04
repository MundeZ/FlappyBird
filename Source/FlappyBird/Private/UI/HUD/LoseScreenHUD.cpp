// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/LoseScreenHUD.h"

#include "Blueprint/UserWidget.h"

void ALoseScreenHUD::BeginPlay()
{
    Super::BeginPlay();

    if (LoseScreenWidgetClass)
    {
        const auto MenuWidget = CreateWidget<UUserWidget>(GetWorld(), LoseScreenWidgetClass);
        if (MenuWidget)
        {
            MenuWidget->AddToViewport();
        }
    }
}
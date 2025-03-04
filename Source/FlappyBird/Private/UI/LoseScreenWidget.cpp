// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/LoseScreenWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void ULoseScreenWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (RestartButton)
    {
        RestartButton->OnClicked.AddDynamic(this, &ULoseScreenWidget::OnRestart);
    }
    else
    {
        UE_LOG(LogTemp, Display, TEXT("Not found RestartButton"))
    }
}

void ULoseScreenWidget::OnRestart()
{
    const FName LevelName = "NewMap";

    UGameplayStatics::OpenLevel(GetWorld(), LevelName);
}
// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MainMenuWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UMainMenuWidget::NativeConstruct()
{
    Super::NativeConstruct();
    if (StartGameButton)
    {
        StartGameButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnStartGame);
    }
    else
    {
        UE_LOG(LogTemp, Display, TEXT("Not found StartGameButton"))
    }

    if (ExitButton)
    {
        ExitButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnExit);
    }

}

void UMainMenuWidget::OnStartGame()
{

    const FName LevelName = "NewMap";

    UGameplayStatics::OpenLevel(GetWorld(), LevelName);

}

void UMainMenuWidget::OnExit()
{
    if (GetWorld())
    {
        UGameplayStatics::SetGamePaused(GetWorld(), false);
        UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Quit, false);
    }
    else
    {
        UE_LOG(LogTemp, Display, TEXT("Not found World"))
    }
}
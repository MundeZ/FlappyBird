// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MainMenuWidget.h"
#include "Components/Button.h"
#include "Components/MySaveGame.h"
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

    LoadAndDisplayScores();
    GetHighScore();
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

void UMainMenuWidget::LoadAndDisplayScores()
{
    UMySaveGame* SaveGameInstance = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("ScoreSlot"), 0));

    if (!SaveGameInstance)
    {
        UE_LOG(LogTemp, Warning, TEXT("SaveGame not found, creating new one."));
        SaveGameInstance = NewObject<UMySaveGame>();
    }

    int32 ScoresToShow = 10;
    int32 StartIndex = FMath::Max(0, SaveGameInstance->Scores.Num() - ScoresToShow);

    FString ScoreText;
    for (int32 i = SaveGameInstance->Scores.Num() - 1; i >= StartIndex; i--)
    {
        ScoreText += FString::Printf(TEXT("%d\n"), SaveGameInstance->Scores[i]);
    }

    if (ScoreTextBlock)
    {
        ScoreTextBlock->SetText(FText::FromString(ScoreText));
    }
}

void UMainMenuWidget::GetHighScore()
{
    UMySaveGame* SaveGameInstance = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("ScoreSlot"), 0));

    if (!SaveGameInstance || SaveGameInstance->Scores.Num() == 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("SaveGame not found or empty."));
        if (HightScoreTextBlock)
        {
            HightScoreTextBlock->SetText(FText::FromString(TEXT("High score: 0")));
        }
        return;
    }

    // Найти максимальный результат
    const int32 HighScore = FMath::Max<int32>(SaveGameInstance->Scores);

    if (HightScoreTextBlock)
    {
        HightScoreTextBlock->SetText(FText::FromString(FString::Printf(TEXT("High score: %d"), HighScore)));
    }
}

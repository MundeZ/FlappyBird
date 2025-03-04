#include "UI/LoseScreenWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "Components/MySaveGame.h"

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

    if (ExitButton)
    {
        ExitButton->OnClicked.AddDynamic(this, &ULoseScreenWidget::OnExit);
    }
    else
    {
        UE_LOG(LogTemp, Display, TEXT("Not found ExitButton"))
    }

    if (ReturnToMainMenuButton)
    {
        ReturnToMainMenuButton->OnClicked.AddDynamic(this, &ULoseScreenWidget::OnReturnToMainMenu);
    }

    LoadAndDisplayLastScore();
}

void ULoseScreenWidget::OnRestart()
{
    const FName LevelName = "NewMap";
    UGameplayStatics::OpenLevel(GetWorld(), LevelName);
}

void ULoseScreenWidget::OnExit()
{
    if (GetWorld())
    {
        UGameplayStatics::SetGamePaused(GetWorld(), false);
        UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Quit, false);
    }
}

void ULoseScreenWidget::OnReturnToMainMenu()
{
    UGameplayStatics::OpenLevel(GetWorld(), "MenuLevel");
}

void ULoseScreenWidget::LoadAndDisplayLastScore()
{
    UMySaveGame* SaveGameInstance = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("ScoreSlot"), 0));

    if (!SaveGameInstance || SaveGameInstance->Scores.Num() == 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("SaveGame not found or no scores available."));
        return;
    }

    int32 LastScore = SaveGameInstance->Scores.Last();

    if (ScoreTextBlock)
    {
        ScoreTextBlock->SetText(FText::FromString(FString::Printf(TEXT("Your score: %d"), LastScore)));
    }
}
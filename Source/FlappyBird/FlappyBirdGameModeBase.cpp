#include "FlappyBirdGameModeBase.h"

#include "Character/MainCharacter.h"
#include "Character/MyPlayerController.h"
#include "Kismet/GameplayStatics.h"

AFlappyBirdGameModeBase::AFlappyBirdGameModeBase()
{
    DefaultPawnClass = AMainCharacter::StaticClass();
    PlayerControllerClass = AMyPlayerController::StaticClass();
    SetGameState(EFlappyBirdGameState::EGameState_WaitingToStart);
}

void AFlappyBirdGameModeBase::StartPlay()
{
    Super::StartPlay();
}

void AFlappyBirdGameModeBase::SetGameState(EFlappyBirdGameState NewGameState)
{
    if (GameState == NewGameState) return;

    GameState = NewGameState;
    HandleStateChange();
}

void AFlappyBirdGameModeBase::HandleStateChange()
{
    switch (GameState)
    {
    case EFlappyBirdGameState::EGameState_WaitingToStart:
        UE_LOG(LogTemp, Display, TEXT("Game is Waiting to Start"));
    // Здесь можно показать начальное меню
        break;

    case EFlappyBirdGameState::EGameState_InPlaying:
        UE_LOG(LogTemp, Display, TEXT("Game is Playing"));
    // Снимаем паузу (разморозить мир)
        UGameplayStatics::SetGamePaused(GetWorld(), false);
        break;

    case EFlappyBirdGameState::EGameState_Pause:
        UE_LOG(LogTemp, Display, TEXT("Game is Paused"));
    // Останавливаем время
        UGameplayStatics::SetGamePaused(GetWorld(), true);
        break;

    case EFlappyBirdGameState::EGameState_GameOver:
        UE_LOG(LogTemp, Display, TEXT("Game Over"));
    // Здесь можно показать экран Game Over
        break;

    default:
        break;
    }
}

void AFlappyBirdGameModeBase::StartGame()
{
    SetGameState(EFlappyBirdGameState::EGameState_InPlaying);
    UE_LOG(LogTemp, Display, TEXT("Game Started!"));
}

void AFlappyBirdGameModeBase::PauseGame()
{
    // Если игра уже на паузе, то мы её снимаем
    if (GameState == EFlappyBirdGameState::EGameState_Pause)
    {
        SetGameState(EFlappyBirdGameState::EGameState_InPlaying);
    }
    else
    {
        SetGameState(EFlappyBirdGameState::EGameState_Pause);
    }
}

void AFlappyBirdGameModeBase::GameOver()
{
    SetGameState(EFlappyBirdGameState::EGameState_GameOver);
    UE_LOG(LogTemp, Display, TEXT("Game Over Triggered"));
    // Здесь можно добавить перезапуск игры или переход в главное меню
}
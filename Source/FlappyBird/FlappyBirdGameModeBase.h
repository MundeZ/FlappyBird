#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FlappyBirdGameModeBase.generated.h"

// Возможные состояния игры
UENUM(BlueprintType)
enum class EFlappyBirdGameState : uint8
{
    EGameState_WaitingToStart, // Ожидание старта
    EGameState_InPlaying, // Игра идет
    EGameState_Pause, // Игра на паузе
    EGameState_GameOver // Конец игры
};

UCLASS()
class FLAPPYBIRD_API AFlappyBirdGameModeBase : public AGameModeBase
{
    GENERATED_BODY()

public:
    AFlappyBirdGameModeBase();

    virtual void StartPlay() override;

    // Установить новое состояние игры
    UFUNCTION(BlueprintCallable, Category = "GameMode")
    void SetGameState(EFlappyBirdGameState NewGameState);

    // Получить текущее состояние игры
    UFUNCTION(BlueprintPure, Category = "GameMode")
    EFlappyBirdGameState GetGameState() const { return GameState; }

    UPROPERTY(EditDefaultsOnly, Category = "UI")
    TSubclassOf<class UMainMenuWidget> MainMenuClass;

    // Специальные действия
    UFUNCTION(BlueprintCallable, Category = "GameMode")
    void StartGame();

    UFUNCTION(BlueprintCallable, Category = "GameMode")
    void PauseGame();

    UFUNCTION(BlueprintCallable, Category = "GameMode")
    void GameOver();

private:
    EFlappyBirdGameState GameState = EFlappyBirdGameState::EGameState_WaitingToStart;
    void HandleStateChange();
};
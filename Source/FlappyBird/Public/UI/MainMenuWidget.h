// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"

class UButton;
class UTextBlock;
class UMySaveGame;

UCLASS()
class FLAPPYBIRD_API UMainMenuWidget : public UUserWidget
{
    GENERATED_BODY()

protected:
    UPROPERTY(meta=(BindWidget))
    UButton* StartGameButton;

    UPROPERTY(meta=(BindWidget))
    UButton* ExitButton;

    UPROPERTY(meta=(BindWidget))
    UTextBlock* HightScoreTextBlock;

    UPROPERTY(meta=(BindWidget))
    UTextBlock* ScoreTextBlock;
    
    UMySaveGame* SaveGameInstance;
    
    virtual void NativeConstruct() override;

private:
    UFUNCTION()
    void OnStartGame();

    UFUNCTION()
    void OnExit();

    void LoadScore();
    void LoadAndDisplayScores();
    void GetHighScore();
};
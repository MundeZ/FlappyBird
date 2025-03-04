// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "MainMenuWidget.generated.h"

class UButton;

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
    
    virtual void NativeConstruct() override;

private:
    UFUNCTION()
    void OnStartGame();

    UFUNCTION()
    void OnExit();
    void LoadAndDisplayScores();
    void GetHighScore();
};
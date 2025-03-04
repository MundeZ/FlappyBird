// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"

class UButton;

UCLASS()
class FLAPPYBIRD_API UMainMenuWidget : public UUserWidget
{
    GENERATED_BODY()

protected:
    UPROPERTY(meta=(BindWidget))
    UButton* StartGameButton;
    
    virtual void NativeConstruct() override;

private:
    UFUNCTION()
    void OnStartGame();
};
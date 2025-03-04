// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LoseScreenWidget.generated.h"

class UButton;

UCLASS()
class FLAPPYBIRD_API ULoseScreenWidget : public UUserWidget
{
    GENERATED_BODY()

protected:
    UPROPERTY(meta=(BindWidget))
    UButton* RestartButton;

    virtual void NativeConstruct() override;

private:
    UFUNCTION()
    void OnRestart();
};
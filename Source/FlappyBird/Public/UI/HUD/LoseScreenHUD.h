// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "LoseScreenHUD.generated.h"


UCLASS()
class FLAPPYBIRD_API ALoseScreenHUD : public AHUD
{
    GENERATED_BODY()

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> LoseScreenWidgetClass;

    virtual void BeginPlay() override;
};
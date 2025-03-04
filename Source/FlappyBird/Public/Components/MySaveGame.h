// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "MySaveGame.generated.h"


UCLASS()
class FLAPPYBIRD_API UMySaveGame : public USaveGame
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadWrite, Category= "SaveGame")
    TArray<int32> Scores;
};
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class FLAPPYBIRD_API AMyPlayerController : public APlayerController
{
    virtual void BeginPlay() override;
    GENERATED_BODY()
};
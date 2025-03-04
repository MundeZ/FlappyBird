// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelGenerator.generated.h"

UCLASS()
class FLAPPYBIRD_API ALevelGenerator : public AActor
{
    GENERATED_BODY()

public:
    ALevelGenerator();
    
    void UpdateLevelGeneration(const FVector& CameraPosition);

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Level Generator")
    TArray<TSubclassOf<AActor>> LevelData;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Level Generation")
    float Spacing = 30.0f;

    virtual void BeginPlay() override;

private:
    FVector CurrentSpawnPosition;
    TArray<AActor*> SpawnedActors;

    void GenerateLevel();
};
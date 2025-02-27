// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "MyCharacterMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class FLAPPYBIRD_API UMyCharacterMovementComponent : public UCharacterMovementComponent
{
    GENERATED_BODY()
    
public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Movement", meta=(ClampMin="1.5", ClampMax="100.0"))
    float MaxSpeed = 3.0f;
    
};
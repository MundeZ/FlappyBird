// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "MyCharacterMovementComponent.generated.h"

UCLASS()
class FLAPPYBIRD_API UMyCharacterMovementComponent : public UCharacterMovementComponent
{
    GENERATED_BODY()

public:
    virtual void BeginPlay() override;
    virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement", meta = (ClampMin = "0.0", ClampMax = "1000.0"))
    float MaxSpeed = 450.0f;

private:
    AActor* Owner = GetOwner();
    void LockMoveByX();
    void MoveForward(float DeltaTime);
};
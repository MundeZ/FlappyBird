// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/HealthComponent.h"


UHealthComponent::UHealthComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

bool UHealthComponent::IsDead() const
{
    return FMath::IsNearlyZero(Health);
}

float UHealthComponent::GetHealth() const
{
    return Health;
}

float UHealthComponent::MinusHP(float Amount)
{
    Health -= Amount;
    return Health;
}
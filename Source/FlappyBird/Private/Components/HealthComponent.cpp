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

void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UHealthComponent::BeginPlay()
{
    Super::BeginPlay();
}
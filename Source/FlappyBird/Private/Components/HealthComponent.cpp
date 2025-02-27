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


void UHealthComponent::BeginPlay()
{
    Super::BeginPlay();
}


void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UHealthComponent::OnTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy,
                                       AActor* DamageCauser)
{

}
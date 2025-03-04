// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/MyCharacterMovementComponent.h"


void UMyCharacterMovementComponent::BeginPlay()
{
    Super::BeginPlay();
    LockMoveByX();
}

void UMyCharacterMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    MoveForward(DeltaTime);
}

void UMyCharacterMovementComponent::LockMoveByX() // Ограничиваем движение по оси X
{
    if (!Owner) { return; }
    FVector CurrentLocation = GetOwner()->GetActorLocation();
    CurrentLocation.X = 0.0f;
    Owner->SetActorLocation(CurrentLocation);
}

void UMyCharacterMovementComponent::MoveForward(float DeltaTime) // Постоянное движение вперед
{
    if (!Owner) { return; }
    const FVector ForwardMovement = FVector(0.0f, MaxSpeed * DeltaTime, 0.0f);
    Owner->AddActorWorldOffset(ForwardMovement, true);
}
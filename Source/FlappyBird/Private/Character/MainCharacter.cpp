// Fill out your copyright notice in the Description page of Project Settings.

#include "FlappyBird/Public/Character/MainCharacter.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
    Super::BeginPlay();

}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}
// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/BaseCharacter.h"

#include "Components/MyCharacterMovementComponent.h"


ABaseCharacter::ABaseCharacter(const FObjectInitializer& ObjInit): Super(
    ObjInit.SetDefaultSubobjectClass<UMyCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{

    PrimaryActorTick.bCanEverTick = true;

    GetCharacterMovement()->GravityScale = 1.0f;
    FlipbookComponent = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("FlipbookComponent"));
    FlipbookComponent->SetupAttachment(RootComponent);
}


void ABaseCharacter::BeginPlay()
{
    Super::BeginPlay();

}


void ABaseCharacter::Jump()
{
    const auto MovementComponent = Cast<UMyCharacterMovementComponent>(GetCharacterMovement());
    if (MovementComponent)
    {
        UE_LOG(LogTemp, Warning, TEXT("Jumping!"));
        Super::Jump();
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Cannot jump: character is falling. 2"));
    }
}

void ABaseCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

void ABaseCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    check(PlayerInputComponent);

    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ABaseCharacter::Jump);
}
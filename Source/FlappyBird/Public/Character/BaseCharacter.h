// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PaperFlipbookComponent.h"
#include "BaseCharacter.generated.h"

UCLASS()
class FLAPPYBIRD_API ABaseCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    ABaseCharacter(const FObjectInitializer& ObjInit);

protected:
    virtual void BeginPlay() override;

public:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
    UPaperFlipbookComponent* FlipbookComponent;

    virtual void Jump() override;
    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
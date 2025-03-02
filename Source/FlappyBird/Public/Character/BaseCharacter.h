// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

class ALevelGenerator;
class USpringArmComponent;
class UPaperFlipbookComponent;
class UCameraComponent;

UCLASS()
class FLAPPYBIRD_API ABaseCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    ABaseCharacter(const FObjectInitializer& ObjInit);

    virtual void Jump() override;
    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Components")
    UPaperFlipbookComponent* FlipbookComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USpringArmComponent* SpringArmComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UCameraComponent* CameraComponent;

    virtual void BeginPlay() override;

private:
    ALevelGenerator* LevelGenerator;
};

// Убрать хардкод.
// Перенести движение вперед и прыжок в movement component.
// Убрать лишние include.
// Для level generator добавить новый массив. 1 - хранит объекты для спавна на крыше 2- хранит объекты для спавна на полу (Нужно переворачивать деревья).
// Добавить спавн крыши и пола.(Сейчас объекты поставлены вручную).
// Запретить передвижение по оси Х.
// Исправить ошибку, при которой камера ломается, если между камерой и персонажем есть объект.

// Если птичка прыгает - спрайт поднимается, если птичка падает, спрайт опускается.

// Лидерборд. 

// Меню игры.

// Написать readme

// Собрать игру, и залить на google диск, что бы можно было скачать не собирая проект.
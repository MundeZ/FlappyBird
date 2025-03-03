#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

// Предварительные декларации для указателей
class ALevelGenerator;
class USpringArmComponent;
class UPaperFlipbookComponent;
class UCameraComponent;
class UBoxComponent; // Не хватает объявления этого компонента в вашем коде

UCLASS()
class FLAPPYBIRD_API ABaseCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    ABaseCharacter(const FObjectInitializer& ObjInit);

    // Обработка оверлапа
    UFUNCTION()
    void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
                        bool bFromSweep, const FHitResult& SweepResult);

    virtual void Tick(float DeltaTime) override;
    virtual void Jump() override;
    virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

protected:
    virtual void BeginPlay() override;

    // Компоненты
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UPaperFlipbookComponent* FlipbookComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USpringArmComponent* SpringArmComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UCameraComponent* CameraComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collision")
    UBoxComponent* CollisionBox;

private:
    // Генератор уровня
    ALevelGenerator* LevelGenerator;
};
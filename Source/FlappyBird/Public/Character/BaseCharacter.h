#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"


class ALevelGenerator;
class UHealthComponent;
class USpringArmComponent;
class UPaperFlipbookComponent;
class UCameraComponent;
class UBoxComponent;
class UTextRenderComponent;

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
    void SaveNewScore(float NewScore);
    virtual void Tick(float DeltaTime) override;
    virtual void Jump() override;
    void SetInputMode(const FInputModeUIOnly& InputModeUIOnly);
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

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UHealthComponent* HealthComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UTextRenderComponent* HealthTextComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collision")
    UBoxComponent* CollisionBox;

private:
    ALevelGenerator* LevelGenerator;
    int32 JumpCount = 0;
};
#include "Character/BaseCharacter.h"
#include "PaperFlipbookComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/MyCharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Levels/LevelGenerator.h"
#include "Engine/World.h"
#include "EngineUtils.h"

ABaseCharacter::ABaseCharacter(const FObjectInitializer& ObjInit)
    : Super(ObjInit.SetDefaultSubobjectClass<UMyCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
    PrimaryActorTick.bCanEverTick = true;

    GetCharacterMovement()->GravityScale = 1.0f;

    FlipbookComponent = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("FlipbookComponent"));
    FlipbookComponent->SetupAttachment(RootComponent);

    SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
    SpringArmComponent->SetupAttachment(GetRootComponent());
    SpringArmComponent->bUsePawnControlRotation = true;
    SpringArmComponent->SocketOffset = FVector(0.0f, 100.0f, 80.0f);

    CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
    CameraComponent->SetupAttachment(SpringArmComponent);
}

void ABaseCharacter::BeginPlay()
{
    Super::BeginPlay();

    FlipbookComponent->SetSimulatePhysics(true);
    FlipbookComponent->BodyInstance.bLockXTranslation = true;
    FlipbookComponent->BodyInstance.bLockYTranslation = true;
    FlipbookComponent->BodyInstance.bLockZTranslation = true;

    // Автоматически ищем LevelGenerator, если он не задан вручную
    if (!LevelGenerator)
    {
        for (TActorIterator<ALevelGenerator> It(GetWorld()); It;)
        {
            LevelGenerator = *It;
            break;
        }

        if (LevelGenerator)
        {
            UE_LOG(LogTemp, Display, TEXT("LevelGenerator found: %s"), *LevelGenerator->GetName());
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("LevelGenerator not found!"));
        }
    }
}

void ABaseCharacter::Jump()
{
    const auto MovementComponent = Cast<UMyCharacterMovementComponent>(GetCharacterMovement());
    if (MovementComponent)
    {
        FlipbookComponent->BodyInstance.SetLinearVelocity(FVector::UpVector * 600.0f, true);
        UE_LOG(LogTemp, Warning, TEXT("Jumping!"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Cannot jump: character is falling."));
    }
    Super::Jump();
}

void ABaseCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Смещение персонажа вперёд
    const FVector ForwardMovement = FVector(0.0f, 90.0f * DeltaTime, 0.0f);
    AddActorWorldOffset(ForwardMovement, true);

    // Получение позиции камеры (через SpringArm)
    FVector CameraPos = SpringArmComponent->GetComponentLocation();
    if (CameraPos == FVector::ZeroVector) return;

    // Обновление генерации уровня
    if (LevelGenerator)
    {
        LevelGenerator->UpdateLevelGeneration(CameraPos);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("LevelGenerator is nullptr!"));
    }
}

void ABaseCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    check(PlayerInputComponent);

    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ABaseCharacter::Jump);
}
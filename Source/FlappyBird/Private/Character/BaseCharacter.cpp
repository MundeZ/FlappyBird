#include "Character/BaseCharacter.h"
#include "PaperFlipbookComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/MyCharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Levels/LevelGenerator.h"
#include "EngineUtils.h"
#include "Components/BoxComponent.h"

ABaseCharacter::ABaseCharacter(const FObjectInitializer& ObjInit): Super(
    ObjInit.SetDefaultSubobjectClass<UMyCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
    PrimaryActorTick.bCanEverTick = true;

    // Создаём FlipbookComponent
    FlipbookComponent = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("FlipbookComponent"));
    FlipbookComponent->SetupAttachment(RootComponent);

    // Добавляем SpringArm
    SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
    SpringArmComponent->SetupAttachment(RootComponent);
    SpringArmComponent->bUsePawnControlRotation = true;
    SpringArmComponent->SocketOffset = FVector(0.0f, 100.0f, 80.0f);

    // Добавляем Камеру
    CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
    CameraComponent->SetupAttachment(SpringArmComponent);

    // Добавляем BoxComponent для коллизии
    CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
    CollisionBox->SetupAttachment(RootComponent);
    CollisionBox->SetBoxExtent(FVector(40.0f, 40.0f, 40.0f));
    CollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    CollisionBox->SetCollisionObjectType(ECollisionChannel::ECC_Pawn);
    CollisionBox->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
    CollisionBox->SetGenerateOverlapEvents(true);

    // Привязываем обработку события оверлапа
    CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ABaseCharacter::OnOverlapBegin);
}

void ABaseCharacter::BeginPlay()
{
    Super::BeginPlay();

    FlipbookComponent->SetSimulatePhysics(true);
    FlipbookComponent->SetEnableGravity(true);
    GetCharacterMovement()->GravityScale = 1.0f;

    FlipbookComponent->BodyInstance.bLockXTranslation = true;
    FlipbookComponent->BodyInstance.bLockYTranslation = true;
    FlipbookComponent->BodyInstance.bLockZTranslation = false;

    // Автоматический поиск генератора уровня
    if (!LevelGenerator)
    {
        for (TActorIterator<ALevelGenerator> It(GetWorld()); It; ++It)
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

void ABaseCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Ограничиваем движение по оси X
    FVector CurrentLocation = GetActorLocation();
    CurrentLocation.X = 0.0f;
    SetActorLocation(CurrentLocation);

    // Перемещение персонажа вперёд
    const FVector ForwardMovement = FVector(0.0f, 450.0f * DeltaTime, 0.0f);
    AddActorWorldOffset(ForwardMovement, true);

    // Обновляем уровень
    if (LevelGenerator)
    {
        FVector CameraPos = SpringArmComponent->GetComponentLocation();
        if (CameraPos != FVector::ZeroVector)
        {
            LevelGenerator->UpdateLevelGeneration(CameraPos);
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("LevelGenerator is nullptr!"));
    }
}

void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    check(PlayerInputComponent);
    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ABaseCharacter::Jump);
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

void ABaseCharacter::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                                    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
                                    bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherActor && OtherActor != this) // Проверяем, чтобы это не был сам персонаж
    {
        UE_LOG(LogTemp, Warning, TEXT("HIT! Overlapped with: %s"), *OtherActor->GetName());
    }
}
#include "Levels/LevelGenerator.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"

ALevelGenerator::ALevelGenerator()
{
    PrimaryActorTick.bCanEverTick = true;
    CurrentSpawnPosition = FVector::ZeroVector;
}

void ALevelGenerator::BeginPlay()
{
    Super::BeginPlay();

    if (GetWorld())
    {
        // Получаем расположение начального спавна, основываясь на расположении игрока
        FVector PlayerLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
        CurrentSpawnPosition = PlayerLocation + FVector(0.0f, Spacing, 0.0f);
        UE_LOG(LogTemp, Display, TEXT("Initial Spawn Position set to: %s"), *CurrentSpawnPosition.ToString());
    }

    // Запускаем первую генерацию уровня
    GenerateLevel();
}

void ALevelGenerator::GenerateLevel()
{
    if (LevelData.Num() == 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("No level prefabs found in LevelData!"));
        return;
    }

    // Выбираем случайный префаб для генерации
    int32 RandomIndex = FMath::RandRange(0, LevelData.Num() - 1);
    TSubclassOf<AActor> SelectedPrefab = LevelData[RandomIndex];

    if (SelectedPrefab)
    {
        UWorld* World = GetWorld();
        if (World)
        {
            FActorSpawnParameters SpawnParams;
            AActor* SpawnedActor = World->SpawnActor<AActor>(
                SelectedPrefab,
                CurrentSpawnPosition,
                FRotator::ZeroRotator,
                SpawnParams
            );

            if (SpawnedActor)
            {
                // Увеличиваем позицию спавна для следующего объекта
                CurrentSpawnPosition.Y += Spacing; 
                SpawnedActors.Add(SpawnedActor);

                UE_LOG(LogTemp, Display, TEXT("Spawned actor at: %s"), *CurrentSpawnPosition.ToString());
            }
        }
    }
}

void ALevelGenerator::UpdateLevelGeneration(const FVector& CameraPosition)
{
    // Убираем актёров, которые оказались слишком далеко за камерой
    for (AActor* Actor : SpawnedActors)
    {
        if (Actor && Actor->GetActorLocation().Y < CameraPosition.Y - Spacing * 3)
        {
            UE_LOG(LogTemp, Display, TEXT("Destroying actor at: %s"), *Actor->GetActorLocation().ToString());
            Actor->Destroy();
            SpawnedActors.Remove(Actor);
            break;
        }
    }

    // Проверяем, нужно ли добавить новый объект перед камерой
    if (CameraPosition.Y > CurrentSpawnPosition.Y - Spacing * 2)
    {
        UE_LOG(LogTemp, Display, TEXT("Adding new actor. Camera Position: %s, Next Spawn Position: %s"),
            *CameraPosition.ToString(), *CurrentSpawnPosition.ToString()
        );
        GenerateLevel();
    }
}

void ALevelGenerator::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
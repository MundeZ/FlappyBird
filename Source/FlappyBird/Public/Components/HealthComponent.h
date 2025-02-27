// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class FLAPPYBIRD_API UHealthComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UHealthComponent();

    float GetHealth() const;
    bool IsDead() const;
    bool IsHealthFull() const;
    bool IsHealthZero() const;

    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Health", meta=(ClampMin="0.0", ClampMax="100.0"))
    float MaxHealth = 100.0f;

    virtual void BeginPlay() override;

private:
    float Health = 100.0f;

    UFUNCTION(Category="Health")
    void OnTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy,
                         AActor* DamageCauser);
};
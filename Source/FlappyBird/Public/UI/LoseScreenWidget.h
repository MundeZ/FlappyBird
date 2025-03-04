#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"  
#include "LoseScreenWidget.generated.h"

class UButton;

UCLASS()
class FLAPPYBIRD_API ULoseScreenWidget : public UUserWidget
{
    GENERATED_BODY()

protected:
    UPROPERTY(meta=(BindWidget))
    UButton* RestartButton;

    UPROPERTY(meta=(BindWidget))
    UButton* ExitButton;
    
    UPROPERTY(meta=(BindWidget))
    UTextBlock* ScoreTextBlock;  

    virtual void NativeConstruct() override;

private:
    UFUNCTION()
    void OnRestart();

    UFUNCTION()
    void OnExit();

    void LoadAndDisplayScores();
    void LoadAndDisplayLastScore();
};
// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"

// Sets default values
AItem::AItem() : Score(0)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	if (ScoreTextWidget)
	{

		pScoreTextWidget = CreateWidget<UUserWidget>(GetGameInstance(), ScoreTextWidget);
			
		if (pScoreTextWidget.IsValid())
		{
			//Con el puntero esta añadiendo el widget al viewport
			pScoreTextWidget-> AddToViewport();

			pScoreText = (UTextBlock*)pScoreTextWidget->GetWidgetFromName("ScoreText");
		}
	}
	
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItem::IncreaseScore(int amount)
{
	// Increase the score and update the text widget
	if (pScoreText.IsValid()) {
		Score += amount;
		pScoreText->SetText(FText::FromString(FString::FromInt(Score)));
	}
}

int AItem::GetScore() const 
{
	return Score;
}



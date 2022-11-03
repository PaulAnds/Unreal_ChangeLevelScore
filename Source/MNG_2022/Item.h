// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class MNG_2022_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<class UUserWidget> ScoreTextWidget;
	TWeakObjectPtr<class UUserWidget> pScoreTextWidget;
	TWeakObjectPtr<class UTextBlock> pScoreText;
	TWeakObjectPtr<class UTextBlock> pPullsText;
	TWeakObjectPtr<class UTextBlock> pShotsText;

	// Exposed function to Blueprints
	UFUNCTION(BlueprintCallable, Category = "Score")
	void IncreaseScore(int amount);

	UFUNCTION(BlueprintCallable, Category = "Pulls")
		void DecreasePulls(int amount);

	UFUNCTION(BlueprintCallable, Category = "Shots")
		void DecreaseShots(int amount);

	UFUNCTION(BlueprintCallable, Category = "Shots")
	void ResetShots();

	UFUNCTION(BlueprintCallable, Category = "Pulls")
	void ResetPulls();

	UFUNCTION(BlueprintCallable, Category = "Score")
	int GetScore() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	int Score;
	int Pulls;
	int Shots;
};

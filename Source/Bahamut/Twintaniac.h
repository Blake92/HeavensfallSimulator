// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NPCc.h"
#include "Twintaniac.generated.h"

/**
 * 
 */
UCLASS()
class BAHAMUT_API ATwintaniac : public ANPCc
{
	GENERATED_BODY()

public:

	void twister();
	UFUNCTION(BlueprintCallable)
	void dive();
	UFUNCTION()
	void spawnTWI();

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AActor> twisterACT;

private:

	FTransform pos;
	
	
};

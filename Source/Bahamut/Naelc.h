// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NPCc.h"
#include "Naelc.generated.h"

/**
 * 
 */
UCLASS()
class BAHAMUT_API ANaelc : public ANPCc
{
	GENERATED_BODY()

public:

	FVector randomloc(float, float, float, float);
	UFUNCTION(blueprintcallable)
	void Towers();
	UFUNCTION(blueprintcallable)
	void Heavensfall();
	UFUNCTION(blueprintcallable)
	void AOE();
	UFUNCTION()
	void delay();

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AActor> TowersACT;
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AActor> HeavenACT;


	
};

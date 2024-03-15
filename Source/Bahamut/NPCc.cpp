// Fill out your copyright notice in the Description page of Project Settings.


#include "NPCc.h"

// Sets default values
ANPCc::ANPCc()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANPCc::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANPCc::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANPCc::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


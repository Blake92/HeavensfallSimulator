// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NPCc.h"
#include "BahamutC.generated.h"


UCLASS()
class BAHAMUT_API ABahamutC : public ANPCc
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABahamutC();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void dive();

	UFUNCTION(BlueprintCallable)
	void heavensfall();


	// takes a templated array of any type and randomizes it
	template < class t>
	void randomize(TArray < t* >&);
	void randomizeINT(int*);

	FVector radomloc(float , float);


private:

	int Angle[8] = { 0,45,90,135,180,225,270,315 }; // array containing the possible positions (in angle degrees) to teleport enemies around the circumference of the arena ring



};

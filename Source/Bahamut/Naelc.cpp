// Fill out your copyright notice in the Description page of Project Settings.


#include "Naelc.h"
#include <Kismet/GameplayStatics.h>

FVector ANaelc::randomloc(float x, float y , float radiusx, float radiusy)
{
	x = FMath::DegreesToRadians(x);
	y = FMath::DegreesToRadians(y);
	float x1 = cos(x) * radiusx;  
	float y1 = sin(y) * radiusy;  
	FVector loc(x1, y1, 10);
	return loc;
}

void ANaelc::Towers()
{
	
	FTransform tran; 
	TArray<AActor*> towarr;
	for (int i = 0; i < 8; i++)  // spwan 8 towers in in a random location within the arena, if they overlap move them and retry
	{
		float x = rand() % 359;
		FVector randloc = randomloc(x, x, 2200, 2200);
		tran.SetLocation(randloc);
		AActor* spawn = GetWorld()->SpawnActor<AActor>(TowersACT, tran);
		while (bool cond = false)
		{
			GetOverlappingActors(towarr, TowersACT);
			if (towarr.IsEmpty() == false)
			{
				x = rand() % 359;
				randloc = randomloc(x, x, 2200, 2200);
				spawn->SetActorLocation(randloc);
			}
			else 
			{
				cond = true;
			}
		}
		
	}

}

void ANaelc::Heavensfall()
{
	FTransform tran;
	FVector vec;
	AActor* pawn = UGameplayStatics::GetActorOfClass(GetWorld(), ACharacter::StaticClass());
	vec = pawn->GetActorLocation();
	vec.SetComponentForAxis(EAxis::Z, 10);
	tran.SetLocation(vec);
	AActor* spawn = GetWorld()->SpawnActor<AActor>(aoe, tran);
	for (int i = 0; i < 7; i++)
	{
		float x = rand() % 359;
		float rad = rand() % 2200;
		FVector randloc = randomloc(x, x, rad, rad);
		tran.SetLocation(randloc);
		spawn = GetWorld()->SpawnActor<AActor>(aoe, tran);
	}
}

void ANaelc::AOE()
{
	FTransform tran;
	FVector vel = { 10000,10000,0 };
	AActor* spawn = GetWorld()->SpawnActor<AActor>(HeavenACT, tran);
	ACharacter* chara = UGameplayStatics::GetPlayerCharacter(GetWorld(),0);
	vel = chara->GetActorLocation();
	vel = vel * 10;
	FMath::Clamp(vel.X, 10000, 10000);
	FMath::Clamp(vel.Y, 10000, 10000);
	vel.SetComponentForAxis(EAxis::Z, 0);
	chara->LaunchCharacter(vel, true, false);
	FTimerHandle handle;
	GetWorld()->GetTimerManager().SetTimer(handle,this,&ANaelc::delay, 1.f, false);
}

void ANaelc::delay()
{
	ACharacter* chara = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	TArray<AActor*> arr;
	chara->GetOverlappingActors(arr, TowersACT);
	if (arr.IsEmpty() == true)
	{
		chara->Destroy();
	}
	else
	{
		UGameplayStatics::OpenLevel(GetWorld(), "Vittoria");
	}
}

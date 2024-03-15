// Fill out your copyright notice in the Description page of Project Settings.

#include "Twintaniac.h"
#include "Kismet/GameplayStatics.h"


void ATwintaniac::twister()
{
	AActor* pawn = UGameplayStatics::GetActorOfClass(GetWorld(), ACharacter::StaticClass());
	FVector loc = pawn->GetActorLocation();
	loc.SetComponentForAxis(EAxis::Z,10);
	this->pos.SetLocation(loc);
	FTimerHandle handle;
	GetWorld()->GetTimerManager().SetTimer(handle,this, &ATwintaniac::spawnTWI, 1.f);
}

void ATwintaniac::dive()
{
	FTransform tran;
	FVector loc = this->GetActorLocation();
	tran.SetLocation(loc);
	loc = { 50,15,1 };
	AActor* spawn = GetWorld()->SpawnActor<AActor>(aoe, tran);
	spawn->SetActorScale3D(loc);
	FRotator rota = this->GetActorRotation();
	spawn->SetActorRotation(rota);
	AActor* pawn = UGameplayStatics::GetActorOfClass(GetWorld(), ACharacter::StaticClass());
	if (spawn->IsOverlappingActor(pawn) && pawn != NULL)
	{
		pawn->Destroy();
	}
	twister();
}

void ATwintaniac::spawnTWI()
{
	AActor* spawn = GetWorld()->SpawnActor<AActor>(twisterACT,this->pos);
}

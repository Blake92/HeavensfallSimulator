// Fill out your copyright notice in the Description page of Project Settings.


#include "BahamutC.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetArrayLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
ABahamutC::ABahamutC()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABahamutC::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABahamutC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABahamutC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABahamutC::dive()
{
	FTransform tran;
	FVector loc = this->GetActorLocation();
	tran.SetLocation(loc);
	loc = { 50,15,1 };
	AActor * spawn = GetWorld()->SpawnActor<AActor>(aoe,tran);
	spawn->SetActorScale3D(loc);
	FRotator rota = this->GetActorRotation();
	spawn->SetActorRotation(rota);
	AActor * pawn = UGameplayStatics::GetActorOfClass(GetWorld(),ACharacter::StaticClass());
	if (spawn->IsOverlappingActor(pawn) && pawn != NULL)
	{
		pawn->Destroy();
	}
	/*FTimerDelegate TimerDelegate;
	TimerDelegate.BindLambda([&]
		{
			spawn->Destroy();
		}
	);
	FTimerHandle handle;
	GetWorld()->GetTimerManager().SetTimer(handle, TimerDelegate, 1, false); */
}

void ABahamutC::heavensfall()
{
	TArray < AActor* > NPCArray; // make an array of NPC characters
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ANPCc::StaticClass(), NPCArray); // get all child characters of class NPC and put them in the NPC array
	randomize(NPCArray);
	// teleports the first enemy in NPCArray at one of the positions at the outer ring in the arena, then teleports the other enemies one by one at the positions directly after
	for (int i = rand() % 8, j = 0, z = i + 3; i < z; i++, j++)
	{
		int i1 = i % 8; // precaution when i > 8, this way i can access the first members of the array directly after the last in a sort of proto loop
		UE_LOG(LogTemp, Warning, TEXT("%d"), i1);
		FVector loc = radomloc(this->Angle[i1], this->Angle[i1]);
		UE_LOG(LogTemp, Warning, TEXT("angolo %d"), Angle[i1]);
		UE_LOG(LogTemp, Warning, TEXT("loc value is: %s"), *loc.ToString());
		FRotator RotToCenter;
		NPCArray[j]->TeleportTo(loc, RotToCenter, false, false);
		RotToCenter = UKismetMathLibrary::FindLookAtRotation(NPCArray[j]->GetActorLocation(), FVector(0, 0, 0)); // Rotate the enemy so it faces the center of the arena
		RotToCenter.SetComponentForAxis(EAxis::X, 0);
		RotToCenter.SetComponentForAxis(EAxis::Y, 0);
		NPCArray[j]->SetActorRotation(RotToCenter);
	}
}

FVector ABahamutC::radomloc(float x, float y)
{
	x = FMath::DegreesToRadians(x);
	y = FMath::DegreesToRadians(y);
	float x1 = cos(x) * 2200;  // find the x coordinate by multiplying the cosine of the angle and the outer ring radius relative to the map origin ( x=0,y=0,z=0)
	float y1 = sin(y) * 2200;  // find the y coordinate by multiplying the sine of the angle and the outer ring radius
	FVector loc(x1, y1, 10); // make a vector with the found x and y points, along with an above ground z coordinate (height) to avoid clipping with floor
	return loc;
}

//Randomizes an array of type TArray (array of actor objects)

void ABahamutC::randomize(TArray < AActor* > a)
{
	for (int i = 0; i < 10; i++)
	{
		int x = rand() % 2;
		int y = rand() % 2;
		if (x != y)
			{
				a.Swap(x, y);
			}
			// randomize NPCarray, a simple element swap of random indices repeated 10 times
		
	}
}


void ABahamutC::randomizeINT(int * a)
{
	int max = 1;
	int n = 0;
	while (a[n] != NULL) { max++; n++; }
	for (int i = 0; i < 10; i++)
	{
		int x = rand() % max;
		int y = rand() % max;
		if (x != y)
			{
				int temp = a[x];
				a[x] = a[y];
				a[y] = temp;
			}

	//randomize an int array with bubble sorting random elements 10 times, obviously it's less useful with large elements
	}
}
#include "carSpawner.h"

AcarSpawner::AcarSpawner(){
	PrimaryActorTick.bCanEverTick = false;
}

float AcarSpawner::RepeatSpawnTime(){
	float spawnDelay = FMath::RandRange(3, 9);
	return spawnDelay;
}

void AcarSpawner::RepeatSpawn(){
	const FVector Location = GetActorLocation();
	const FRotator Rotation = GetActorRotation();
	GetWorld()->SpawnActor<AActor>(ActorToSpawn, Location, Rotation);
	SpawnStart();
}

void AcarSpawner::SpawnStart(){
	FTimerHandle SpawnTimer;
	float newDelayTime = RepeatSpawnTime();
	int timer = newDelayTime;
	GEngine->AddOnScreenDebugMessage(-1, timer, FColor::Yellow, FString::Printf(TEXT("New car will appear in: %i seconds"), timer));
	GEngine->AddOnScreenDebugMessage(-1, timer, FColor::Yellow, FString::Printf(TEXT("The car will appear randomly at intervals of 3 to 9 seconds")));
	GetWorldTimerManager().SetTimer(SpawnTimer, this, &AcarSpawner::RepeatSpawn, newDelayTime, false);
}


void AcarSpawner::BeginPlay(){
	Super::BeginPlay();
	SpawnStart();	
}


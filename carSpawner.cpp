#include "carSpawner.h"

AcarSpawner::AcarSpawner(){
	PrimaryActorTick.bCanEverTick = false;
}

float AcarSpawner::RepeatSpawnTime(){
	float spawnDelay = FMath::RandRange(1, 6);
	UE_LOG(LogTemp, Warning, TEXT("Delay period: %f"), spawnDelay);
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
	GetWorldTimerManager().SetTimer(SpawnTimer, this, &AcarSpawner::RepeatSpawn, newDelayTime, false);
}


void AcarSpawner::BeginPlay(){
	Super::BeginPlay();
	SpawnStart();	
}


#include "carSpawner.h"

AcarSpawner::AcarSpawner(){
	PrimaryActorTick.bCanEverTick = false;
}

float AcarSpawner::RepeatSpawnTime(){
	float spawnDelay = FMath::RandRange(2, 6);
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
	int32 timer = newDelayTime;
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, FString::Printf(TEXT("New car will appear in: %i seconds"), timer));
	GetWorldTimerManager().SetTimer(SpawnTimer, this, &AcarSpawner::RepeatSpawn, newDelayTime, false);
}


void AcarSpawner::BeginPlay(){
	Super::BeginPlay();
	SpawnStart();	
}


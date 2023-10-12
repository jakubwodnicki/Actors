#pragma once

#include "Math/UnrealMathUtility.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "carSpawner.generated.h"


UCLASS()
class SIMTERACTTASKCAR_API AcarSpawner : public AActor{

GENERATED_BODY()

public:
	AcarSpawner();
	virtual void RepeatSpawn();
	virtual void SpawnStart();
	static float RepeatSpawnTime();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAcces = "true"))
	TSubclassOf<AActor> ActorToSpawn;
};
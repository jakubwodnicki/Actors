#pragma once

#include "CoreMinimal.h"
#include "Components/PrimitiveComponent.h"
#include "GameFramework/Pawn.h"
#include "CarInterface.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Math/UnrealMathUtility.h"
#include "CarToSpawn.generated.h"

UCLASS()
class SIMTERACTTASKCAR_API ACarToSpawn : public APawn, public ICarInterface
{
	GENERATED_BODY()

public:
	ACarToSpawn();
	float RandomSpeed();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetSpeedBeforeBraking();
	void SphereTrace();	

protected:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "CarSpeed")
	float Speed;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "CarSpeed")
	float SpeedBeforeBraking;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "CarSpeed")
	int32 SpeedLevel;
};

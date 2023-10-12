#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CarDestroyer.generated.h"

UCLASS()
class SIMTERACTTASKCAR_API ACarDestroyer : public AActor
{
	GENERATED_BODY()
	
public:	
	ACarDestroyer();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* TriggerVolume;

	UFUNCTION()
	void OnBoxBeginOverlap(
		UPrimitiveComponent* OverlappedComp, 
		AActor* OtherActor, 
		UPrimitiveComponent* OtherComp, 
		int32 OtherBodyIndex, 
		bool bFromSweep, 
		const FHitResult& SweepResult
	);
};

#include "CarToSpawn.h"
#include "Components/StaticMeshComponent.h"


ACarToSpawn::ACarToSpawn(){
	PrimaryActorTick.bCanEverTick = true;
}

float ACarToSpawn::RandomSpeed(){
	float ranSpeed = FMath::RandRange(2, 7);
	SpeedLevel = FMath::FloorToInt(ranSpeed); ;
	return ranSpeed;
}

void ACarToSpawn::BeginPlay(){
	
	Super::BeginPlay();
	Speed = RandomSpeed();
	FTimerHandle DelayTime;
	GetWorldTimerManager().SetTimer(DelayTime, this, &ACarToSpawn::SetSpeedBeforeBraking, 0.2f, false);
}

void ACarToSpawn::SetSpeedBeforeBraking(){
	SpeedBeforeBraking = Speed;
}

void ACarToSpawn::SphereTrace() {
	const FVector Start = GetActorLocation() + FVector(0.0f, 50.0f, 0.0f);
	const FVector End = Start + FVector(0.0f, Speed*50.0f, 0.0f);
	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(this);
	FHitResult HitArray;
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypesArray;
	ObjectTypesArray.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_GameTraceChannel1));

	const bool Hit = UKismetSystemLibrary::SphereTraceSingleForObjects(
		this,
		Start,
		End,
		3.0f,
		ObjectTypesArray,
		false,
		ActorsToIgnore,
		EDrawDebugTrace::ForOneFrame,
		HitArray,
		true,
		FLinearColor::Red,
		FLinearColor::Green,
		5.0f
	);

	if (Hit) {
		switch (SpeedLevel) {

		case 2:
			if (Speed > 1)
				Speed -= 0.02;
			break;

		case 3:
			if (Speed > 1)
				Speed -= 0.04;
			break;

		case 4:
			if (Speed > 1)
				Speed -= 0.06;
			break;

		case 5:
			if (Speed > 1)
				Speed -= 0.08;
			break;

		case 6:
			if (Speed > 1)
				Speed -= 0.1;
			break;

		case 7:
			if (Speed > 1)
				Speed -= 0.12;
			break;
		}
}
	else if (!Hit)
		if (Speed < SpeedBeforeBraking)
			Speed += 0.01;
}

void ACarToSpawn::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	SphereTrace();
	FVector Velocity = GetActorLocation();
	Velocity += FVector(0.f, Speed,0.f);
	SetActorLocation(Velocity);
}






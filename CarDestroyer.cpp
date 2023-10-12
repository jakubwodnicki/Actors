#include "CarDestroyer.h"
#include "CarInterface.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetSystemLibrary.h"

ACarDestroyer::ACarDestroyer(){
	PrimaryActorTick.bCanEverTick = true;
	TriggerVolume = CreateDefaultSubobject<UBoxComponent>(FName("TriggerVolume"));
	if (!ensure(TriggerVolume != nullptr)) return;
	RootComponent = TriggerVolume;
	TriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &ACarDestroyer::OnBoxBeginOverlap);
}

void ACarDestroyer::BeginPlay(){
	Super::BeginPlay();	
}

void ACarDestroyer::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult){
	if (UKismetSystemLibrary::DoesImplementInterface(OtherActor, UCarInterface::StaticClass())) {
		OtherActor->K2_DestroyActor();
	}	
}


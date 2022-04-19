
#include "TestActor.h"

ATestActor::ATestActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ATestActor::Damage()
{
	Destroy();
}

void ATestActor::BeginPlay()
{
	Super::BeginPlay();
}

void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
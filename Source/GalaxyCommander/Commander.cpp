
#include "Commander.h"

ACommander::ACommander()
{
	PrimaryActorTick.bCanEverTick = true;

	// Create components.
	Collider = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collider"));
	RootComponent = Collider;

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
}

void ACommander::BeginPlay()
{
	Super::BeginPlay();
}

void ACommander::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACommander::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}


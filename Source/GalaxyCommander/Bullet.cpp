
#include "Bullet.h"

ABullet::ABullet()
{
	PrimaryActorTick.bCanEverTick = true;

	// Default Components.
	m_Collider = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collider"));
	RootComponent = m_Collider;

	m_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	m_Mesh->SetupAttachment(RootComponent);

	// BasicMovement Component.
	m_BasicMovementComponent = CreateDefaultSubobject<UBasicMovementComponent>(TEXT("BasicMovementComponent"));
	m_BasicMovementComponent->RegisterComponent();
}
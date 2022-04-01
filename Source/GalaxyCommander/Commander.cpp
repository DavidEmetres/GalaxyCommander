
#include "Commander.h"

ACommander::ACommander()
{
	PrimaryActorTick.bCanEverTick = true;

	// Default Components.
	m_Collider = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collider"));
	RootComponent = m_Collider;

	m_Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	m_Mesh->SetupAttachment(RootComponent);

	// TPCamera Components.
	m_FollowinSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("FollowingSpringArm"));
	m_FollowinSpringArm->SetupAttachment(RootComponent);

	m_FollowingCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowingCamera"));
	m_FollowingCamera->SetupAttachment(m_FollowinSpringArm);

	m_TPCameraComponent = CreateDefaultSubobject<UTPCameraComponent>(TEXT("TPCameraComponent"));
	m_TPCameraComponent->SetupSpringArm(m_FollowinSpringArm);
	m_TPCameraComponent->SetupCamera(m_FollowingCamera);
	m_TPCameraComponent->RegisterComponent();

	// Weapon Component.
	m_WeaponComponent = CreateDefaultSubobject<UWeaponComponent>(TEXT("WeaponComponent"));
	m_WeaponComponent->RegisterComponent();

	// BasicMovement Component.
	m_BasicMovementComponent = CreateDefaultSubobject<UBasicMovementComponent>(TEXT("BasicMovementComponent"));
	m_BasicMovementComponent->RegisterComponent();
}
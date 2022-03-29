
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

	m_TPCamera = CreateDefaultSubobject<UTPCameraComponent>(TEXT("TPCamera"));
	m_TPCamera->SetupSpringArm(m_FollowinSpringArm);
	m_TPCamera->SetupCamera(m_FollowingCamera);
	m_TPCamera->RegisterComponent();

	// BasicAiming Component.
	m_AimingSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("AimingSpringArm"));
	m_AimingSpringArm->SetupAttachment(RootComponent);

	m_AimingCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("AimingCamera"));
	m_AimingCamera->SetupAttachment(m_AimingSpringArm);

	m_BasicAiming = CreateDefaultSubobject<UBasicAimingComponent>(TEXT("BasicAiming"));
	m_BasicAiming->SetupSpringArm(m_AimingSpringArm);
	m_BasicAiming->SetupCamera(m_AimingCamera);
	m_BasicAiming->RegisterComponent();

	// BasicMovement Component.
	m_BasicMovement = CreateDefaultSubobject<UBasicMovementComponent>(TEXT("BasicMovement"));
	m_BasicMovement->RegisterComponent();
}

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
	m_SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	m_SpringArm->SetupAttachment(RootComponent);

	m_Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	m_Camera->SetupAttachment(m_SpringArm);

	m_TPCamera = CreateDefaultSubobject<UTPCameraComponent>(TEXT("TPCamera"));
	m_TPCamera->SetupSpringArm(m_SpringArm);
	m_TPCamera->SetupCamera(m_Camera);

	m_TPCamera->RegisterComponent();
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


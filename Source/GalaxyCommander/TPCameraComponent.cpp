
#include "TPCameraComponent.h"

UTPCameraComponent::UTPCameraComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTPCameraComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UTPCameraComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Apply accumulated rotation.
	FRotator rotation = m_SpringArm->GetRelativeRotation();
	rotation += m_AccumulatedRotation * m_CameraSpeed * DeltaTime;

	// Clamp pitch.
	rotation.Pitch = FMath::Clamp(rotation.Pitch, m_PitchMinMax.X, m_PitchMinMax.Y);

	m_SpringArm->SetRelativeRotation(rotation);

	// Reset accumulated rotation.
	m_AccumulatedRotation = FRotator::ZeroRotator;
}

void UTPCameraComponent::SetupSpringArm(USpringArmComponent* SpringArm)
{
	m_SpringArm = SpringArm;
}

void UTPCameraComponent::SetupCamera(UCameraComponent* Camera)
{
	m_Camera = Camera;
}

void UTPCameraComponent::AddRotation(FRotator Rotation)
{
	m_AccumulatedRotation += Rotation;
}
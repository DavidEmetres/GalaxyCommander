
#include "BasicMovementComponent.h"

UBasicMovementComponent::UBasicMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UBasicMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AActor* owner = GetOwner();

	// Compute velocity.
	if (m_InputDirection != FVector::ZeroVector)
	{
		// Apply input direction.
		m_InputDirection.Normalize();

		m_NextVelocity += m_InputDirection * GetCurrentSpeed();
		m_NextVelocity = m_NextVelocity.GetClampedToMaxSize2D(GetCurrentMaxVelocity());
	}
	else
	{
		// Apply ground friction.
		m_NextVelocity *= m_GroundFriction;

		SetIsSprinting(false);
	}

	m_Velocity = FMath::Lerp(m_Velocity, m_NextVelocity, m_Acceleration * DeltaTime);

	// Apply velocity.
	FVector location = owner->GetActorLocation();
	location += m_Velocity * DeltaTime;

	owner->SetActorRelativeLocation(location);

	// Face movement direction.
	if (m_FaceMovementDirection)
	{
		if (!m_InputDirection.IsZero())
		{
			m_FacingRotation = m_InputDirection.Rotation();
		}

		FRotator rotation = FMath::Lerp(owner->GetActorRotation(), m_FacingRotation, m_FacingRotationSpeed * DeltaTime);

		owner->SetActorRelativeRotation(rotation);
	}

	// Reset input direction.
	m_InputDirection = FVector::ZeroVector;
}

void UBasicMovementComponent::Move(FVector Direction)
{
	m_InputDirection += Direction;
}

void UBasicMovementComponent::ToggleSprinting()
{
	SetIsSprinting(!m_IsSprinting);
}

void UBasicMovementComponent::SetFaceMovementDirection(bool Facing)
{
	if (Facing && Facing != m_FaceMovementDirection)
	{
		m_FacingRotation = GetOwner()->GetActorRotation();
	}

	m_FaceMovementDirection = Facing;
}

float UBasicMovementComponent::GetCurrentSpeed()
{
	return m_IsSprinting ? m_SprintSpeed : m_RunningSpeed;
}

float UBasicMovementComponent::GetCurrentMaxVelocity()
{
	return m_IsSprinting ? m_MaxSprintingVelocity : m_MaxRunningVelocity;
}

void UBasicMovementComponent::SetIsSprinting(bool IsSprinting)
{
	m_IsSprinting = IsSprinting;

	OnSprintingChanged.Broadcast(m_IsSprinting);
}
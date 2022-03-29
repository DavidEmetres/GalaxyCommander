
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

		m_IsSprinting = false;
	}

	m_Velocity = FMath::Lerp(m_Velocity, m_NextVelocity, m_Acceleration * DeltaTime);

	// Apply velocity.
	FVector location = owner->GetActorLocation();
	location += m_Velocity * DeltaTime;

	owner->SetActorRelativeLocation(location);

	// Face movement direction.
	if (m_FaceMovementDirection)
	{
		if (m_Velocity != FVector::ZeroVector)
		{
			m_FacingRotation = m_Velocity.Rotation();
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

FVector UBasicMovementComponent::GetVelocity()
{
	return m_Velocity;
}

void UBasicMovementComponent::ToggleSprinting()
{
	m_IsSprinting = !m_IsSprinting;
}

float UBasicMovementComponent::GetCurrentSpeed()
{
	return m_IsSprinting ? m_SprintSpeed : m_RunningSpeed;
}

float UBasicMovementComponent::GetCurrentMaxVelocity()
{
	return m_IsSprinting ? m_MaxSprintingVelocity : m_MaxRunningVelocity;
}

#include "BasicMovementComponent.h"

UBasicMovementComponent::UBasicMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UBasicMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Apply accumulated direction.
	AActor* owner = GetOwner();

	FVector location = owner->GetActorLocation();
	location += m_AccumulatedDirection * m_MovementSpeed * DeltaTime;

	owner->SetActorRelativeLocation(location);

	// Face movement direction.
	if (m_FaceMovementDirection)
	{
		if (m_AccumulatedDirection != FVector::ZeroVector)
		{
			m_FacingRotation = m_AccumulatedDirection.Rotation();
		}

		FRotator rotation = FMath::Lerp(owner->GetActorRotation(), m_FacingRotation, m_FacingRotationSpeed * DeltaTime);

		owner->SetActorRelativeRotation(rotation);
	}

	// Reset accumulated direction.
	m_AccumulatedDirection = FVector::ZeroVector;
}

void UBasicMovementComponent::Move(FVector Direction)
{
	m_AccumulatedDirection += Direction;
}
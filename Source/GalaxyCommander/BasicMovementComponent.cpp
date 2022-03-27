
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

	// Reset accumulated direction.
	m_AccumulatedDirection = FVector::ZeroVector;
}

void UBasicMovementComponent::Move(FVector Direction)
{
	m_AccumulatedDirection += Direction;
}
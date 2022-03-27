
#include "CommanderPlayerController.h"

void ACommanderPlayerController::OnPossess(APawn* PawnPossessed)
{
	Super::OnPossess(PawnPossessed);

	// Cast to concrete pawn.
	if (PawnPossessed->IsA(ACommander::StaticClass()))
	{
		m_Commander = Cast<ACommander>(PawnPossessed);
	}
}

void ACommanderPlayerController::OnRHorizontalAxis(float Axis)
{
	if (m_Commander != nullptr)
	{
		m_Commander->m_TPCamera->AddRotation(FRotator(0.0f, Axis, 0.0f));
	}
}

void ACommanderPlayerController::OnRVerticalAxis(float Axis)
{
	if (m_Commander != nullptr)
	{
		m_Commander->m_TPCamera->AddRotation(FRotator(Axis, 0.0f, 0.0f));
	}
}

void ACommanderPlayerController::OnLHorizontalAxis(float Axis)
{
	if (m_Commander != nullptr)
	{
		FVector cameraRight = m_Commander->m_TPCamera->GetRightVector();
		FVector projectedRight = FVector::VectorPlaneProject(cameraRight, FVector::ZAxisVector);
		projectedRight.Normalize();

		m_Commander->m_BasicMovement->Move(projectedRight * Axis);
	}
}

void ACommanderPlayerController::OnLVerticalAxis(float Axis)
{
	if (m_Commander != nullptr)
	{
		FVector cameraForward = m_Commander->m_TPCamera->GetForwardVector();
		FVector projectedForward = FVector::VectorPlaneProject(cameraForward, FVector::ZAxisVector);
		projectedForward.Normalize();

		m_Commander->m_BasicMovement->Move(projectedForward * Axis);
	}
}
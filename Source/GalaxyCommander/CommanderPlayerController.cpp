
#include "CommanderPlayerController.h"

void ACommanderPlayerController::OnPossess(APawn* PawnPossessed)
{
	Super::OnPossess(PawnPossessed);

	// Cast to concrete pawn.
	if (PawnPossessed->IsA(ACommander::StaticClass()))
	{
		m_Commander = Cast<ACommander>(PawnPossessed);

		m_Commander->m_BasicMovement->OnSprintingChanged.AddUObject(this, &ACommanderPlayerController::OnSprintingChangedHandler);
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

void ACommanderPlayerController::OnLJoystickPressed()
{
	if (m_Commander != nullptr)
	{
		m_Commander->m_BasicMovement->ToggleSprinting();
	}
}

void ACommanderPlayerController::OnLTriggerPressed()
{
	if (m_Commander != nullptr)
	{
		m_Commander->m_TPCamera->Deactivate();
		m_Commander->m_BasicAiming->Activate();
	}
}

void ACommanderPlayerController::OnLTriggerReleased()
{
	if (m_Commander != nullptr)
	{
		m_Commander->m_BasicAiming->Deactivate();
		m_Commander->m_TPCamera->Activate();
	}
}

void ACommanderPlayerController::OnSprintingChangedHandler(bool IsSprinting)
{
	if (m_Commander != nullptr)
	{
		// Change FOV on sprinting.
		float fieldOfView = IsSprinting ? m_Commander->m_TPCamera->GetSprintFieldOfView() : m_Commander->m_TPCamera->GetDefaultFieldOfView();
		m_Commander->m_TPCamera->SetFieldOfView(fieldOfView, true);
	}
}
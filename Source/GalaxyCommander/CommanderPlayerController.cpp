
#include "CommanderPlayerController.h"

void ACommanderPlayerController::OnPossess(APawn* PawnPossessed)
{
	Super::OnPossess(PawnPossessed);

	// Cast to concrete pawn.
	if (PawnPossessed->IsA(ACommander::StaticClass()))
	{
		m_Commander = Cast<ACommander>(PawnPossessed);

		m_Commander->m_WeaponComponent->OnAimingChanged.AddUObject(this, &ACommanderPlayerController::OnAimingChangedHandler);
		m_Commander->m_BasicMovementComponent->OnSprintingChanged.AddUObject(this, &ACommanderPlayerController::OnSprintingChangedHandler);

		UGalaxyCommanderGameInstance* gameInstance = Cast<UGalaxyCommanderGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
		Weapon* rifle = gameInstance->GetWeaponRepository()->Build(FName("Rifle"));

		m_Commander->m_WeaponComponent->SetWeapon(rifle);
	}
}

void ACommanderPlayerController::OnRHorizontalAxis(float Axis)
{
	if (m_Commander != nullptr)
	{
		m_Commander->m_TPCameraComponent->AddRotation(FRotator(0.0f, Axis, 0.0f));
	}
}

void ACommanderPlayerController::OnRVerticalAxis(float Axis)
{
	if (m_Commander != nullptr)
	{
		m_Commander->m_TPCameraComponent->AddRotation(FRotator(Axis, 0.0f, 0.0f));
	}
}

void ACommanderPlayerController::OnLHorizontalAxis(float Axis)
{
	if (m_Commander != nullptr)
	{
		FVector cameraRight = m_Commander->m_TPCameraComponent->GetRightVector();
		FVector projectedRight = FVector::VectorPlaneProject(cameraRight, FVector::ZAxisVector);
		projectedRight.Normalize();

		m_Commander->m_BasicMovementComponent->Move(projectedRight * Axis);
	}
}

void ACommanderPlayerController::OnLVerticalAxis(float Axis)
{
	if (m_Commander != nullptr)
	{
		FVector cameraForward = m_Commander->m_TPCameraComponent->GetForwardVector();
		FVector projectedForward = FVector::VectorPlaneProject(cameraForward, FVector::ZAxisVector);
		projectedForward.Normalize();

		m_Commander->m_BasicMovementComponent->Move(projectedForward * Axis);
	}
}

void ACommanderPlayerController::OnLJoystickPressed()
{
	if (m_Commander != nullptr)
	{
		m_Commander->m_BasicMovementComponent->ToggleSprinting();
	}
}

void ACommanderPlayerController::OnLTriggerPressed()
{
	if (m_Commander != nullptr && m_Commander->m_WeaponComponent->GetIsWeaponEquipped())
	{
		m_Commander->m_WeaponComponent->ToggleAiming();
	}
}

void ACommanderPlayerController::OnLTriggerReleased()
{
	if (m_Commander != nullptr && m_Commander->m_WeaponComponent->GetIsAiming())
	{
		m_Commander->m_WeaponComponent->ToggleAiming();
	}
}

void ACommanderPlayerController::OnSprintingChangedHandler(bool IsSprinting)
{
	if (m_Commander != nullptr)
	{
		if (m_Commander->m_WeaponComponent->GetIsAiming())
		{
			// Change FOV on sprinting.
			float fieldOfView = IsSprinting ? m_Commander->m_TPCameraComponent->GetSprintFieldOfView() : m_Commander->m_TPCameraComponent->GetDefaultFieldOfView();
			m_Commander->m_TPCameraComponent->SetFieldOfView(fieldOfView, true);
		}
	}
}

void ACommanderPlayerController::OnAimingChangedHandler(bool IsAiming)
{
	if (m_Commander != nullptr)
	{
		if (IsAiming)
		{
			if (m_Commander->m_BasicMovementComponent->GetIsSprinting())
			{
				m_Commander->m_BasicMovementComponent->ToggleSprinting();
			}

			Weapon* weapon = m_Commander->m_WeaponComponent->GetWeapon();

			m_Commander->m_TPCameraComponent->SetFieldOfView(weapon->GetAimingFieldOfView(), true);
			m_Commander->m_TPCameraComponent->SetCameraLocation(weapon->GetCameraLocation(), true);

			m_Commander->m_BasicMovementComponent->SetFaceMovementDirection(false);
			m_Commander->m_TPCameraComponent->SetFaceCameraDirection(true);
		}
		else
		{
			m_Commander->m_TPCameraComponent->SetFieldOfView(m_Commander->m_TPCameraComponent->GetDefaultFieldOfView(), true);
			m_Commander->m_TPCameraComponent->SetCameraLocation(m_Commander->m_TPCameraComponent->GetDefaultCameraLocation(), true);

			m_Commander->m_TPCameraComponent->SetFaceCameraDirection(false);
			m_Commander->m_BasicMovementComponent->SetFaceMovementDirection(true);
		}
	}
}
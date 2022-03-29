
#include "TPCameraComponent.h"

UTPCameraComponent::UTPCameraComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTPCameraComponent::Activate(bool bReset)
{
	m_Camera->Activate();
}

void UTPCameraComponent::Deactivate()
{
	m_Camera->Deactivate();
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

	// Lerp FOV.
	if (m_Camera->FieldOfView != m_FieldOfView)
	{
		m_Camera->FieldOfView = FMath::Lerp(m_Camera->FieldOfView, m_FieldOfView, DeltaTime);
	}
}

void UTPCameraComponent::SetupSpringArm(USpringArmComponent* SpringArm)
{
	m_SpringArm = SpringArm;

	if (m_SpringArm != nullptr)
	{
		m_SpringArm->bInheritPitch = false;
		m_SpringArm->bInheritYaw = false;
		m_SpringArm->bInheritRoll = false;
	}
}

void UTPCameraComponent::SetupCamera(UCameraComponent* Camera)
{
	m_Camera = Camera;

	if (m_Camera != nullptr)
	{
		m_DefaultFieldOfView = m_Camera->FieldOfView;
		m_FieldOfView = m_DefaultFieldOfView;
	}
}

void UTPCameraComponent::AddRotation(FRotator Rotation)
{
	m_AccumulatedRotation += Rotation;
}

void UTPCameraComponent::SetFieldOfView(float FieldOfView, bool Lerp)
{
	m_FieldOfView = FieldOfView;

	if (!Lerp)
	{
		m_Camera->FieldOfView = m_FieldOfView;
	}
}

#include "TPCameraComponent.h"

UTPCameraComponent::UTPCameraComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTPCameraComponent::BeginPlay()
{
	// Set defaults.
	if (m_SpringArm != nullptr)
	{
		m_SpringArm->bInheritPitch = false;
		m_SpringArm->bInheritYaw = false;
		m_SpringArm->bInheritRoll = false;
	}

	if (m_Camera != nullptr)
	{
		m_DefaultLocation = m_Camera->GetRelativeLocation();
		m_Location = m_DefaultLocation;
		m_DefaultFieldOfView = m_Camera->FieldOfView;
		m_FieldOfView = m_DefaultFieldOfView;
		m_PitchMinMax = m_DefaultPitchMinMax;
	}
}

void UTPCameraComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Lerp location.
	if (m_Camera->GetRelativeLocation() != m_Location)
	{
		FVector newLocation = FMath::Lerp(m_Camera->GetRelativeLocation(), m_Location, DeltaTime);
		m_Camera->SetRelativeLocation(newLocation);
	}

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

	// Face camera direction.
	if (m_FaceCameraDirection)
	{
		AActor* owner = GetOwner();

		FVector cameraForward = GetForwardVector();
		FVector ownerForward = owner->GetActorForwardVector();

		if (cameraForward != ownerForward)
		{
			m_FacingRotation = cameraForward.Rotation();
		}

		FRotator rot = FMath::Lerp(owner->GetActorRotation(), m_FacingRotation, m_FacingRotationSpeed * DeltaTime);

		owner->SetActorRelativeRotation(rot);
	}
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

void UTPCameraComponent::SetCameraLocation(FVector Location, bool Lerp)
{
	m_Location = Location;

	if (!Lerp)
	{
		m_Camera->SetRelativeLocation(Location);
	}
}

void UTPCameraComponent::SetFieldOfView(float FieldOfView, bool Lerp)
{
	m_FieldOfView = FieldOfView;

	if (!Lerp)
	{
		m_Camera->FieldOfView = m_FieldOfView;
	}
}

void UTPCameraComponent::SetFaceCameraDirection(bool Facing)
{
	if (Facing && Facing != m_FaceCameraDirection)
	{
		m_FacingRotation = GetOwner()->GetActorRotation();
	}

	m_FaceCameraDirection = Facing;
}
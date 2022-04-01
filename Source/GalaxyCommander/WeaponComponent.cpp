
#include "WeaponComponent.h"

UWeaponComponent::UWeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UWeaponComponent::ToggleAiming()
{
	m_IsAiming = !m_IsAiming;

	OnAimingChanged.Broadcast(m_IsAiming);
}
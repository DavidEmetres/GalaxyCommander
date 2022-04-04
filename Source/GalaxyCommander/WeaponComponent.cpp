
#include "WeaponComponent.h"

UWeaponComponent::UWeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UWeaponComponent::SetWeapon(Weapon* Weapon)
{
	if (m_Weapon != Weapon)
	{
		m_Weapon = Weapon;

		OnWeaponChanged.Broadcast();
	}
}

void UWeaponComponent::ToggleAiming()
{
	m_IsAiming = !m_IsAiming;

	OnAimingChanged.Broadcast(m_IsAiming);
}

UWeaponFacade* UWeaponComponent::GetWeaponFacade()
{
	UWeaponFacade* weaponFacade = nullptr;

	if (m_Weapon != nullptr)
	{
		weaponFacade = NewObject<UWeaponFacade>();
		weaponFacade->Construct(m_Weapon);
	}

	return weaponFacade;
}
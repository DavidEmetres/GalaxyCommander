
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

		SetMesh(m_Weapon);

		OnWeaponChanged.Broadcast();
	}
}

void UWeaponComponent::ToggleAiming()
{
	m_IsAiming = !m_IsAiming;

	OnAimingChanged.Broadcast(m_IsAiming);
}

void UWeaponComponent::Shoot()
{
	if (m_Weapon != nullptr)
	{
		UClass* bulletClass = m_Weapon->GetBulletClass().Get();

		AActor* owner = GetOwner();

		ABullet* bullet = GetWorld()->SpawnActor<ABullet>(
			bulletClass,
			owner->GetActorLocation(),
			owner->GetActorForwardVector().Rotation());
	}
}

void UWeaponComponent::SetMesh(Weapon* Weapon)
{
	m_Mesh->SetStaticMesh(Weapon->GetWeaponMesh());
	m_Mesh->SetRelativeTransform(Weapon->GetWeaponTransform());
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
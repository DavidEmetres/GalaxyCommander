
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
		// Calculate origin and destination.
		FVector startPoint = m_Mesh->GetSocketLocation(m_Weapon->GetBulletOriginSocket());
		FVector endPoint = m_Camera->GetComponentLocation() + (m_Camera->GetForwardVector() * m_Weapon->GetRangeMeters());

		// Spawn bullet.
		UClass* bulletClass = m_Weapon->GetBulletClass().Get();

		if (bulletClass != nullptr)
		{
			ABullet* bullet = GetWorld()->SpawnActor<ABullet>(bulletClass);
			bullet->SetActorLocation(startPoint);
			bullet->SetActorRotation((endPoint - startPoint).Rotation());

			bullet->SetEndPoint(endPoint);

			FCollisionQueryParams collisionParams = FCollisionQueryParams();
			collisionParams.AddIgnoredActor(GetOwner());
			bullet->Shoot(collisionParams);
		}
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
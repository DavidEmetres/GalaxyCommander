
#include "WeaponFacade.h"

UWeaponFacade::UWeaponFacade()
{
}

void UWeaponFacade::Construct(Weapon* Weapon)
{
	Magazine = Weapon->m_Magazine;
	AmmoPerMagazine = Weapon->m_AmmoPerMagazine;
	AimingFOV = Weapon->m_AimingFOV;
	CameraLocation = Weapon->m_CameraLocation;
	SightUIWidget = Weapon->m_SightUIWidget;
	RecoilForce = Weapon->m_RecoilForce;
	SecondsBetweenShots = Weapon->m_SecondsBetweenShots;
}
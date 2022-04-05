
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
	RecoilForce = Weapon->m_RecoilForce;
	SecondsBetweenShots = Weapon->m_SecondsBetweenShots;
	RangeMeters = Weapon->m_RangeMeters;
	WeaponMesh = Weapon->m_WeaponMesh;
	WeaponTransform = Weapon->m_WeaponTransform;
	Bullet = Weapon->m_Bullet;
	BulletOriginSocket = Weapon->m_BulletOriginSocket;
	SightUIWidget = Weapon->m_SightUIWidget;
}
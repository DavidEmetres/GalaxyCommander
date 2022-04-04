
#include "Weapon.h"

Weapon::Weapon(
	int Magazine, 
	int AmmoPerMagazine, 
	float AimingFOV, 
	FVector CameraLocation, 
	TSoftClassPtr<UUserWidget> SightUIWidget,
	FVector RecoilForce, 
	float SecondsBetweenShots)
{
	m_Magazine = Magazine;
	m_AmmoPerMagazine = AmmoPerMagazine;
	m_AimingFOV = AimingFOV;
	m_CameraLocation = CameraLocation;
	m_SightUIWidget = SightUIWidget;
	m_RecoilForce = RecoilForce;
	m_SecondsBetweenShots = SecondsBetweenShots;
}

Weapon::~Weapon()
{
}

Weapon* Weapon::Clone()
{
	return new Weapon(
		m_Magazine,
		m_AmmoPerMagazine,
		m_AimingFOV,
		m_CameraLocation,
		m_SightUIWidget,
		m_RecoilForce,
		m_SecondsBetweenShots
	);
}
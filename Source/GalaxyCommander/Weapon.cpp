
#include "Weapon.h"

Weapon::Weapon(
	int Magazine, 
	int AmmoPerMagazine, 
	float AimingFOV, 
	FVector CameraLocation, 
	FVector RecoilForce, 
	float SecondsBetweenShots,
	float RangeMeters,
	UStaticMesh* WeaponMesh,
	FTransform WeaponTransform,
	TSoftClassPtr<ABullet> Bullet,
	FName BulletOriginSocket,
	TSoftClassPtr<UUserWidget> SightUIWidget)
{
	m_Magazine = Magazine;
	m_AmmoPerMagazine = AmmoPerMagazine;
	m_AimingFOV = AimingFOV;
	m_CameraLocation = CameraLocation;
	m_RecoilForce = RecoilForce;
	m_SecondsBetweenShots = SecondsBetweenShots;
	m_RangeMeters = RangeMeters;
	m_WeaponMesh = WeaponMesh;
	m_WeaponTransform = WeaponTransform;
	m_Bullet = Bullet;
	m_BulletOriginSocket = BulletOriginSocket;
	m_SightUIWidget = SightUIWidget;
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
		m_RecoilForce,
		m_SecondsBetweenShots,
		m_RangeMeters,
		m_WeaponMesh,
		m_WeaponTransform,
		m_Bullet,
		m_BulletOriginSocket,
		m_SightUIWidget
	);
}
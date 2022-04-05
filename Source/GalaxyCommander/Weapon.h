
#pragma once

#include "Engine/StaticMesh.h"
#include "WeaponStruct.h"
#include "Prototype.h"
#include "Bullet.h"

class GALAXYCOMMANDER_API Weapon : public Prototype<Weapon>
{
public:
	Weapon(
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
		TSoftClassPtr<UUserWidget> SightUIWidget);
	~Weapon();

	int GetMagazine() { return m_Magazine; }
	int GetAmmoPerMagazine() { return m_AmmoPerMagazine; }
	float GetAimingFieldOfView() { return m_AimingFOV; }
	FVector GetCameraLocation() { return m_CameraLocation; }
	FVector GetRecoilForce() { return m_RecoilForce; }
	float GetSecondsBetweenShots() { return m_SecondsBetweenShots; }
	float GetRangeMeters() { return m_RangeMeters; }
	UStaticMesh* GetWeaponMesh() { return m_WeaponMesh; }
	FTransform GetWeaponTransform() { return m_WeaponTransform; }
	TSoftClassPtr<ABullet> GetBulletClass() { return m_Bullet; }
	FName GetBulletOriginSocket() { return m_BulletOriginSocket; }

	virtual Weapon* Clone() override;

	friend class UWeaponFacade;

private:
	int m_Magazine;
	int m_AmmoPerMagazine;
	float m_AimingFOV;
	FVector m_CameraLocation;
	FVector m_RecoilForce;
	float m_SecondsBetweenShots;
	float m_RangeMeters;
	UStaticMesh* m_WeaponMesh;
	FTransform m_WeaponTransform;
	TSoftClassPtr<ABullet> m_Bullet;
	FName m_BulletOriginSocket;
	TSoftClassPtr<UUserWidget> m_SightUIWidget;
};

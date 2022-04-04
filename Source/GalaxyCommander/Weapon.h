
#pragma once

#include "WeaponStruct.h"
#include "Prototype.h"

class GALAXYCOMMANDER_API Weapon : public Prototype<Weapon>
{
public:
	Weapon(
		int Magazine, 
		int AmmoPerMagazine, 
		float AimingFOV, 
		FVector CameraLocation, 
		TSoftClassPtr<UUserWidget> SightUIWidget,
		FVector RecoilForce, 
		float SecondsBetweenShots);
	~Weapon();

	FVector GetCameraLocation() { return m_CameraLocation; }
	float GetAimingFieldOfView() { return m_AimingFOV; }

	virtual Weapon* Clone() override;

	friend class UWeaponFacade;

private:
	int m_Magazine;
	int m_AmmoPerMagazine;
	float m_AimingFOV;
	FVector m_CameraLocation;
	TSoftClassPtr<UUserWidget> m_SightUIWidget;
	FVector m_RecoilForce;
	float m_SecondsBetweenShots;
};

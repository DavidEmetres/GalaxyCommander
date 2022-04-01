
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
		UTexture2D* SightTexture, 
		FVector RecoilForce, 
		float SecondsBetweenShots);
	~Weapon();

	FVector GetCameraLocation() { return m_CameraLocation; }
	float GetAimingFieldOfView() { return m_AimingFOV; }

	virtual Weapon* Clone() override;

private:
	int m_Magazine;
	int m_AmmoPerMagazine;
	float m_AimingFOV;
	FVector m_CameraLocation;
	UTexture2D* m_SightTexture;
	FVector m_RecoilForce;
	float m_SecondsBetweenShots;
};

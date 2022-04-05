
#include "WeaponRepository.h"

WeaponRepository::WeaponRepository(UDataTable* WeaponsDataTable)
{
	FString contextString;
	TArray<FName> rowNames = WeaponsDataTable->GetRowNames();

	for (FName name : rowNames)
	{
		FWeaponStruct* rowData = WeaponsDataTable->FindRow<FWeaponStruct>(name, contextString);
		PrototypeMap.Add(name, BuildPrototype(*rowData));
	}
}

WeaponRepository::~WeaponRepository()
{
}

Prototype<Weapon>* WeaponRepository::BuildPrototype(FWeaponStruct Data)
{
	return new Weapon(
		Data.Magazine,
		Data.AmmoPerMagazine,
		Data.AimingFOV,
		Data.CameraLocation,
		Data.RecoilForce,
		Data.SecondsBetweenShots,
		Data.RangeMeters,
		Data.WeaponMesh,
		Data.WeaponTransform,
		Data.Bullet,
		Data.BulletOriginSocket,
		Data.SightUIWidget
	);
}
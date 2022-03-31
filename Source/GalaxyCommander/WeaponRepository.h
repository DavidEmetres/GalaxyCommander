
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "WeaponStruct.h"
#include "Weapon.h"
#include "Prototype.h"
#include "PrototypeRepository.h"

class GALAXYCOMMANDER_API WeaponRepository : public PrototypeRepository<Weapon, FWeaponStruct>
{
public:
	WeaponRepository(UDataTable* WeaponsDataTable);
	~WeaponRepository();

protected:
	virtual Prototype<Weapon>* BuildPrototype(FWeaponStruct Data) override;
};
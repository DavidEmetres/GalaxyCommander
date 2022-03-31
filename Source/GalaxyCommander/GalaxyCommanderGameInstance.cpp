
#include "GalaxyCommanderGameInstance.h"

void UGalaxyCommanderGameInstance::Init()
{
	m_WeaponRepository = new WeaponRepository(m_WeaponsDataTable);
}
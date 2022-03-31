
#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "WeaponRepository.h"
#include "GalaxyCommanderGameInstance.generated.h"

UCLASS()
class GALAXYCOMMANDER_API UGalaxyCommanderGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	virtual void Init() override;

	WeaponRepository* GetWeaponRepository() { return m_WeaponRepository; }

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UDataTable* m_WeaponsDataTable;

	WeaponRepository* m_WeaponRepository;
};

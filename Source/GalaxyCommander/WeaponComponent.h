
#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "Components/ActorComponent.h"
#include "WeaponComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(AimingChangedSignature, bool);

UCLASS()
class GALAXYCOMMANDER_API UWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UWeaponComponent();

	bool GetIsWeaponEquipped() { return m_Weapon != nullptr; }
	Weapon* GetWeapon() { return m_Weapon; }
	bool GetIsAiming() { return m_IsAiming; }
	FVector2D GetPitchMinMax() { return m_PitchMinMax; }

	void SetWeapon(Weapon* Weapon) { m_Weapon = Weapon; }

	void ToggleAiming();

	AimingChangedSignature OnAimingChanged;

private:
	Weapon* m_Weapon;

	bool m_IsAiming;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	FVector2D m_PitchMinMax;
};
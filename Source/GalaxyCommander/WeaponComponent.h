
#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "Components/ActorComponent.h"
#include "WeaponComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(AimingChangedSignature, bool);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GALAXYCOMMANDER_API UWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UWeaponComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	bool GetIsWeaponEquipped() { return m_Weapon != nullptr; }
	Weapon* GetWeapon() { return m_Weapon; }
	bool GetIsAiming() { return m_IsAiming; }

	void SetWeapon(Weapon* Weapon) { m_Weapon = Weapon; }

	void ToggleAiming();

	AimingChangedSignature OnAimingChanged;

protected:
	virtual void BeginPlay() override;

private:
	Weapon* m_Weapon;

	bool m_IsAiming;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float m_AimingSpeed;
};

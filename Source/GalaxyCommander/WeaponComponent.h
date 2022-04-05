
#pragma once

#include "CoreMinimal.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Weapon.h"
#include "WeaponFacade.h"
#include "Components/ActorComponent.h"
#include "WeaponComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(AimingChangedSignature, bool);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FWeaponChangedSignature);

UCLASS()
class GALAXYCOMMANDER_API UWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UWeaponComponent();

	bool GetIsWeaponEquipped() { return m_Weapon != nullptr; }
	Weapon* GetWeapon() { return m_Weapon; }
	FName GetWeaponParentSocketName() { return m_WeaponParentSocketName; }
	FVector2D GetPitchMinMax() { return m_PitchMinMax; }

	void SetupMesh(UStaticMeshComponent* Mesh) { m_Mesh = Mesh; }
	void SetWeapon(Weapon* Weapon);

	void ToggleAiming();
	void Shoot();

	AimingChangedSignature OnAimingChanged;

	UFUNCTION(BlueprintCallable)
	bool GetIsAiming() { return m_IsAiming; }

private:
	void SetMesh(Weapon* Weapon);

	Weapon* m_Weapon;

	bool m_IsAiming;

	UStaticMeshComponent* m_Mesh;

	UFUNCTION(BlueprintCallable, meta = (AllowPrivateAccess = "true"))
	UWeaponFacade* GetWeaponFacade();

	UPROPERTY(BlueprintAssignable, meta = (AllowPrivateAccess = "true"))
	FWeaponChangedSignature OnWeaponChanged;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	FName m_WeaponParentSocketName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	FVector2D m_PitchMinMax;
};
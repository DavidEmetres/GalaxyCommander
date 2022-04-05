
#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "WeaponFacade.generated.h"

UCLASS()
class GALAXYCOMMANDER_API UWeaponFacade : public UObject
{
	GENERATED_BODY()

public:
	UWeaponFacade();

	void Construct(Weapon* Weapon);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int Magazine;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int AmmoPerMagazine;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float AimingFOV;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FVector CameraLocation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FVector RecoilForce;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float SecondsBetweenShots;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float RangeMeters;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UStaticMesh* WeaponMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FTransform WeaponTransform;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FName WeaponParentSocket;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSoftClassPtr<ABullet> Bullet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FName BulletOriginSocket;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSoftClassPtr<UUserWidget> SightUIWidget;
};

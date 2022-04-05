
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Blueprint/UserWidget.h"
#include "Engine/StaticMesh.h"
#include "Bullet.h"
#include "WeaponStruct.generated.h"

USTRUCT(BlueprintType)
struct GALAXYCOMMANDER_API FWeaponStruct : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

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
	TSoftClassPtr<ABullet> Bullet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FName BulletOriginSocket;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSoftClassPtr<UUserWidget> SightUIWidget;
};

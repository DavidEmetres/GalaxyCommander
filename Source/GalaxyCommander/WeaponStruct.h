
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
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
	UTexture2D* SightTexture;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FVector RecoilForce;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float SecondsBetweenShots;
};

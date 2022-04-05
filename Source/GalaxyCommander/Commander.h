
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "TPCameraComponent.h"
#include "BasicMovementComponent.h"
#include "WeaponComponent.h"
#include "Commander.generated.h"

UCLASS()
class GALAXYCOMMANDER_API ACommander : public APawn
{
	GENERATED_BODY()

public:
	ACommander();

	friend class ACommanderPlayerController;

	UFUNCTION(BlueprintCallable)
	UWeaponComponent* GetWeaponComponent() { return m_WeaponComponent; }

	UFUNCTION(BlueprintCallable)
	UBasicMovementComponent* GetBasicMovementComponent() { return m_BasicMovementComponent; }

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* m_Mesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UCapsuleComponent* m_Collider;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* m_FollowinSpringArm;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* m_FollowingCamera;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UTPCameraComponent* m_TPCameraComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* m_AimingSpringArm;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* m_AimingCamera;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* m_WeaponMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UWeaponComponent* m_WeaponComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UBasicMovementComponent* m_BasicMovementComponent;
};
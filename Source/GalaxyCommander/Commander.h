
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "TPCameraComponent.h"
#include "BasicMovementComponent.h"
#include "BasicAimingComponent.h"
#include "Commander.generated.h"

UCLASS(BlueprintType)
class GALAXYCOMMANDER_API ACommander : public APawn
{
	GENERATED_BODY()

public:
	ACommander();

	friend class ACommanderPlayerController;

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
	UTPCameraComponent* m_TPCamera;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* m_AimingSpringArm;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* m_AimingCamera;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UBasicAimingComponent* m_BasicAiming;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UBasicMovementComponent* m_BasicMovement;
};
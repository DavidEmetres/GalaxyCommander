
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BasicMovementComponent.generated.h"

UCLASS()
class GALAXYCOMMANDER_API UBasicMovementComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:
	UBasicMovementComponent();

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void Move(FVector Direction);

	void ToggleSprinting();

	UFUNCTION(BlueprintCallable)
	FVector GetVelocity();

private:
	float GetCurrentSpeed();
	float GetCurrentMaxVelocity();

	FVector m_Velocity;
	FVector m_NextVelocity;
	FVector m_InputDirection;
	FRotator m_FacingRotation;

	bool m_IsSprinting;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float m_RunningSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float m_SprintSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	bool m_FaceMovementDirection;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float m_FacingRotationSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float m_MaxRunningVelocity;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float m_MaxSprintingVelocity;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float m_Acceleration;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float m_GroundFriction;
};

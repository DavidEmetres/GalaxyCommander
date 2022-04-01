
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Math/UnrealMathUtility.h"
#include "TPCameraComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GALAXYCOMMANDER_API UTPCameraComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UTPCameraComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	FVector GetForwardVector() { return m_Camera->GetForwardVector(); }
	FVector GetRightVector() { return m_Camera->GetRightVector(); }
	FVector GetDefaultCameraLocation() { return m_DefaultLocation; }
	float GetDefaultFieldOfView() { return m_DefaultFieldOfView; }
	float GetSprintFieldOfView() { return m_SprintFieldOfView; }

	void SetCameraLocation(FVector Location, bool Lerp = false);
	void SetFieldOfView(float FieldOfView, bool Lerp = false);
	void SetFaceCameraDirection(bool Facing);

	void SetupSpringArm(USpringArmComponent* SpringArm);
	void SetupCamera(UCameraComponent* Camera);
	void AddRotation(FRotator Rotation);


private:
	USpringArmComponent* m_SpringArm;
	UCameraComponent* m_Camera;

	FRotator m_AccumulatedRotation;

	FVector m_DefaultLocation;
	FVector m_Location;
	float m_DefaultFieldOfView;
	float m_FieldOfView;

	FRotator m_FacingRotation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	bool m_FaceCameraDirection;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float m_FacingRotationSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float m_CameraSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	FVector2D m_PitchMinMax;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float m_SprintFieldOfView;
};
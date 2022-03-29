
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

	virtual void Activate(bool bReset = false) override;
	virtual void Deactivate() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	FVector GetForwardVector() { return m_Camera->GetForwardVector(); }
	FVector GetRightVector() { return m_Camera->GetRightVector(); }
	float GetDefaultFieldOfView() { return m_DefaultFieldOfView; }
	float GetSprintFieldOfView() { return m_SprintFieldOfView; }

	void SetupSpringArm(USpringArmComponent* SpringArm);
	void SetupCamera(UCameraComponent* Camera);
	void AddRotation(FRotator Rotation);
	void SetFieldOfView(float FieldOfView, bool Lerp = false);

private:
	USpringArmComponent* m_SpringArm;
	UCameraComponent* m_Camera;

	FRotator m_AccumulatedRotation;

	float m_DefaultFieldOfView;
	float m_FieldOfView;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float m_CameraSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	FVector2D m_PitchMinMax;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float m_SprintFieldOfView;
};
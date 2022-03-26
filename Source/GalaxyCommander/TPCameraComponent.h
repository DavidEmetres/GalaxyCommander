
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

	void SetupSpringArm(USpringArmComponent* SpringArm);
	void SetupCamera(UCameraComponent* Camera);
	void AddRotation(FRotator Rotation);

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float m_CameraSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	FVector2D m_PitchMinMax;

	USpringArmComponent* m_SpringArm;
	UCameraComponent* m_Camera;

	FRotator m_AccumulatedRotation;
};
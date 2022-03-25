
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
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

protected:
	virtual void BeginPlay() override;

private:
	USpringArmComponent* m_SpringArm;
	UCameraComponent* m_Camera;
};

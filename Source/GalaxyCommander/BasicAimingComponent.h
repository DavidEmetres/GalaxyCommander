
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/ActorComponent.h"
#include "BasicAimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GALAXYCOMMANDER_API UBasicAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UBasicAimingComponent();

	virtual void Activate(bool bReset = false) override;
	virtual void Deactivate() override;

	void SetupSpringArm(USpringArmComponent* SpringArm);
	void SetupCamera(UCameraComponent* Camera);

private:
	USpringArmComponent* m_SpringArm;
	UCameraComponent* m_Camera;
};

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "GalaxyPlayerController.h"
#include "Commander.h"
#include "GalaxyCommanderGameInstance.h"
#include "CommanderPlayerController.generated.h"

UCLASS()
class GALAXYCOMMANDER_API ACommanderPlayerController : public AGalaxyPlayerController
{
	GENERATED_BODY()

protected:
	virtual void OnPossess(APawn* PawnPossessed) override;

	virtual void OnRHorizontalAxis(float Axis) override;
	virtual void OnRVerticalAxis(float Axis) override;
	virtual void OnLHorizontalAxis(float Axis) override;
	virtual void OnLVerticalAxis(float Axis) override;

	virtual void OnLJoystickPressed() override;
	virtual void OnLTriggerPressed() override;
	virtual void OnLTriggerReleased() override;

private:
	void OnSprintingChangedHandler(bool IsSprinting);
	void OnAimingChangedHandler(bool IsAiming);

	ACommander* m_Commander;
};


#pragma once

#include "CoreMinimal.h"
#include "GalaxyPlayerController.h"
#include "Commander.h"
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

private:
	ACommander* m_Commander;
};

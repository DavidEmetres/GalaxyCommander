
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GalaxyPlayerController.generated.h"

UCLASS(abstract)
class GALAXYCOMMANDER_API AGalaxyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

	virtual void OnRHorizontalAxis(float Axis) {};
	virtual void OnRVerticalAxis(float Axis) {};
	virtual void OnLHorizontalAxis(float Axis) {};
	virtual void OnLVerticalAxis(float Axis) {};

	virtual void OnLJoystickPressed() {};
	virtual void OnLTriggerPressed() {};
	virtual void OnLTriggerReleased() {};
	virtual void OnRTriggerPressed() {};
	virtual void OnRTriggerReleased() {};
};

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Commander.h"
#include "GalaxyPlayerController.generated.h"

UCLASS()
class GALAXYCOMMANDER_API AGalaxyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	//virtual bool InputKey(const FInputKeyParams& Params) override;

protected:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* PawnPossessed) override;

private:
	virtual void OnRHorizontalAxis(float Axis);
	virtual void OnRVerticalAxis(float Axis);

	ACommander* m_Commander;
};

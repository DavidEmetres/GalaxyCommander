
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Blueprint/UserWidget.h"
#include "HUDGameplay.generated.h"

UCLASS()
class GALAXYCOMMANDER_API AHUDGameplay : public AHUD
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UUserWidget* m_SightWidget;
};
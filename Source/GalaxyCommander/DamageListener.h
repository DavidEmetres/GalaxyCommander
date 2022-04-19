
#pragma once

#include "CoreMinimal.h"
#include "DamageListener.generated.h"

UINTERFACE(MinimalAPI)
class UDamageListener : public UInterface
{
	GENERATED_BODY()
};

class GALAXYCOMMANDER_API IDamageListener
{
	GENERATED_BODY()

public:
	virtual void Damage() {};
};

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DamageListener.h"
#include "TestActor.generated.h"

UCLASS()
class GALAXYCOMMANDER_API ATestActor : public AActor, public IDamageListener
{
	GENERATED_BODY()
	
public:	
	ATestActor();

	virtual void Damage() override;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
};
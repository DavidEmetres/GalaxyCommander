
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BasicMovementComponent.generated.h"

UCLASS()
class GALAXYCOMMANDER_API UBasicMovementComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:
	UBasicMovementComponent();

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void Move(FVector Direction);

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float m_MovementSpeed;

	FVector m_AccumulatedDirection;
};

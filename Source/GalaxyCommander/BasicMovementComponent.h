
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

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	bool m_FaceMovementDirection;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float m_FacingRotationSpeed;

	FVector m_AccumulatedDirection;
	FRotator m_FacingRotation;
};


#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "BasicMovementComponent.h"
#include "DamageListener.h"
#include "Bullet.generated.h"

UCLASS()
class GALAXYCOMMANDER_API ABullet : public AActor
{
	GENERATED_BODY()
	
public:	
	ABullet();

	void Shoot(FCollisionQueryParams QueryParams = FCollisionQueryParams::FCollisionQueryParams());

	void SetEndPoint(FVector EndPoint) { m_EndPoint = EndPoint; }

	virtual void Tick(float DeltaTime) override;

private:
	FVector m_EndPoint;

	bool m_Fired;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* m_Mesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float m_AnimSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TSoftClassPtr<AActor> m_ImpactFX;
};
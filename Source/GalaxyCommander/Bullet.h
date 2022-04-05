
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "BasicMovementComponent.h"
#include "Bullet.generated.h"

UCLASS()
class GALAXYCOMMANDER_API ABullet : public AActor
{
	GENERATED_BODY()
	
public:	
	ABullet();

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* m_Mesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UCapsuleComponent* m_Collider;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UBasicMovementComponent* m_BasicMovementComponent;
};

#include "Bullet.h"

ABullet::ABullet()
{
	PrimaryActorTick.bCanEverTick = true;

	// Default Components.
	m_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = m_Mesh;
}

void ABullet::Shoot(FCollisionQueryParams QueryParams)
{
	QueryParams.AddIgnoredActor(this);

	// Line trace.
	FHitResult hitResult;
	if (GetWorld()->LineTraceSingleByChannel(
		hitResult,
		GetActorLocation(),
		m_EndPoint,
		ECollisionChannel::ECC_Visibility,
		QueryParams
	))
	{
		m_EndPoint = hitResult.ImpactPoint;

		// Notify actor.
		AActor* actor = hitResult.GetActor();
		IDamageListener* listener = Cast<IDamageListener>(actor);

		if (listener != nullptr)
		{
			listener->Damage();

			UClass* impactFXClass = m_ImpactFX.Get();
			AActor* impactFX = GetWorld()->SpawnActor<AActor>(impactFXClass);
			impactFX->SetActorLocation(actor->GetActorLocation());
		}
	}

	// Spawn impact FX.

	m_Fired = true;
}

void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (m_Fired)
	{
		if (GetActorLocation().Equals(m_EndPoint, 0.1f))
		{
			Destroy();
		}
		else
		{
			FVector newLocation = FMath::Lerp(GetActorLocation(), m_EndPoint, m_AnimSpeed * DeltaTime);
			SetActorLocation(newLocation);
		}
	}
}
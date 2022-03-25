
#include "TPCameraComponent.h"

UTPCameraComponent::UTPCameraComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UTPCameraComponent::BeginPlay()
{
	Super::BeginPlay();
}


void UTPCameraComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UTPCameraComponent::SetupSpringArm(USpringArmComponent* SpringArm)
{
	m_SpringArm = SpringArm;
}

void UTPCameraComponent::SetupCamera(UCameraComponent* Camera)
{
	m_Camera = Camera;
}
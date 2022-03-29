
#include "BasicAimingComponent.h"

UBasicAimingComponent::UBasicAimingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UBasicAimingComponent::Activate(bool bReset)
{
	Super::Activate(bReset);

	m_Camera->Activate();
}

void UBasicAimingComponent::Deactivate()
{
	Super::Deactivate();

	m_Camera->Deactivate();
}

void UBasicAimingComponent::SetupSpringArm(USpringArmComponent* SpringArm)
{
	m_SpringArm = SpringArm;
}

void UBasicAimingComponent::SetupCamera(UCameraComponent* Camera)
{
	m_Camera = Camera;
}
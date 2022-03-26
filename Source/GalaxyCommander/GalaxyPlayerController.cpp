
#include "GalaxyPlayerController.h"

void AGalaxyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// Setup input.
	InputComponent->BindAxis("RHorizontal", this, &AGalaxyPlayerController::OnRHorizontalAxis);
	InputComponent->BindAxis("RVertical", this, &AGalaxyPlayerController::OnRVerticalAxis);
}

void AGalaxyPlayerController::OnPossess(APawn* PawnPossessed)
{
	Super::OnPossess(PawnPossessed);

	// Cast to concrete pawn.
	if (PawnPossessed->IsA(ACommander::StaticClass()))
	{
		m_Commander = Cast<ACommander>(PawnPossessed);
	}
}

void AGalaxyPlayerController::OnRHorizontalAxis(float Axis)
{
	if (m_Commander != nullptr)
	{
		m_Commander->m_TPCamera->AddRotation(FRotator(0.0f, Axis, 0.0f));
	}
}

void AGalaxyPlayerController::OnRVerticalAxis(float Axis)
{
	if (m_Commander != nullptr)
	{
		m_Commander->m_TPCamera->AddRotation(FRotator(Axis, 0.0f, 0.0f));
	}
}
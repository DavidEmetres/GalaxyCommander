
#include "CommanderPlayerController.h"

void ACommanderPlayerController::OnPossess(APawn* PawnPossessed)
{
	Super::OnPossess(PawnPossessed);

	// Cast to concrete pawn.
	if (PawnPossessed->IsA(ACommander::StaticClass()))
	{
		m_Commander = Cast<ACommander>(PawnPossessed);

		UE_LOG(LogTemp, Warning, TEXT("On Commander possessed."));
	}
}

void ACommanderPlayerController::OnRHorizontalAxis(float Axis)
{
	if (m_Commander != nullptr)
	{
		m_Commander->m_TPCamera->AddRotation(FRotator(0.0f, Axis, 0.0f));
	}
}

void ACommanderPlayerController::OnRVerticalAxis(float Axis)
{
	if (m_Commander != nullptr)
	{
		m_Commander->m_TPCamera->AddRotation(FRotator(Axis, 0.0f, 0.0f));
	}
}
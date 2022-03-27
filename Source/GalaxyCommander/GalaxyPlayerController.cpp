
#include "GalaxyPlayerController.h"

void AGalaxyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// Setup input.
	InputComponent->BindAxis("RHorizontal", this, &AGalaxyPlayerController::OnRHorizontalAxis);
	InputComponent->BindAxis("RVertical", this, &AGalaxyPlayerController::OnRVerticalAxis);
	InputComponent->BindAxis("LHorizontal", this, &AGalaxyPlayerController::OnLHorizontalAxis);
	InputComponent->BindAxis("LVertical", this, &AGalaxyPlayerController::OnLVerticalAxis);
}

void AGalaxyPlayerController::OnPossess(APawn* PawnPossessed)
{
	Super::OnPossess(PawnPossessed);
}

#include "GalaxyPlayerController.h"

void AGalaxyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// Setup input.
	InputComponent->BindAxis("RHorizontal", this, &AGalaxyPlayerController::OnRHorizontalAxis);
	InputComponent->BindAxis("RVertical", this, &AGalaxyPlayerController::OnRVerticalAxis);
	InputComponent->BindAxis("LHorizontal", this, &AGalaxyPlayerController::OnLHorizontalAxis);
	InputComponent->BindAxis("LVertical", this, &AGalaxyPlayerController::OnLVerticalAxis);

	InputComponent->BindAction("LJoystickButton", EInputEvent::IE_Pressed, this, &AGalaxyPlayerController::OnLJoystickPressed);
	InputComponent->BindAction("LTrigger", EInputEvent::IE_Pressed, this, &AGalaxyPlayerController::OnLTriggerPressed);
	InputComponent->BindAction("LTrigger", EInputEvent::IE_Released, this, &AGalaxyPlayerController::OnLTriggerReleased);
}
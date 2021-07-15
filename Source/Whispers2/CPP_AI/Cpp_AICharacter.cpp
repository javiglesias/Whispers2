#include "Cpp_AICharacter.h"
#include "Cpp_AIController.h"


void ACpp_AICharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

ACpp_AICharacter::ACpp_AICharacter()
{
	AI_Senses = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("Senses"));
	AI_Senses->SetPeripheralVisionAngle(90.f);
}

void ACpp_AICharacter::BeginPlay()
{
	Super::BeginPlay();
	if(AI_Senses)
	{
		AI_Senses->OnSeePawn.AddDynamic(this, &ACpp_AICharacter::OnPlayerCaught);
	}
}

void ACpp_AICharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ACpp_AICharacter::OnPlayerCaught(APawn* InPawn)
{
	ACpp_AIController* CharacterController = Cast<ACpp_AIController>(GetController());
	if(CharacterController)
	{
		CharacterController->SetPlayerCaught(InPawn);
	}
}

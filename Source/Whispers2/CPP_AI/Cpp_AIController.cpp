﻿#include "Cpp_AIController.h"

#include "Kismet/GameplayStatics.h"

ACpp_AIController::ACpp_AIController()
{
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTree"));
	BlackboardCompoonent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardCOmponent"));
	UGameplayStatics::GetAllActorsOfClassWithTag(GetWorld(),AActor::StaticClass(),FName("PatrolIAPoint"), PatrolPoints);
	
	PlayerKey = "Amelia";
	LocationToGoKey = "LocationToGo";
	CurrentPatrolPoint = 0;
}

void ACpp_AIController::SetPlayerCaught(APawn* InPawn)
{
	if(BlackboardCompoonent)
	{
		BlackboardCompoonent->SetValueAsObject(PlayerKey, InPawn);
	}
}

void ACpp_AIController::ResetPlayerCaught()
{
	if(BlackboardCompoonent)
	{
		BlackboardCompoonent->SetValueAsObject(PlayerKey, nullptr);
	}
}


void ACpp_AIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	ACpp_AICharacter* AI_Character = Cast<ACpp_AICharacter>(InPawn);
	if(AI_Character)
	{
		if(AI_Character->BehaviorTree->BlackboardAsset != nullptr)
		{
			BlackboardCompoonent->InitializeBlackboard(*(AI_Character->BehaviorTree->BlackboardAsset));
		}
		BehaviorTreeComponent->StartTree(*AI_Character->BehaviorTree);
	}
}

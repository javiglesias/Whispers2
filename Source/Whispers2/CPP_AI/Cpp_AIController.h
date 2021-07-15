#pragma once
#include "AIController.h"
#include "Cpp_AICharacter.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Cpp_AIController.generated.h"

UCLASS()
class WHISPERS2_API ACpp_AIController : public AController
{
	GENERATED_BODY()
private:
	UBehaviorTreeComponent* BehaviorTreeComponent;
	UBlackboardComponent* BlackboardCompoonent;

	UPROPERTY(EditDefaultsOnly, Category="BehaviorTree")
		FName LocationToGoKey;
	UPROPERTY(EditDefaultsOnly, Category="BehaviorTree")
		FName PlayerKey;
	UPROPERTY(EditAnywhere, Category="BehaviorTree")
		TArray<AActor*> PatrolPoints;

	virtual void OnPossess(APawn* InPawn) override;

	int32 CurrentPatrolPoint = 0;
public:
	ACpp_AIController();

	void SetPlayerCaught(APawn* InPawn);
	FORCEINLINE UBlackboardComponent* GeBlackBoardComponent(){ return BlackboardCompoonent; }
	FORCEINLINE TArray<AActor*> GetPatrolPoints() {return PatrolPoints;}
};

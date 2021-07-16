#pragma once
#include "CoreMinimal.h"

#include "BehaviorTree/BehaviorTree.h"
#include "GameFramework/Character.h"
#include "Perception/PawnSensingComponent.h"
#include "Cpp_AICharacter.generated.h"

UCLASS()
class WHISPERS2_API ACpp_AICharacter : public ACharacter
{
	GENERATED_BODY()
protected:
	virtual void Tick(float DeltaSeconds) override;
public:
	ACpp_AICharacter();

	UPROPERTY(EditAnywhere, Category="Behavior")
		UBehaviorTree* BehaviorTree;
	UPROPERTY(VisibleAnywhere, Category="Senses")
		UPawnSensingComponent* AI_Senses;
private:
	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	//
	UFUNCTION()
		void OnPlayerCaught(APawn* InPawn);
	UPROPERTY(EditDefaultsOnly, Category="Health")
		int32 Health = 10;
};


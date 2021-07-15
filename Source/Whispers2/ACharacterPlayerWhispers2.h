#pragma once
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"

UCLASS()
class ACharacterPlayerWhispers2 : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY()
	class USpringArmComponent m_camera_arm;

public:
	ACharacterPlayerWhispers2();
protected:
	virtual void BeginPlay() override;
private:
	virtual void Tick(float DeltaSeconds) override;
};

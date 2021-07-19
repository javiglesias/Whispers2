// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "C_CharacterPlayer.generated.h"

UCLASS()
class WHISPERS2_API AC_CharacterPlayer : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	class USpringArmComponent* BoomArm;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	class UCameraComponent* Camera;
	
public:
	// Sets default values for this character's properties
	AC_CharacterPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	void ForwardBackwards(float Value);
	void RighLeft(float Value);

	void TurnRate(float Rate);
	void LookUpRate(float Rate);

	float TurnRatio;
	float LookUpRatio;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
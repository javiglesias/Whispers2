// Fill out your copyright notice in the Description page of Project Settings.


#include "C_CharacterPlayer.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AC_CharacterPlayer::AC_CharacterPlayer()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoomArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Boom"));
	BoomArm->SetupAttachment(RootComponent);
	BoomArm->TargetArmLength = 300.f;
	BoomArm->bUsePawnControlRotation = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(BoomArm, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0,540,0);

	TurnRatio = 45;
	LookUpRatio = 45;
	
}
	
// Called when the game starts or when spawned
void AC_CharacterPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AC_CharacterPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}

// Called to bind functionality to input
void AC_CharacterPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this,&AC_CharacterPlayer::ForwardBackwards );
	PlayerInputComponent->BindAxis("MoveRight", this,&AC_CharacterPlayer::RighLeft);
	PlayerInputComponent->BindAxis("LookUp", this, &AC_CharacterPlayer::LookUpRate);
	PlayerInputComponent->BindAxis("Turn", this,&AC_CharacterPlayer::TurnRate);
	PlayerInputComponent->BindAxis("LookUpRate", this,&APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("TurnRate", this,&APawn::AddControllerYawInput);
	
}

void AC_CharacterPlayer::ForwardBackwards(float Value)
{
	if(Controller != NULL && Value != 0.0 )
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator Yaw(0,Rotation.Yaw,0);
		const FVector direction = FRotationMatrix(Yaw).GetUnitAxis(EAxis::X);
		AddMovementInput(direction,Value);
	}
}

void AC_CharacterPlayer::RighLeft(float Value)
{
	if(Controller != NULL && Value != 0.0 )
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator Yaw(0,Rotation.Yaw,0);
		const FVector direction = FRotationMatrix(Yaw).GetUnitAxis(EAxis::Y);
		AddMovementInput(direction,Value);
	}
}

void AC_CharacterPlayer::TurnRate(float Rate)
{
		AddControllerYawInput(Rate * GetWorld()->GetDeltaSeconds() * TurnRatio);
}

void AC_CharacterPlayer::LookUpRate(float Rate)
{
		AddControllerPitchInput(Rate * GetWorld()->GetDeltaSeconds() * TurnRatio);
}

